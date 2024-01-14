// SPDX-License-Identifier: LGPL-3.0-only

#include <id3/id3lib_streams.h>
#include <id3/tag.h>
#include "test_utils.h"

int test_unicode (const char *in, const char *out)
{
    ID3_Tag tag;
    ID3_Frame frame;

    tag.Link (out);
    tag.Strip (ID3TT_ALL);
    tag.Clear();

    frame.SetID (ID3FID_USERTEXT);
    frame.GetField (ID3FN_DESCRIPTION)->Set ("example text frame");
    frame.GetField (ID3FN_TEXT)->Set ("This text and the description should be in Unicode.");
    frame.GetField (ID3FN_TEXTENC)->Set (ID3TE_UNICODE);
    tag.AddFrame (frame);

    tag.SetPadding (false);
    tag.SetUnsync (false);
    tag.Update (ID3TT_ID3V2);

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
    return test_unicode ("tags/230-unicode.tag",
                        "tags/temp-230-unicode.tag");

}
