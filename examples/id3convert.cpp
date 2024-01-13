// SPDX-License-Identifier: LGPL-3.0-only

#include <config.h>
#include <id3/id3lib_streams.h>
#include <id3/tag.h>
#include <string.h>
#include <vector>

#define APP_NAME "id3convert"

using std::cout;
using std::endl;

/* Replaced gengetopt as with demo_info/id3info */
void PrintUsage ()
{
    cout << "Converts between id3v1 and id3v2 tags of an mp3 file." << endl;
    cout << endl;
    cout << "Will render both types of tag by default.  Only the last" << endl
         << "tag type indicated in the option list will be used.  Non-" << endl
         << "rendered will remain unchanged in the original file.  Will" << endl
         << "also parse and convert Lyrics3 v2.0 frames, but will not" << endl
         << "render them." << endl;
    cout << endl;
    cout << "Usage: " << APP_NAME << " [OPTIONS] <FILES>..." << endl;
    cout << "       " << APP_NAME << " [-h | -V]" << endl;
    cout << endl;
    cout << "  -1  --v1tag     Render only the id3v1 tag (default=off)" << endl;
    cout << "  -2  --v2tag     Render only the id3v2 tag (default=off)" << endl;
    cout << "  -s  --strip     Strip the tags instead of rendering (default=off)" << endl;
    cout << "  -p  --padding   Use padding in the tag (default=off)" << endl;
    cout << endl;
    cout << "  -h, --help      Print help and exit" << endl;
    cout << "  -V, --version   Print version and exit" << endl;
    cout << endl;
}

void PrintVersion ()
{
    cout << APP_NAME << " version: " << VERSION << endl;
    cout << "Converts between id3v1 and id3v2 tags of an mp3 file." << endl;
    cout << "Uses " << ID3LIB_FULL_NAME << endl;
    cout << endl;
}


void DisplayTags (ostream &os, luint nTags)
{
    if (! ( (nTags & ID3TT_ID3V1) || (nTags & ID3TT_ID3V2))) {
        os << "no tag";
    }

    if (nTags & ID3TT_ID3V1) {
        os << "v1";
    }

    if ( (nTags & ID3TT_ID3V1) && (nTags & ID3TT_ID3V2)) {
        os << " and ";
    }

    if (nTags & ID3TT_ID3V2) {
        os << "v2";
    }
}

int main (int argc, char *const argv[])
{

    if (argc < 2) {
        PrintUsage();
        exit (1);
    }

    std::vector<std::string> files;
    flags_t ulFlag = ID3TT_ALL;
    bool strip = false, padding = false;

    for (size_t i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            PrintUsage();
            exit (0);
        } else if (arg == "-V" || arg == "--version") {
            PrintVersion();
            exit (0);
        } else if (arg == "-1" || arg == "--v1tag") {
            ulFlag = ID3TT_ID3V1;
        } else if (arg == "-2" || arg == "--v2tag") {
            ulFlag = ID3TT_ID3V2;
        } else if (arg == "-s" || arg == "--strip") {
            strip = true;
        } else if (arg == "-p" || arg == "--padding") {
            padding = true;
        } else if (arg.at (0) == '-') {
            cout << "Error, Invalid option: " << arg << endl << endl;
            PrintUsage();
            exit (1);
        }else {
            files.push_back(arg);
        }
    }

    std::vector<std::string>::iterator i;
    for (i = files.begin(); i != files.end(); i++) {
        std::string filename = *i;
        ID3_Tag myTag;

        if (strip) {
            cout << "Stripping " << filename << ": ";
        } else {
            cout << "Converting " << filename << ": ";
        }

        cout << filename << ": ";

        myTag.Clear();
        myTag.Link (filename.c_str(), ID3TT_ALL);
        myTag.SetPadding (padding);

        cout << "attempting ";
        DisplayTags (cout, ulFlag);
        luint nTags;

        if (strip) {
            nTags = myTag.Strip (ulFlag);
            cout << ", stripped ";
        } else {
            nTags = myTag.Update (ulFlag);
            cout << ", converted ";
        }

        DisplayTags (cout, nTags);
        cout << endl;
    }

    return 0;
}


