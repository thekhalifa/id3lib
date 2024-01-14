// SPDX-License-Identifier: LGPL-3.0-only

#include "id3/id3lib_streams.h"
#include "id3/tag.h"
#include "test_utils.h"

int main (int argc, char *argv[])
{
    ID3D_INIT_DOUT();
    ID3D_INIT_WARNING();
    ID3D_INIT_NOTICE();

    ID3_Tag tag;
    ID3_Frame frame;

    tag.Link ("tags/temp-230-picture.tag");
    tag.Strip (ID3TT_ALL);
    tag.Clear();

    frame.SetID (ID3FID_TITLE);
    frame.GetField (ID3FN_TEXT)->Set ("Aquarium");
    tag.AddFrame (frame);

    frame.SetID (ID3FID_CONTENTGROUP);
    frame.GetField (ID3FN_TEXT)->Set ("Short fraction of 'Carnival of the Animals: A Grand Zoological Fantasy'");
    tag.AddFrame (frame);

    frame.SetID (ID3FID_COMPOSER);
    frame.GetField (ID3FN_TEXT)->Set ("Camille Saint-Sa\xebns"); //x to match original binary
    tag.AddFrame (frame);

    frame.SetID (ID3FID_BAND);
    frame.GetField (ID3FN_TEXT)->Set ("Slovakia Radio Symphony Orchestra");
    tag.AddFrame (frame);

    frame.SetID (ID3FID_CONDUCTOR);
    frame.Field (ID3FN_TEXTENC) = ID3TE_ASCII;
    frame.GetField (ID3FN_TEXT)->Set ("Ondrej Len\xe1rd"); //x to match original binary
    tag.AddFrame (frame);

    frame.SetID (ID3FID_COPYRIGHT);
    frame.GetField (ID3FN_TEXT)->Set ("1996 HNH international Ltd.");
    tag.AddFrame (frame);

    frame.SetID (ID3FID_CONTENTTYPE);
    frame.GetField (ID3FN_TEXT)->Set ("(32)");
    tag.AddFrame (frame);

    frame.SetID (ID3FID_INVOLVEDPEOPLE);
    frame.GetField (ID3FN_TEXT)->Add ("Producer");
    frame.GetField (ID3FN_TEXT)->Add ("Martin Sauer");
    frame.GetField (ID3FN_TEXT)->Add ("Piano");
    frame.GetField (ID3FN_TEXT)->Add ("Peter Toperczer");
    tag.AddFrame (frame);

    frame.SetID (ID3FID_PICTURE);
    frame.GetField (ID3FN_MIMETYPE)->Set ("image/jpeg");
    frame.GetField (ID3FN_PICTURETYPE)->Set (11);
    frame.GetField (ID3FN_DESCRIPTION)->Set ("B/W picture of Saint-Sa\xebns"); //x to match
    frame.GetField (ID3FN_DATA)->FromFile ("tags/composer.jpg");
    tag.AddFrame (frame);

    tag.SetPadding (false);
    tag.SetUnsync (true);
    tag.Update (ID3TT_ID3V2);
    //compare both files
    if (test_utils_files_match ("tags/230-picture.tag", "tags/temp-230-picture.tag")) {
        std::cout << "Files match" << std::endl << "tags/230-picture.tag" <<
            std::endl << "tags/temp-230-picture.tag" << std::endl;
        return 0;
    } else {
        std::cout << "No Match!!!" << std::endl << "tags/230-picture.tag" <<
            std::endl << "tags/temp-230-picture.tag" << std::endl;
        return 1;
    }
}
