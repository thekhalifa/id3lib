// SPDX-License-Identifier: LGPL-3.0-only

#include <id3.h>
#include <stdio.h>
#include <string.h>

#define APP_NAME "example_cwrapper"

void print_usage ()
{
    printf ("C wrapper example\n\n");
    printf ("Usage: %s <FILE>\n", APP_NAME);
    printf ("\nUses %s\n", ID3LIB_FULL_NAME);
}

size_t get_frame_field_ascii (const ID3Tag *tag, ID3_FrameID frame_id,
                              char *buffer, size_t buffsize)
{

    ID3Frame *frame;

    if (! (frame = ID3Tag_FindFrameWithID (tag, frame_id))) {
        return 0;
    }

    ID3Field *field;

    if (! (field = ID3Frame_GetField (frame, ID3FN_TEXT))) {
        return 0;
    }

    size_t ret = ID3Field_GetASCII (field, buffer, buffsize);

    if (!ret)
        buffer[0] = '\0';

    return ret;
}


size_t get_frame_user_text (const ID3Tag *tag, ID3_FrameID frame_id,
                            char *label, size_t labelsize, char *value, size_t valsize)
{

    ID3Frame *frame;

    if (! (frame = ID3Tag_FindFrameWithID (tag, frame_id))) {
        return 0;
    }

    ID3Field *field;
    size_t labelret = 0, valueret = 0;

    if ( (field = ID3Frame_GetField (frame, ID3FN_DESCRIPTION))) {
        labelret = ID3Field_GetASCII (field, label, labelsize);

        if (!labelret)
            label[0] = '\0';
    }

    if ( (field = ID3Frame_GetField (frame, ID3FN_TEXT))) {
        valueret = ID3Field_GetASCII (field, value, valsize);

        if (!valueret)
            value[0] = '\0';
    }

    return labelret + valueret;
}

int main (int argc, char *argv[])
{

    if (argc != 2) {
        print_usage();
        exit (1);
    }

    char *filename = argv[1];
    printf ("*** Reading %s\n", filename);


    ID3Tag *tag;

    if (! (tag = ID3Tag_New())) {
        printf ("Error, could not create a new tag object\n");
        exit (1);
    }


    size_t ret;
    unsigned short genre;
    char buffer[1024], valbuffer[1024];
    memset (buffer, 0, sizeof (buffer));

    ID3Tag_Link (tag, filename);

    /* extract text fields */
    ret = get_frame_field_ascii (tag, ID3FID_TITLE, buffer, sizeof (buffer));

    if (ret)
        printf ("Title: %s\n", buffer);

    ret = get_frame_field_ascii (tag, ID3FID_LEADARTIST, buffer, sizeof (buffer));

    if (ret)
        printf ("Artist: %s\n", buffer);

    ret = get_frame_field_ascii (tag, ID3FID_ALBUM, buffer, sizeof (buffer));

    if (ret)
        printf ("Album: %s\n", buffer);

    ret = get_frame_field_ascii (tag, ID3FID_COMPOSER, buffer, sizeof (buffer));

    if (ret)
        printf ("Composer: %s\n", buffer);

    ret = get_frame_field_ascii (tag, ID3FID_YEAR, buffer, sizeof (buffer));

    if (ret)
        printf ("Year: %s\n", buffer);

    /* extract genre, expecting "(NUMBER)" or stored as TEXT */
    ret = get_frame_field_ascii (tag, ID3FID_CONTENTTYPE, buffer, sizeof (buffer));

    if (ret) {
        int num = sscanf (buffer, "(%hi)", &genre);

        if (num)
            printf ("Genre: %s - %s\n", buffer, ID3_V1GENRE2DESCRIPTION (genre));
        else
            printf ("Genre: %s\n", buffer);
    }


    /* extract 2 frames of user text TXXX
     * this will loop over them and start at the beginning again
     */
    ret = get_frame_user_text (tag, ID3FID_USERTEXT, buffer, sizeof (buffer),
                               valbuffer, sizeof (valbuffer));

    if (ret)
        printf ("User Text: %s = %s\n", buffer, valbuffer);

    ret = get_frame_user_text (tag, ID3FID_USERTEXT, buffer, sizeof (buffer),
                               valbuffer, sizeof (valbuffer));

    if (ret)
        printf ("User Text: %s = %s\n", buffer, valbuffer);

    exit (0);
}
