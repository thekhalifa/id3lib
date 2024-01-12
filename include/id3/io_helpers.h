// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_IO_HELPERS_H_
#define _ID3LIB_IO_HELPERS_H_

#include "id3/id3lib_strings.h"
#include "reader.h"
#include "writer.h"

namespace dami
{
    namespace io
    {
        /**
         **/
        class ID3_CPP_EXPORT ExitTrigger
        {
            ID3_Reader &_reader;
            ID3_Reader::pos_type _pos;
            bool _locked;
        public:
            ExitTrigger (ID3_Reader &rdr)
                : _reader (rdr), _pos (rdr.getCur()), _locked (true)
            { ; }
            ExitTrigger (ID3_Reader &rdr, ID3_Reader::pos_type pos)
                : _reader (rdr), _pos (pos)
            { ; }
            virtual ~ExitTrigger()
            {
                if (_locked) {
                    _reader.setCur (_pos);
                }
            }

            void release()
            {
                _locked = false;
            }
            void update()
            {
                _pos = _reader.getCur();
            }
            void setExitPos (ID3_Reader::pos_type pos)
            {
                _pos = pos;
            }
        };

        ID3_C_EXPORT String      readString (ID3_Reader &);
        ID3_C_EXPORT String      readText (ID3_Reader &, size_t);
        ID3_C_EXPORT String      readUnicodeString (ID3_Reader &);
        ID3_C_EXPORT String      readUnicodeText (ID3_Reader &, size_t);
        ID3_C_EXPORT BString     readAllBinary (ID3_Reader &);
        ID3_C_EXPORT BString     readBinary (ID3_Reader &, size_t);
        ID3_C_EXPORT uint32      readLENumber (ID3_Reader &, size_t);
        ID3_C_EXPORT uint32      readBENumber (ID3_Reader &, size_t);
        ID3_C_EXPORT String      readTrailingSpaces (ID3_Reader &, size_t);
        ID3_C_EXPORT uint32      readUInt28 (ID3_Reader &);

        ID3_C_EXPORT size_t      writeString (ID3_Writer &, String);
        ID3_C_EXPORT size_t      writeText (ID3_Writer &, String);
        ID3_C_EXPORT size_t      writeUnicodeString (ID3_Writer &, String, bool = true);
        ID3_C_EXPORT size_t      writeUnicodeText (ID3_Writer &, String, bool = true);
        ID3_C_EXPORT size_t      writeBENumber (ID3_Writer &, uint32 val, size_t);
        ID3_C_EXPORT size_t      writeTrailingSpaces (ID3_Writer &, String, size_t);
        ID3_C_EXPORT size_t      writeUInt28 (ID3_Writer &, uint32);
    };
};

#endif /* _ID3LIB_IO_HELPERS_H_ */

