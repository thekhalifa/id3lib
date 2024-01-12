// SPDX-License-Identifier: LGPL-3.0-only

#include "readers.h"
#include "id3/utils.h" // has <config.h> "id3/id3lib_streams.h" "id3/globals.h" "id3/id3lib_strings.h"

using namespace dami;

ID3_Reader::size_type
ID3_MemoryReader::readChars (char_type buf[], size_type len)
{
    size_type size = dami::min<size_type> (len, _end - _cur);
    ::memcpy (buf, _cur, size);
    _cur += size;
    return size;
}

