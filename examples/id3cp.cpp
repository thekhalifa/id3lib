// SPDX-License-Identifier: LGPL-3.0-only

#include <config.h>
#include <id3/id3lib_streams.h>
#include <id3/tag.h>
#include <string.h>
#include <vector>

#define APP_NAME "id3cp"

using std::cout;
using std::endl;

/* Replaced gengetopt as with demo_info/id3info */
void PrintUsage ()
{
    cout << "Copy one or all tags from SOURCE to DEST." << endl;
    cout << endl;
    cout << "Usage: " << APP_NAME << " [OPTIONS] SOURCE DEST" << endl;
    cout << "       " << APP_NAME << " [-h | -V]" << endl;
    cout << endl;
    cout << "  -1  --v1tag     Render only the id3v1 tag (default=off)" << endl;
    cout << "  -2  --v2tag     Render only the id3v2 tag (default=off)" << endl;
    cout << endl;
    cout << "  -h, --help      Print help and exit" << endl;
    cout << "  -V, --version   Print version and exit" << endl;
    cout << endl;
}

void PrintVersion ()
{
    cout << APP_NAME << " version: " << VERSION << endl;
    cout << "Copy tags from one file to another." << endl;
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
    int ulFlag = ID3TT_ID3;

    std::vector<std::string> files;

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
        } else if (arg.at (0) == '-') {
            cout << "Error, Invalid option: " << arg << endl << endl;
            PrintUsage();
            exit (1);
        } else {
            files.push_back (arg);
        }
    }

    if (files.size() != 2) {
        cout << "Error, Invalid number of SOURCE or DESTINATION: " << endl << endl;
        PrintUsage();
        exit (1);
    }

    const char *source = files[0].c_str(), *dest = files[1].c_str();

    ID3_Tag myTag;
    cout << "Parsing " << source << ": ";

    myTag.Clear();
    myTag.Link (source, ID3TT_ALL);

    cout << "done.  Copying to " << dest << ": ";

    myTag.Link (dest, ID3TT_NONE);
    myTag.Update (ulFlag);

    cout << "done" << endl;

    return 0;
}
