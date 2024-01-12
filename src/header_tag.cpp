// SPDX-License-Identifier: LGPL-3.0-only

#include "header_tag.h"
#include "id3/utils.h" // has <config.h> "id3/id3lib_streams.h" "id3/globals.h" "id3/id3lib_strings.h"
#include "tag.h"
#include "io_helpers.h"
#include "spec.h"

using namespace dami;

const char *const ID3_TagHeader::ID = "ID3";

bool ID3_TagHeader::SetSpec (ID3_V2Spec spec)
{
    bool changed = this->ID3_Header::SetSpec (spec);

    if (changed) {
        if (_info) {
            _flags.set (HEADER_FLAG_EXPERIMENTAL, _info->is_experimental);
            _flags.set (HEADER_FLAG_EXTENDED,     _info->is_extended);
        }
    }

    return changed;
}

size_t ID3_TagHeader::Size() const
{
    size_t bytesUsed = ID3_TagHeader::SIZE;

    if (_info && _info->is_extended) {
        bytesUsed += _info->extended_bytes;
    }

    return bytesUsed;
}


void ID3_TagHeader::Render (ID3_Writer &writer) const
{
    writer.writeChars ( (uchar *) ID, strlen (ID));

    writer.writeChar (ID3_V2SpecToVer (ID3V2_LATEST));
    writer.writeChar (ID3_V2SpecToRev (ID3V2_LATEST));

    // set the flags byte in the header
    writer.writeChar (static_cast<uchar> (_flags.get() & MASK8));
    io::writeUInt28 (writer, this->GetDataSize()); //now includes the extended header

    // now we render the extended header
    if (_flags.test (HEADER_FLAG_EXTENDED)) {
        if (this->GetSpec() == ID3V2_4_0) {
            io::writeUInt28 (writer, 6); //write 4 bytes of v2.4.0 ext header containing size '6'
            io::writeBENumber (writer, 1, 1); //write that it has only one flag byte (value '1')
            io::writeBENumber (writer, 0, 1); //write flag byte with value '0'
        } else if (this->GetSpec() == ID3V2_3_0) {
            io::writeBENumber (writer, 6, sizeof (uint32));

            for (size_t i = 0; i < 6; ++i) {
                if (writer.writeChar ('\0') == ID3_Writer::END_OF_WRITER) {
                    break;
                }
            }
        }

        //  else //not implemented
    }
}

bool ID3_TagHeader::Parse (ID3_Reader &reader)
{
    io::ExitTrigger et (reader);

    if (!ID3_Tag::IsV2Tag (reader)) {
        ID3D_NOTICE ("ID3_TagHeader::Parse(): not an id3v2 header");
        return false;
    }

    uchar id[3];
    reader.readChars (id, 3);
    // The spec version is determined with the MAJOR and MINOR OFFSETs
    uchar major = reader.readChar();
    uchar minor = reader.readChar();
    this->SetSpec (ID3_VerRevToV2Spec (major, minor));

    // Get the flags at the appropriate offset
    _flags.set (static_cast<ID3_Flags::TYPE> (reader.readChar()));

    // set the data size
    this->SetDataSize (io::readUInt28 (reader));

    if (_flags.test (HEADER_FLAG_EXTENDED) && this->GetSpec() == ID3V2_2_1) {
        //couldn't find anything about this in the draft specifying 2.2.1 -> http://www.id3.org/pipermail/id3v2/2000-April/000126.html
        _flags.set (HEADER_FLAG_EXTENDED, false);
        _info->extended_bytes = 0;
        // rest is checked at ParseExtended()
    }

    et.setExitPos (reader.getCur());
    return true;
}

void ID3_TagHeader::ParseExtended (ID3_Reader &reader)
{
    if (this->GetSpec() == ID3V2_3_0) {
        /*
            Extended header size   $xx xx xx xx
            Extended Flags         $xx xx
            Size of padding        $xx xx xx xx
        */
        // skip over header size, we are not using it anyway, we calculate it
        reader.setCur (reader.getCur() + 4); //Extended header size
        //io::readBENumber(reader, 4); //Extended header size
        uint16 tmpval = io::readBENumber (reader, 2); //Extended Flags
        // skip over padding size, we are not using it anyway
        reader.setCur (reader.getCur() + 4); //Size of padding

        // io::readBENumber(reader, 4); //Size of padding
        if (tmpval != 0) { //there is only one flag defined in ID3V2_3_0: crc
            //skip over crc data, we are not using it anyway
            reader.setCur (reader.getCur() + 4); //Crc
            //io::readBENumber(reader, 4); //Crc
            _info->extended_bytes = 14;
        } else {
            _info->extended_bytes = 10;
        }
    }

    if (this->GetSpec() == ID3V2_4_0) {
        /*
            Extended header size   4 * %0xxxxxxx
            Number of flag bytes       $01
            Extended Flags             $xx
        */
        uint16 i;
        uint16 extrabytes;

        io::readUInt28 (reader);
        const int extflagbytes = reader.readChar(); //Number of flag bytes
        ID3_Flags *extflags[1]; // ID3V2_4_0 has 1 flag byte, extflagbytes should be equal to 1

        for (i = 0; i < extflagbytes; ++i) {
            extflags[i] = new ID3_Flags;
            extflags[i]->set (reader.readChar()); //flags
        }

        extrabytes = 0;

        //extflags[0]->test(EXT_HEADER_FLAG_BIT1); // ID3V2_4_0 ext header flag bit 1 *should* be 0
        if (extflags[0]->test (EXT_HEADER_FLAG_BIT2)) {
            // ID3V2_4_0 ext header flag bit 2 = Tag is an update
            // read size
            extrabytes += 1; // add a byte for the char containing the extflagdatasize
            const int extheaderflagdatasize = reader.readChar();
            extrabytes += extheaderflagdatasize;
            // Set the cursor right; we are not parsing the data, no-one is using extended flags anyway
            reader.setCur (reader.getCur() + extheaderflagdatasize);
            //reader.readChars(buf, extheaderflagdatasize); //buf should be at least 127 bytes = max extended header flagdata size
        }

        if (extflags[0]->test (EXT_HEADER_FLAG_BIT3)) {
            // ID3V2_4_0 ext header flag bit 3 = CRC data present
            // read size
            extrabytes += 1; // add a byte for the char containing the extflagdatasize
            const int extheaderflagdatasize = reader.readChar();
            extrabytes += extheaderflagdatasize;
            // Set the cursor right; we are not parsing the data, no-one is using extended flags anyway
            reader.setCur (reader.getCur() + extheaderflagdatasize);
            //reader.readChars(buf, extheaderflagdatasize); //buf should be at least 127 bytes = max extended header flagdata size
        }

        if (extflags[0]->test (EXT_HEADER_FLAG_BIT4)) {
            // ID3V2_4_0 ext header flag bit 4 = Tag restrictions
            // read size
            extrabytes += 1; // add a byte for the char containing the extflagdatasize
            const int extheaderflagdatasize = reader.readChar();
            extrabytes += extheaderflagdatasize;
            // Set the cursor right; we are not parsing the data, no-one is using extended flags anyway
            reader.setCur (reader.getCur() + extheaderflagdatasize);
            //reader.readChars(buf, extheaderflagdatasize); //buf should be at least 127 bytes = max extended header flagdata size
        }

        _info->extended_bytes = 5 + extflagbytes + extrabytes;
    }

    // a bit unorthodox, but since we are not using any of the extended header, but were merely
    // parsing it to get the cursor right, we delete it. Be Gone !
    _flags.set (HEADER_FLAG_EXTENDED, false);

    if (_info) {
        _data_size -= _info->extended_bytes;
        _info->extended_bytes = 0;
    }//else there is a tag with a higher or lower version than supported
}

