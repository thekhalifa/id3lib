// SPDX-License-Identifier: LGPL-3.0-only

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include "id3/tag.h"
#include "id3/id3lib_streams.h"
#include "demo_copy_options.h"
#include <string.h>


using std::cout;
using std::endl;
using std::cerr;

static const char *VERSION_NUMBER = "$Revision: 1.11 $";

void PrintUsage (const char *sName)
{
    cout << "Usage: " << sName << " [OPTION]... SOURCE DEST" << endl;
    cout << "Copy the tag(s) from SOURCE to DEST." << endl;
    cout << endl;
}

void PrintVersion (const char *sName)
{
    size_t nIndex;
    cout << sName << " ";

    for (nIndex = 0; nIndex < strlen (VERSION_NUMBER); nIndex++) {
        if (VERSION_NUMBER[nIndex] == ' ') {
            break;
        }
    }

    nIndex++;

    for (; nIndex < strlen (VERSION_NUMBER); nIndex++) {
        if (VERSION_NUMBER[nIndex] == ' ') {
            break;
        }

        cout << VERSION_NUMBER[nIndex];
    }

    cout << endl;
    cout << "Uses " << ID3LIB_FULL_NAME << endl << endl;

    cout << "This program copies tags from one file to another" << endl;
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
    ID3D_INIT_DOUT();
    gengetopt_args_info args;

    if (cmdline_parser (argc, argv, &args) != 0) {
        exit (1);
    }

#if defined ID3_ENABLE_DEBUG

    if (args.warning_flag) {
        ID3D_INIT_WARNING();
        ID3D_WARNING ("warnings turned on");
    }

    if (args.notice_flag) {
        ID3D_INIT_NOTICE();
        ID3D_NOTICE ("notices turned on");
    }

#endif

    if (args.v1tag_flag) {
        ulFlag = ID3TT_ID3V1;
    }

    if (args.v2tag_flag) {
        ulFlag = ID3TT_ID3V2;
    }


    if (args.inputs_num != 2) {
        cerr << "Usage: id3cp [OPTIONS] SOURCE DEST" << endl;
        exit (1);
    }

    const char *source = args.inputs[0], *dest = args.inputs[1];

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

