// SPDX-License-Identifier: LGPL-3.0-only

#include <config.h>

#include <id3/id3lib_streams.h>
#include <id3/misc_support.h>
#include <id3/tag.h>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define APP_NAME "id3tag"

using std::cout;
using std::endl;
using std::string;

/* Replaced gengetopt as with demo_info/id3info */
void PrintUsage ()
{
    cout << "Will render both types of tag by default.  Only the last" << endl;
    cout << "tag type indicated in the option list will be used.  Non-" << endl;
    cout << "rendered will remain unchanged in the original file.  Will" << endl;
    cout << "also parse and convert Lyrics3 v2.0 frames, but will not" << endl;
    cout << "render them." << endl;
    cout << endl;
    cout << "Usage: " << APP_NAME << " [OPTIONS]... <FILE>..." << endl;
    cout << "       " << APP_NAME << " [-h | -V]" << endl;
    cout << endl;
    cout << "  -aSTRING   --artist=STRING   Set the artist information" << endl;
    cout << "  -ASTRING   --album=STRING    Set the album title information" << endl;
    cout << "  -sSTRING   --song=STRING     Set the title information" << endl;
    cout << "  -cSTRING   --comment=STRING  Set the comment information" << endl;
    cout << "  -CSTRING   --desc=STRING     Set the comment description" << endl;
    cout << "  -ySTRING   --year=STRING     Set the year" << endl;
    cout << "  -tSTRING   --track=STRING    Set the track number" << endl;
    cout << "  -TSTRING   --total=STRING    Set the total number of tracks" << endl;
    cout << "  -gSHORT    --genre=SHORT     Set the genre" << endl;
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
    cout << "Tags mp3 files with ID3v1/1.1 and/or id3v2 tags." << endl;
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
    // int ulFlag = ID3TT_ID3;

    if (argc < 2) {
        PrintUsage();
        exit (1);
    }

    int ulFlag = ID3TT_ID3;

    std::map<string, string> argmap;
    argmap["a"] = "ARTIST";
    argmap["artist"] = "ARTIST";
    argmap["A"] = "ALBUM";
    argmap["album"] = "ALBUM";
    argmap["s"] = "SONG";
    argmap["song"] = "SONG";
    argmap["c"] = "COMMENT";
    argmap["comment"] = "COMMENT";
    argmap["C"] = "DESCRIPTION";
    argmap["desc"] = "DESCRIPTION";
    argmap["y"] = "YEAR";
    argmap["year"] = "YEAR";
    argmap["t"] = "TRACK";
    argmap["track"] = "TRACK";
    argmap["T"] = "TOTAL";
    argmap["total"] = "TOTAL";
    argmap["g"] = "GENRE";
    argmap["genre"] = "GENRE";


    std::vector<string> files;
    std::map<string, string> tagmap;
    string key, value, tagkey;
    string::size_type sep;

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
            // process long options first --artist=X
        } else if (arg[0] == '-' && arg[1] == '-') {
            sep = arg.find ("=");

            if (sep < 3)
                continue;

            key = arg.substr (2, sep - 2);
            value = arg.substr (sep + 1);
            tagkey = argmap[key];

            if (tagkey == key) {
                cout << "Invalid key: " << key << endl;
                continue;
            }

            tagmap[tagkey] = value;
            // process short options -aARTIST_NAME
        } else if (arg[0] == '-') {
            key = arg[1];
            value = arg.substr (2);
            tagkey = argmap[key];

            if (tagkey == key) {
                cout << "Invalid key: " << key << endl;
                continue;
            }

            tagmap[tagkey] = value;
        } else {
            files.push_back (arg);
        }
    }

    std::map<string, string>::iterator mapit;
    std::vector<std::string>::iterator i;

    for (i = files.begin(); i != files.end(); i++) {
        std::string filename = *i;
        ID3_Tag myTag;

        cout << "Tagging " << filename << ": ";

        myTag.Link (filename.c_str());

        cout << "attempting ";
        DisplayTags (cout, ulFlag);

        mapit = tagmap.find ("ARTIST");

        if (mapit != tagmap.end()) {
            ID3_AddArtist (&myTag, (*mapit).second.c_str(), true);
            cout << "+++ Artist  = " << (*mapit).second << endl;
        }

        mapit = tagmap.find ("ALBUM");

        if (mapit != tagmap.end()) {
            ID3_AddAlbum (&myTag, (*mapit).second.c_str(), true);
            cout << "+++ Album  = " << (*mapit).second << endl;
        }

        mapit = tagmap.find ("SONG");

        if (mapit != tagmap.end()) {
            ID3_AddTitle (&myTag, (*mapit).second.c_str(), true);
            cout << "+++ Song  = " << (*mapit).second << endl;
        }

        mapit = tagmap.find ("YEAR");

        if (mapit != tagmap.end()) {
            ID3_AddYear (&myTag, (*mapit).second.c_str(), true);
            cout << "+++ Year  = " << (*mapit).second << endl;
        }

        mapit = tagmap.find ("COMMENT");

        if (mapit != tagmap.end()) {
            value = (*mapit).second;
            string desc;
            mapit = tagmap.find ("DESCRIPTION");

            if (mapit != tagmap.end())
                desc = (*mapit).second;

            ID3_AddComment (&myTag, value.c_str(), desc.c_str(), true);
            cout << "+++ Comment = " << value << endl;

            if (desc.length()) {
                cout << "+++ Comment Description" << endl;
                cout << "            = " << desc << endl;
            }
        }

        mapit = tagmap.find ("GENRE");

        if (mapit != tagmap.end()) {
            unsigned short genre = ::strtol ( (*mapit).second.c_str(), NULL, 10);
            ID3_AddGenre (&myTag, genre, true);
            cout << "+++ Genre  = " << genre << endl;
        }

        mapit = tagmap.find ("TRACK");

        if (mapit != tagmap.end()) {
            unsigned short track = ::strtol ( (*mapit).second.c_str(), NULL, 10);
            string totalstr;
            mapit = tagmap.find ("TOTAL");

            if (mapit != tagmap.end())
                totalstr = (*mapit).second;

            unsigned short total = ::strtol (totalstr.c_str(), NULL, 10);
            ID3_AddTrack (&myTag, track, total, true);
            cout << "+++ Track = " << track << endl;
        }

        luint nTags = myTag.Update (ulFlag);
        cout << ", tagged ";

        DisplayTags (cout, nTags);

        cout << endl;
    }

    return 0;
}
