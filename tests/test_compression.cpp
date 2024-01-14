// SPDX-License-Identifier: LGPL-3.0-only

#include <id3/id3lib_streams.h>
#include <id3/tag.h>
#include "test_utils.h"

int test_compressed(const char *in, const char *out, ID3_TagType type)
{

    ID3_Tag tag;
    ID3_Frame frame;

    tag.Link (out);
    tag.Strip (ID3TT_ALL);
    tag.Clear();

    frame.SetID (ID3FID_USERTEXT);
    frame.GetField (ID3FN_DESCRIPTION)->Set ("compression example");
    frame.GetField (ID3FN_TEXT)->Set ("This sample user text frame came from "
        "an ID3v2-3.0 tag.  The frame has the 'compression' bit set in it's "
        "frame header.  This is the new method for compressing frames, which "
        "supercedes the 2.01 Compressed Data Metaframe.");
    frame.SetCompression (true);
    tag.AddFrame (frame);
    tag.SetPadding (false);
    tag.SetUnsync (false);
    tag.Update (type);

    //compare both files
    if (test_utils_files_match (in, out)) {
        std::cout << "Files match" << std::endl << in << std::endl << out << std::endl;
        return 0;
    } else {
        std::cout << "No Match!!!" << std::endl << in << std::endl << out << std::endl;
        return 1;
    }
}

int main (int argc, char *argv[])
{
    if(test_compressed( "tags/test-221-compressed.tag",
                        "tags/temp-221-compressed-out.tag", ID3TT_ID3V1))
        return 1;
    if(test_compressed( "tags/test-230-compressed.tag",
                        "tags/temp-230-compressed-out.tag", ID3TT_ID3V2))
        return 1;

    return 0;
}
