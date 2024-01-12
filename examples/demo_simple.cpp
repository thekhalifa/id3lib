// SPDX-License-Identifier: LGPL-3.0-only

#include <id3.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    char *filename = NULL;
    ID3Tag *tag;

    if (argc != 2) {
        printf ("*** Usage: %s file\n", argv[0]);
        exit (1);
    }

    filename = argv[1];
    printf ("*** Reading %s\n", filename);

    if ( (tag = ID3Tag_New()) != NULL) {
        ID3Frame *frame;

        (void) ID3Tag_Link (tag, filename);

        if ( (frame = ID3Tag_FindFrameWithID (tag, ID3FID_TITLE)) != NULL) {
            ID3Field *field;

            if ( (field = ID3Frame_GetField (frame, ID3FN_TEXT)) != NULL) {
                char title[1024];
                (void) ID3Field_GetASCII (field, title, 1024);
                printf ("Title: %s\n", title);
            } else {
                printf ("Didn't get the field\n");
            }
        } else {
            printf ("Didn't get the frame\n");
        }

        if ( (frame = ID3Tag_FindFrameWithID (tag, ID3FID_LEADARTIST)) != NULL) {
            ID3Field *field;

            if ( (field = ID3Frame_GetField (frame, ID3FN_TEXT)) != NULL) {
                char artist[1024];
                (void) ID3Field_GetASCII (field, artist, 1024);
                printf ("Artist: %s\n", artist);
            } else {
                printf ("Didn't get the field\n");
            }
        } else {
            printf ("Didn't get the frame\n");
        }

        if ( (frame = ID3Tag_FindFrameWithID (tag, ID3FID_ALBUM)) != NULL) {
            ID3Field *field;

            if ( (field = ID3Frame_GetField (frame, ID3FN_TEXT)) != NULL) {
                char album[1024];
                (void) ID3Field_GetASCII (field, album, 1024);
                printf ("Album: %s\n", album);
            } else {
                printf ("Didn't get the field\n");
            }
        } else {
            printf ("Didn't get the frame\n");
        }
    } else {
        printf ("Didn't get the tag\n");
    }

    exit (0);
}
