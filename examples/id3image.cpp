// SPDX-License-Identifier: LGPL-3.0-only

#include "id3/id3lib_streams.h"
#include <stdlib.h>
#include <id3/tag.h>
#include <id3/misc_support.h>
#include <vector>

#define APP_NAME "id3image"

/* Re-written to extract image data through misc_support and
 * write the mimetype and size written to stdout
 */

using std::cout;
using std::endl;

void PrintUsage ()
{
    cout << "Extract image data from mp3 or tag file to separate file" << endl;
    cout << "Usage: " << APP_NAME << " SOURCE DEST" << endl;
    cout << "       " << APP_NAME << " [-h | -V]" << endl;
    cout << "  -o, --overwrite Overwrite output file if it exists" << endl;
    cout << endl;
    cout << "  -h, --help      Print help and exit" << endl;
    cout << "  -V, --version   Print version and exit" << endl;
    cout << endl;
}

void PrintVersion ()
{
    cout << APP_NAME << " version: " << VERSION << endl;
    cout << "Extract image data from mp3 or tag file to separate file" << endl;
    cout << "Uses " << ID3LIB_FULL_NAME << endl;
    cout << endl;
}

int main (int argc, char *argv[])
{

    bool override = false;
    std::vector<std::string> files;

    for (size_t i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            PrintUsage();
            exit (0);
        } else if (arg == "-V" || arg == "--version") {
            PrintVersion();
            exit (0);
        } else if (arg == "-o" || arg == "--override") {
            override = true;
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

    std::string infile = files[0];
    std::string outfile = files[1];

    ifstream instream(infile.c_str());
    if (!instream.good()) {
        cout << "Error, input file does not exist." << endl;
        exit(1);
    }

    ifstream outstream(outfile.c_str());
    if (outstream.good() && !override) {
        cout << "Output file exists, stopping as no overwrite argument passed: " 
            << outfile << endl;
        exit(1);
    } else if (outstream.good() && override) {
        cout << "Output file exists, will overwrite " << outfile << endl;
    }

    ID3_Tag tag (infile.c_str());
    if (!ID3_HasPicture(&tag)) {
        cout << "Input file does not have an image data." << endl;
        exit(1);
    }

    std::string mime = ID3_GetPictureMimeType (&tag);
    if (mime.size())
        cout << "Found MIME Type: " << mime << endl;
    else
        cout << "Unknown MIME Type" << endl;

    size_t ret = ID3_GetPictureData(&tag, outfile.c_str());
    cout << "Wrote " << ret << " bytes to '" << outfile << "'" << endl;

    return 0;
}

