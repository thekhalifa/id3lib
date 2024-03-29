// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_HELPERS_H_
#define _ID3LIB_HELPERS_H_

#include "id3/id3lib_strings.h"
#include "id3/globals.h" //has <stdlib.h> "id3/sized_types.h"

class ID3_TagImpl;
class ID3_Frame;

namespace dami
{
    namespace id3
    {
        namespace v2
        {
            ID3_C_EXPORT String     getString (const ID3_Frame *, ID3_FieldID);
            ID3_C_EXPORT String     getStringAtIndex (const ID3_Frame *, ID3_FieldID, size_t);

            ID3_C_EXPORT String     getFrameText (const ID3_TagImpl &, ID3_FrameID);
            ID3_C_EXPORT ID3_Frame *setFrameText (ID3_TagImpl &, ID3_FrameID, String);
            ID3_C_EXPORT size_t     removeFrames (ID3_TagImpl &, ID3_FrameID);

            ID3_C_EXPORT ID3_Frame *hasArtist (const ID3_TagImpl &);
            ID3_C_EXPORT String     getArtist (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setArtist (ID3_TagImpl &, String);
            ID3_C_EXPORT size_t     removeArtists (ID3_TagImpl &);

            ID3_C_EXPORT ID3_Frame *hasAlbum (const ID3_TagImpl &);
            ID3_C_EXPORT String     getAlbum (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setAlbum (ID3_TagImpl &, String);
            ID3_C_EXPORT size_t     removeAlbums (ID3_TagImpl &);

            ID3_C_EXPORT ID3_Frame *hasTitle (const ID3_TagImpl &);
            ID3_C_EXPORT String     getTitle (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setTitle (ID3_TagImpl &, String);
            ID3_C_EXPORT size_t     removeTitles (ID3_TagImpl &);

            ID3_C_EXPORT ID3_Frame *hasYear (const ID3_TagImpl &);
            ID3_C_EXPORT String     getYear (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setYear (ID3_TagImpl &, String);
            ID3_C_EXPORT size_t     removeYears (ID3_TagImpl &);

            ID3_C_EXPORT ID3_Frame *hasV1Comment (const ID3_TagImpl &);
            //      ID3_C_EXPORT ID3_Frame* hasComment(const ID3_TagImpl&, String desc);
            ID3_C_EXPORT ID3_Frame *hasComment (const ID3_TagImpl &);
            ID3_C_EXPORT String     getComment (const ID3_TagImpl &, String desc);
            ID3_C_EXPORT String     getV1Comment (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setComment (ID3_TagImpl &, String, String, String);
            ID3_C_EXPORT size_t     removeComments (ID3_TagImpl &, String);
            ID3_C_EXPORT size_t     removeAllComments (ID3_TagImpl &);

            ID3_C_EXPORT ID3_Frame *hasTrack (const ID3_TagImpl &);
            ID3_C_EXPORT String     getTrack (const ID3_TagImpl &);
            ID3_C_EXPORT size_t     getTrackNum (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setTrack (ID3_TagImpl &, uchar ucTrack, uchar ucTotal);
            ID3_C_EXPORT size_t     removeTracks (ID3_TagImpl &);

            ID3_C_EXPORT ID3_Frame *hasGenre (const ID3_TagImpl &);
            ID3_C_EXPORT String     getGenre (const ID3_TagImpl &);
            ID3_C_EXPORT size_t     getGenreNum (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setGenre (ID3_TagImpl &, size_t ucGenre);
            ID3_C_EXPORT size_t     removeGenres (ID3_TagImpl &);

            ID3_C_EXPORT ID3_Frame *hasLyrics (const ID3_TagImpl &);
            ID3_C_EXPORT String     getLyrics (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setLyrics (ID3_TagImpl &, String, String, String);
            ID3_C_EXPORT size_t     removeLyrics (ID3_TagImpl &);

            ID3_C_EXPORT String     getLyricist (const ID3_TagImpl &);
            ID3_C_EXPORT ID3_Frame *setLyricist (ID3_TagImpl &, String);
            ID3_C_EXPORT size_t     removeLyricists (ID3_TagImpl &);

            ID3_C_EXPORT ID3_Frame *hasSyncLyrics (const ID3_TagImpl &, String lang, String desc);
            ID3_C_EXPORT ID3_Frame *setSyncLyrics (ID3_TagImpl &, BString, ID3_TimeStampFormat,
                                                   String, String, ID3_ContentType);
            ID3_C_EXPORT BString    getSyncLyrics (const ID3_TagImpl &tag, String lang, String desc);
        };
    };
};

#endif /* _ID3LIB_HELPERS_H_ */

