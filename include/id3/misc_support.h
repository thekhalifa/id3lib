// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_MISC_SUPPORT_H_
#define _ID3LIB_MISC_SUPPORT_H_

#include <id3/tag.h>

ID3_C_EXPORT char      *ID3_GetString (const ID3_Frame *, ID3_FieldID);
ID3_C_EXPORT char      *ID3_GetString (const ID3_Frame *, ID3_FieldID, size_t nItems);

ID3_C_EXPORT void ID3_FreeString (char *str);

// defined in 'id3_misc_support.cpp'
// these are 'convenience functions,' to make using the library easier for the
// most common of operations
ID3_C_EXPORT char      *ID3_GetArtist (const ID3_Tag *);
ID3_C_EXPORT ID3_Frame *ID3_AddArtist (ID3_Tag *, const char *, bool replace = false);
ID3_C_EXPORT size_t     ID3_RemoveArtists (ID3_Tag *);

ID3_C_EXPORT char      *ID3_GetAlbum (const ID3_Tag *);
ID3_C_EXPORT ID3_Frame *ID3_AddAlbum (ID3_Tag *, const char *, bool replace = false);
ID3_C_EXPORT size_t     ID3_RemoveAlbums (ID3_Tag *);

ID3_C_EXPORT char      *ID3_GetTitle (const ID3_Tag *);
ID3_C_EXPORT ID3_Frame *ID3_AddTitle (ID3_Tag *, const char *, bool replace = false);
ID3_C_EXPORT size_t     ID3_RemoveTitles (ID3_Tag *);

ID3_C_EXPORT char      *ID3_GetYear (const ID3_Tag *);
ID3_C_EXPORT ID3_Frame *ID3_AddYear (ID3_Tag *, const char *, bool replace = false);
ID3_C_EXPORT size_t     ID3_RemoveYears (ID3_Tag *);

ID3_C_EXPORT char      *ID3_GetComment (const ID3_Tag *, const char *desc = NULL);
ID3_C_EXPORT ID3_Frame *ID3_AddComment (ID3_Tag *, const char *, bool = false);
ID3_C_EXPORT ID3_Frame *ID3_AddComment (ID3_Tag *, const char *, const char *, bool = false);
ID3_C_EXPORT ID3_Frame *ID3_AddComment (ID3_Tag *, const char *, const char *, const char *,
                                        bool = false);
ID3_C_EXPORT size_t     ID3_RemoveComments (ID3_Tag *, const char * = NULL);

ID3_C_EXPORT char      *ID3_GetTrack (const ID3_Tag *);
ID3_C_EXPORT size_t     ID3_GetTrackNum (const ID3_Tag *);
//following routine courtesy of John George
ID3_C_EXPORT ID3_Frame *ID3_AddTrack (ID3_Tag *, uchar ucTrack, uchar ucTotal = 0,
                                      bool replace = false);
ID3_C_EXPORT size_t     ID3_RemoveTracks (ID3_Tag *);

ID3_C_EXPORT char      *ID3_GetGenre (const ID3_Tag *);
ID3_C_EXPORT size_t     ID3_GetGenreNum (const ID3_Tag *);
ID3_C_EXPORT ID3_Frame *ID3_AddGenre (ID3_Tag *, size_t ucGenre, bool replace = false);
//following routine courtesy of John George
ID3_C_EXPORT ID3_Frame *ID3_AddGenre (ID3_Tag *, const char *, bool replace = false);
ID3_C_EXPORT size_t     ID3_RemoveGenres (ID3_Tag *);

ID3_C_EXPORT char      *ID3_GetLyrics (const ID3_Tag *);
ID3_C_EXPORT ID3_Frame *ID3_AddLyrics (ID3_Tag *, const char *, bool = false);
ID3_C_EXPORT ID3_Frame *ID3_AddLyrics (ID3_Tag *, const char *, const char *, bool = false);
ID3_C_EXPORT ID3_Frame *ID3_AddLyrics (ID3_Tag *, const char *, const char *, const char *,
                                       bool = false);
ID3_C_EXPORT size_t     ID3_RemoveLyrics (ID3_Tag *);

ID3_C_EXPORT char      *ID3_GetLyricist (const ID3_Tag *);
ID3_C_EXPORT ID3_Frame *ID3_AddLyricist (ID3_Tag *, const char *, bool replace = false);
ID3_C_EXPORT size_t     ID3_RemoveLyricist (ID3_Tag *);

ID3_C_EXPORT ID3_Frame *ID3_AddSyncLyrics (ID3_Tag *, const uchar *, size_t,
        ID3_TimeStampFormat, bool = false);
ID3_C_EXPORT ID3_Frame *ID3_AddSyncLyrics (ID3_Tag *, const uchar *, size_t,
        ID3_TimeStampFormat, const char *, bool = false);
ID3_C_EXPORT ID3_Frame *ID3_AddSyncLyrics (ID3_Tag *, const uchar *, size_t,
        ID3_TimeStampFormat, const char *, const char *,
        bool = false);
ID3_C_EXPORT ID3_Frame *ID3_AddSyncLyrics (ID3_Tag *, const uchar *, size_t,
        ID3_TimeStampFormat, const char *, const char *,
        ID3_ContentType, bool = false);
ID3_C_EXPORT ID3_Frame *ID3_GetSyncLyricsInfo (const ID3_Tag *tag, const char *lang,
        const char *desc, char &stampformat,
        char &type, size_t &size);
ID3_C_EXPORT ID3_Frame *ID3_GetSyncLyrics (const ID3_Tag *tag, const char *lang,
        const char *desc, const uchar *&pData, size_t &size);


//following routine courtesy of John George
ID3_C_EXPORT int ID3_GetPictureData (const ID3_Tag *, const char *TempPicPath);

//following routine courtesy of John George
ID3_C_EXPORT char *ID3_GetPictureMimeType (const ID3_Tag *);

//following routine courtesy of John George
ID3_C_EXPORT bool ID3_HasPicture (const ID3_Tag *);

//following two routines courtesy of John George
ID3_C_EXPORT ID3_Frame *ID3_AddPicture (ID3_Tag *, const char *TempPicPath, const char *MimeType, bool replace = false);
ID3_C_EXPORT ID3_Frame *ID3_AddPicture (ID3_Tag *, const char *TempPicPath, const char *MimeType, ID3_PictureType pictype, const char *Description, bool replace = false);

//following routine courtesy of John George
ID3_C_EXPORT size_t ID3_RemovePictures (ID3_Tag *);

//following routine courtesy of John George
ID3_C_EXPORT size_t ID3_GetPictureDataOfPicType (ID3_Tag *, const char *TempPicPath, ID3_PictureType pictype);

//following routine courtesy of John George
ID3_C_EXPORT char *ID3_GetMimeTypeOfPicType (ID3_Tag *, ID3_PictureType pictype);

//following routine courtesy of John George
ID3_C_EXPORT char *ID3_GetDescriptionOfPicType (ID3_Tag *, ID3_PictureType pictype);

//following routine courtesy of John George
ID3_C_EXPORT size_t ID3_RemovePictureType (ID3_Tag *, ID3_PictureType pictype);


#endif /* _ID3LIB_MISC_SUPPORT_H_ */

