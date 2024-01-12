// SPDX-License-Identifier: LGPL-3.0-only

#include "tag_impl.h" //has <stdio.h> "tag.h" "header_tag.h" "frame.h" "field.h" "spec.h" "id3lib_strings.h" "utils.h"
#include "helpers.h"
#include "id3/io_decorators.h" //has "readers.h" "io_helpers.h" "utils.h"
#include "io_strings.h"

using namespace dami;

bool id3::v1::parse (ID3_TagImpl &tag, ID3_Reader &reader)
{
    io::ExitTrigger et (reader);

    ID3_Reader::pos_type end = reader.getCur();

    // posn ourselves at 128 bytes from the current position
    if (end < reader.getBeg() + ID3_V1_LEN) {
        ID3D_NOTICE ("id3::v1::parse: not enough bytes to parse, pos = " << end);
        return false;
    }

    reader.setCur (end - ID3_V1_LEN);
    ID3_Reader::pos_type beg = reader.getCur();

    //file.seekg(-static_cast<long>(ID3_V1_LEN), ios::cur);
    if (end != beg + ID3_V1_LEN) {
        ID3D_WARNING ("id3::v1::parse: failed to reposition " << ID3_V1_LEN <<
                      " bytes");
        return false;
    }

    // read the next 128 bytes in;
    String field = io::readText (reader, ID3_V1_LEN_ID);

    // check to see if it was a tag
    if (field != "TAG") {
        return false;
    }

    et.setExitPos (beg);

    // guess so, let's start checking the v2 tag for frames which are the
    // equivalent of the v1 fields.  When we come across a v1 field that has
    // no current equivalent v2 frame, we create the frame, copy the data
    // from the v1 frame and attach it to the tag

    // (Scott Wheeler) The above comment was nice in theory, but it wasn't
    // first checking (before my hacks) to see if there already was v2 data.

    ID3D_NOTICE ("id3::v1::parse: read bytes: " << reader.getCur() - beg);
    String title = io::readTrailingSpaces (reader, ID3_V1_LEN_TITLE);
    field = id3::v2::getTitle (tag);

    if (title.size() > 0 && (field.size() == 0 || field == "")) {
        id3::v2::setTitle (tag, title);
    }

    ID3D_NOTICE ("id3::v1::parse: title = \"" << title << "\"");

    ID3D_NOTICE ("id3::v1::parse: read bytes: " << reader.getCur() - beg);
    String artist = io::readTrailingSpaces (reader, ID3_V1_LEN_ARTIST);
    field = id3::v2::getArtist (tag);

    if (artist.size() > 0 && (field.size() == 0 || field == "")) {
        id3::v2::setArtist (tag, artist);
    }

    ID3D_NOTICE ("id3::v1::parse: artist = \"" << artist << "\"");

    ID3D_NOTICE ("id3::v1::parse: read bytes: " << reader.getCur() - beg);
    String album = io::readTrailingSpaces (reader, ID3_V1_LEN_ALBUM);
    field = id3::v2::getAlbum (tag);

    if (album.size() > 0 && (field.size() == 0 || field == "")) {
        id3::v2::setAlbum (tag, album);
    }

    ID3D_NOTICE ("id3::v1::parse: album = \"" << title << "\"");

    ID3D_NOTICE ("id3::v1::parse: read bytes: " << reader.getCur() - beg);
    String year = io::readTrailingSpaces (reader, ID3_V1_LEN_YEAR);
    field = id3::v2::getYear (tag);

    if (year.size() > 0 && (field.size() == 0 || field == "")) {
        id3::v2::setYear (tag, year);
    }

    ID3D_NOTICE ("id3::v1::parse: year = \"" << year << "\"");

    ID3D_NOTICE ("id3::v1::parse: read bytes: " << reader.getCur() - beg);
    String comment = io::readTrailingSpaces (reader, ID3_V1_LEN_COMMENT - 2);
    // fixes bug for when tracknumber is 0x20
    BString trackno = io::readBinary (reader, ID3_V1_LEN_COMMENT - 28);

    if (trackno[0] == '\0') {
        if (trackno[1] != '\0') {
            //we've got a tracknumber
            size_t track = trackno[1];
            field = id3::v2::getTrack (tag);

            if (field.size() == 0 || field == "00") {
                id3::v2::setTrack (tag, track, 0);
            }

            ID3D_NOTICE ("id3::v1::parse: track = \"" << track << "\"");
            ID3D_NOTICE ("id3::v1::parse: comment length = \"" << comment.length() << "\"");
        }
    } else {
        // trackno[0] != '\0'
        const int paddingsize = (ID3_V1_LEN_COMMENT - 2) - comment.size();
        const char *padding = "                            ";  //28 spaces

        if (trackno[1] == '\0' || trackno[1] == 0x20 && trackno[0] != 0x20) {
            // if there used to be spaces they are gone now, we need to rebuild them
            comment.append (padding, paddingsize);
            comment.append ( (const char *) trackno.data(), 1);
        } else if (trackno[1] != '\0' && trackno[1] != 0x20 &&  trackno[0] != 0x20) {
            // if there used to be spaces they are gone now, we need to rebuild them
            comment.append (padding, paddingsize);
            comment.append ( (const char *) trackno.data(), 2);
        }
    }

    ID3D_NOTICE ("id3::v1::parse: comment = \"" << comment << "\"");

    if (comment.size() > 0) {
        id3::v2::setComment (tag, comment, STR_V1_COMMENT_DESC, "XXX");
    }

    ID3D_NOTICE ("id3::v1::parse: read bytes: " << reader.getCur() - beg);
    // the GENRE field/frame
    uchar genre = reader.readChar();
    field = id3::v2::getGenre (tag);

    if (genre != 0xFF && (field.size() == 0 || field == "")) {
        id3::v2::setGenre (tag, genre);
    }

    ID3D_NOTICE ("id3::v1::parse: genre = \"" << (int) genre << "\"");

    ID3D_NOTICE ("id3::v1::parse: read bytes: " << reader.getCur() - beg);
    return true;
}


