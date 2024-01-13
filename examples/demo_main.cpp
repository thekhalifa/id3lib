// SPDX-License-Identifier: LGPL-3.0-only

#include "id3/id3lib_streams.h"
#include "id3/tag.h"

#define APP_NAME "example_writetag"

using std::cout;
using std::endl;

void PrintUsage ()
{
    cout << "Write tag example" << endl;
    cout << "Usage: " << APP_NAME << " <NEW_FILE>" << endl;
    cout << endl;
}

void SetFrameText (ID3_Frame &frame, ID3_FrameID frame_id, std::string text)
{
    frame.SetID (frame_id);
    frame.Field (ID3FN_TEXTENC) = ID3TE_ASCII;
    frame.Field (ID3FN_TEXT) = text.c_str();
}

void SetFrameTextEnc (ID3_Frame &frame, ID3_FrameID frame_id, ID3_TextEnc enc,
                      std::string text, std::string description)
{
    frame.SetID (frame_id);
    frame.Field (ID3FN_TEXTENC) = enc;
    frame.Field (ID3FN_TEXT) = text.c_str();

    if (description.size())
        frame.Field (ID3FN_DESCRIPTION) = description.c_str();
}

void WriteTag (std::string filename)
{
    ID3_Tag   myTag (filename.c_str());
    ID3_Frame myFrame[6];

    SetFrameText (myFrame[0], ID3FID_LEADARTIST, "Great Artist");
    SetFrameText (myFrame[1], ID3FID_ALBUM, "Great Album");
    SetFrameText (myFrame[2], ID3FID_TITLE, "Great Song");

    SetFrameTextEnc (myFrame[3], ID3FID_USERTEXT, ID3TE_UNICODE,
                     "Unicode Example", "Latin \u00c7, \u00cb, \u1e00, \u1e34 as example");

    SetFrameTextEnc (myFrame[4], ID3FID_USERTEXT, ID3TE_ASCII,
                     "ASCII Example", "This is the text for example #2");

    myFrame[5].SetID (ID3FID_INVOLVEDPEOPLE);
    myFrame[5].Field (ID3FN_TEXTENC)     = ID3TE_ASCII;
    myFrame[5].Field (ID3FN_TEXT).Add ("Artist 1");
    myFrame[5].Field (ID3FN_TEXT).Add ("Artist 2");

    myTag.AddFrames (myFrame, 6);

    myTag.SetUnsync (false);
    myTag.SetExtendedHeader (false);
    myTag.SetCompression (false);
    myTag.SetPadding (false);

    myTag.Strip();
    myTag.Update();

    cout << "Wrote to file " << filename << endl;

    return;
}

int main (int argc, char *argv[])
{

    if (argc != 2) {
        PrintUsage();
        exit (1);
    }

    ifstream infile(argv[1]);
    if (infile.good())
        cout << "File exists, appending" << endl;

    WriteTag (argv[1]);

    return 0;
}
