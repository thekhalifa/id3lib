// SPDX-License-Identifier: LGPL-3.0-only

#include <config.h>
#include <id3/io_helpers.h>
#include <id3/misc_support.h>
#include <id3/readers.h>
#include <id3/tag.h>
#include <id3/utils.h>

#define APP_NAME "id3info"

using namespace dami;
using std::cout;
using std::endl;

/*
 * Replace the gengetopt generated code with basic arg parsing. Even though
 * getopt() is now part of libc, the file was attached here probably for other
 * architectures. In order to support Windows, focus on the main purpose of
 * this utility and parse filenams directly with couple of basic options.
 * One downside is that it's too basic to combine multiple short options in one
 */
void PrintUsage ()
{
    cout << "Display the id3 (both v1 and v2) tag information for one or more files." << endl;
    cout << "Usage: " << APP_NAME << " <FILES>..." << endl;
    cout << "       " << APP_NAME << " [-h | -V]" << endl;
    cout << endl;
    cout << "  -h, --help      Print help and exit" << endl;
    cout << "  -V, --version   Print version and exit" << endl;
    cout << endl;
}

void PrintVersion ()
{
    cout << APP_NAME << " version: " << VERSION << endl;
    cout << "Displays ID3 Tag Information - Written by Scott Thomas Haug" << endl;
    cout << "Uses " << ID3LIB_FULL_NAME << endl;
    cout << endl;
}

void PrintInformation (const ID3_Tag &myTag)
{
    ID3_Tag::ConstIterator *iter = myTag.CreateIterator();
    const ID3_Frame *frame = NULL;

    while (NULL != (frame = iter->GetNext())) {
        const char *desc = frame->GetDescription();

        if (!desc) {
            desc = "";
        }

        cout << "=== " << frame->GetTextID() << " (" << desc << "): ";
        ID3_FrameID eFrameID = frame->GetID();

        switch (eFrameID) {
        case ID3FID_ALBUM:
        case ID3FID_BPM:
        case ID3FID_COMPOSER:
        case ID3FID_CONTENTTYPE:
        case ID3FID_COPYRIGHT:
        case ID3FID_DATE:
        case ID3FID_PLAYLISTDELAY:
        case ID3FID_ENCODEDBY:
        case ID3FID_LYRICIST:
        case ID3FID_FILETYPE:
        case ID3FID_TIME:
        case ID3FID_CONTENTGROUP:
        case ID3FID_TITLE:
        case ID3FID_SUBTITLE:
        case ID3FID_INITIALKEY:
        case ID3FID_LANGUAGE:
        case ID3FID_SONGLEN:
        case ID3FID_MEDIATYPE:
        case ID3FID_ORIGALBUM:
        case ID3FID_ORIGFILENAME:
        case ID3FID_ORIGLYRICIST:
        case ID3FID_ORIGARTIST:
        case ID3FID_ORIGYEAR:
        case ID3FID_FILEOWNER:
        case ID3FID_LEADARTIST:
        case ID3FID_BAND:
        case ID3FID_CONDUCTOR:
        case ID3FID_MIXARTIST:
        case ID3FID_PARTINSET:
        case ID3FID_PUBLISHER:
        case ID3FID_TRACKNUM:
        case ID3FID_RECORDINGDATES:
        case ID3FID_NETRADIOSTATION:
        case ID3FID_NETRADIOOWNER:
        case ID3FID_SIZE:
        case ID3FID_ISRC:
        case ID3FID_ENCODERSETTINGS:
        case ID3FID_YEAR: {
            char *sText = ID3_GetString (frame, ID3FN_TEXT);
            cout << sText << endl;
            delete [] sText;
            break;
        }

        case ID3FID_USERTEXT: {
            char
            *sText = ID3_GetString (frame, ID3FN_TEXT),
             *sDesc = ID3_GetString (frame, ID3FN_DESCRIPTION);
            cout << "(" << sDesc << "): " << sText << endl;
            delete [] sText;
            delete [] sDesc;
            break;
        }

        case ID3FID_COMMENT:
        case ID3FID_UNSYNCEDLYRICS: {
            char
            *sText = ID3_GetString (frame, ID3FN_TEXT),
             *sDesc = ID3_GetString (frame, ID3FN_DESCRIPTION),
              *sLang = ID3_GetString (frame, ID3FN_LANGUAGE);
            cout << "(" << sDesc << ")[" << sLang << "]: "
                 << sText << endl;
            delete [] sText;
            delete [] sDesc;
            delete [] sLang;
            break;
        }

        case ID3FID_WWWAUDIOFILE:
        case ID3FID_WWWARTIST:
        case ID3FID_WWWAUDIOSOURCE:
        case ID3FID_WWWCOMMERCIALINFO:
        case ID3FID_WWWCOPYRIGHT:
        case ID3FID_WWWPUBLISHER:
        case ID3FID_WWWPAYMENT:
        case ID3FID_WWWRADIOPAGE: {
            char *sURL = ID3_GetString (frame, ID3FN_URL);
            cout << sURL << endl;
            delete [] sURL;
            break;
        }

        case ID3FID_WWWUSER: {
            char
            *sURL = ID3_GetString (frame, ID3FN_URL),
             *sDesc = ID3_GetString (frame, ID3FN_DESCRIPTION);
            cout << "(" << sDesc << "): " << sURL << endl;
            delete [] sURL;
            delete [] sDesc;
            break;
        }

        case ID3FID_INVOLVEDPEOPLE: {
            size_t nItems = frame->GetField (ID3FN_TEXT)->GetNumTextItems();

            for (size_t nIndex = 0; nIndex < nItems; nIndex++) {
                char *sPeople = ID3_GetString (frame, ID3FN_TEXT, nIndex);
                cout << sPeople;
                delete [] sPeople;

                if (nIndex + 1 < nItems) {
                    cout << ", ";
                }
            }

            cout << endl;
            break;
        }

        case ID3FID_PICTURE: {
            char
            *sMimeType = ID3_GetString (frame, ID3FN_MIMETYPE),
             *sDesc     = ID3_GetString (frame, ID3FN_DESCRIPTION),
              *sFormat   = ID3_GetString (frame, ID3FN_IMAGEFORMAT);
            size_t
            nPicType   = frame->GetField (ID3FN_PICTURETYPE)->Get(),
            nDataSize  = frame->GetField (ID3FN_DATA)->Size();
            cout << "(" << sDesc << ")[" << sFormat << ", "
                 << nPicType << "]: " << sMimeType << ", " << nDataSize
                 << " bytes" << endl;
            delete [] sMimeType;
            delete [] sDesc;
            delete [] sFormat;
            break;
        }

        case ID3FID_GENERALOBJECT: {
            char
            *sMimeType = ID3_GetString (frame, ID3FN_MIMETYPE),
             *sDesc = ID3_GetString (frame, ID3FN_DESCRIPTION),
              *sFileName = ID3_GetString (frame, ID3FN_FILENAME);
            size_t
            nDataSize = frame->GetField (ID3FN_DATA)->Size();
            cout << "(" << sDesc << ")["
                 << sFileName << "]: " << sMimeType << ", " << nDataSize
                 << " bytes" << endl;
            delete [] sMimeType;
            delete [] sDesc;
            delete [] sFileName;
            break;
        }

        case ID3FID_UNIQUEFILEID: {
            char *sOwner = ID3_GetString (frame, ID3FN_OWNER);
            size_t nDataSize = frame->GetField (ID3FN_DATA)->Size();
            cout << sOwner << ", " << nDataSize
                 << " bytes" << endl;
            delete [] sOwner;
            break;
        }

        case ID3FID_PLAYCOUNTER: {
            size_t nCounter = frame->GetField (ID3FN_COUNTER)->Get();
            cout << nCounter << endl;
            break;
        }

        case ID3FID_POPULARIMETER: {
            char *sEmail = ID3_GetString (frame, ID3FN_EMAIL);
            size_t
            nCounter = frame->GetField (ID3FN_COUNTER)->Get(),
            nRating = frame->GetField (ID3FN_RATING)->Get();
            cout << sEmail << ", counter="
                 << nCounter << " rating=" << nRating << endl;
            delete [] sEmail;
            break;
        }

        case ID3FID_CRYPTOREG:
        case ID3FID_GROUPINGREG: {
            char *sOwner = ID3_GetString (frame, ID3FN_OWNER);
            size_t
            nSymbol = frame->GetField (ID3FN_ID)->Get(),
            nDataSize = frame->GetField (ID3FN_DATA)->Size();
            cout << "(" << nSymbol << "): " << sOwner
                 << ", " << nDataSize << " bytes" << endl;
            break;
        }

        case ID3FID_SYNCEDLYRICS: {
            char
            *sDesc = ID3_GetString (frame, ID3FN_DESCRIPTION),
             *sLang = ID3_GetString (frame, ID3FN_LANGUAGE);
            size_t
            nTimestamp = frame->GetField (ID3FN_TIMESTAMPFORMAT)->Get(),
            nRating = frame->GetField (ID3FN_CONTENTTYPE)->Get();
            const char *format = (2 == nTimestamp) ? "ms" : "frames";
            cout << "(" << sDesc << ")[" << sLang << "]: ";

            switch (nRating) {
            case ID3CT_OTHER:
                cout << "Other";
                break;

            case ID3CT_LYRICS:
                cout << "Lyrics";
                break;

            case ID3CT_TEXTTRANSCRIPTION:
                cout << "Text transcription";
                break;

            case ID3CT_MOVEMENT:
                cout << "Movement/part name";
                break;

            case ID3CT_EVENTS:
                cout << "Events";
                break;

            case ID3CT_CHORD:
                cout << "Chord";
                break;

            case ID3CT_TRIVIA:
                cout << "Trivia/'pop up' information";
                break;
            }

            cout << endl;
            ID3_Field *fld = frame->GetField (ID3FN_DATA);

            if (fld) {
                ID3_MemoryReader mr (fld->GetRawBinary(), fld->BinSize());

                while (!mr.atEnd()) {
                    cout << io::readString (mr).c_str();
                    cout << " [" << io::readBENumber (mr, sizeof (uint32)) << " "
                         << format << "] ";
                }
            }

            cout << endl;
            delete [] sDesc;
            delete [] sLang;
            break;
        }

        case ID3FID_AUDIOCRYPTO:
        case ID3FID_EQUALIZATION:
        case ID3FID_EVENTTIMING:
        case ID3FID_CDID:
        case ID3FID_MPEGLOOKUP:
        case ID3FID_OWNERSHIP:
        case ID3FID_PRIVATE:
        case ID3FID_POSITIONSYNC:
        case ID3FID_BUFFERSIZE:
        case ID3FID_VOLUMEADJ:
        case ID3FID_REVERB:
        case ID3FID_SYNCEDTEMPO:
        case ID3FID_METACRYPTO: {
            cout << " (unimplemented)" << endl;
            break;
        }

        default: {
            cout << " frame" << endl;
            break;
        }
        }
    }

    delete iter;
}

int main (int argc, char *const argv[])
{
    ID3D_INIT_DOUT();
    ID3D_INIT_WARNING();
    ID3D_INIT_NOTICE();

    if (argc < 2) {
        PrintUsage();
        exit (1);
    }

    std::string arg1 = argv[1];

    if (arg1 == "-h" || arg1 == "--help") {
        PrintUsage();
        exit (0);
    } else if (arg1 == "-V" || arg1 == "--version") {
        PrintVersion();
        exit (0);
    } else if (arg1.at (0) == '-') {
        cout << "Error, Invalid option: " << arg1 << endl << endl;
        PrintUsage();
        exit (1);
    }

    std::string filename;

    for (size_t i = 1; i < argc; i++) {
        filename = argv[i];

        ID3_Tag myTag;
        myTag.Link (filename.c_str(), ID3TT_ALL);
        const Mp3_Headerinfo *mp3info;
        mp3info = myTag.GetMp3HeaderInfo();

        cout << endl << "*** Tag information for " << filename << endl;
        PrintInformation (myTag);

        if (mp3info) {
            cout << "*** mp3 info\n";

            switch (mp3info->version) {
            case MPEGVERSION_2_5:
                cout << "MPEG2.5/";
                break;

            case MPEGVERSION_2:
                cout << "MPEG2/";
                break;

            case MPEGVERSION_1:
                cout << "MPEG1/";
                break;

            default:
                break;
            }

            switch (mp3info->layer) {
            case MPEGLAYER_III:
                cout << "layer III\n";
                break;

            case MPEGLAYER_II:
                cout << "layer II\n";
                break;

            case MPEGLAYER_I:
                cout << "layer I\n";
                break;

            default:
                break;
            }

            cout << "Bitrate: " << mp3info->bitrate / 1000 << "KBps\n";
            cout << "Frequency: " << mp3info->frequency / 1000 << "KHz\n";
        }


    }

    return 0;
}
