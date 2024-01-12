// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _MP3_HEADER_H_
#define _MP3_HEADER_H_

#include "io_decorators.h" //has "readers.h" "io_helpers.h" "utils.h"

class Mp3Info
{
public:
    Mp3Info()
    {
        _mp3_header_output = new Mp3_Headerinfo;
    };
    ~Mp3Info()
    {
        this->Clean();
    };
    void Clean();

    const Mp3_Headerinfo *GetMp3HeaderInfo() const
    {
        return _mp3_header_output;
    };
    bool Parse (ID3_Reader &, size_t mp3size);

    Mpeg_Layers Layer() const
    {
        return _mp3_header_output->layer;
    };
    Mpeg_Version Version() const
    {
        return _mp3_header_output->version;
    };
    MP3_BitRates Bitrate() const
    {
        return _mp3_header_output->bitrate;
    };
    Mp3_ChannelMode ChannelMode() const
    {
        return _mp3_header_output->channelmode;
    };
    Mp3_ModeExt ModeExt() const
    {
        return _mp3_header_output->modeext;
    };
    Mp3_Emphasis Emphasis() const
    {
        return _mp3_header_output->emphasis;
    };
    Mp3_Crc Crc() const
    {
        return _mp3_header_output->crc;
    };
    uint32 VbrBitrate() const
    {
        return _mp3_header_output->vbr_bitrate;
    };
    uint32 Frequency() const
    {
        return _mp3_header_output->frequency;
    };
    uint32 Framesize() const
    {
        return _mp3_header_output->framesize;
    };
    uint32 Frames() const
    {
        return _mp3_header_output->frames;
    };
    bool Private() const
    {
        return _mp3_header_output->privatebit;
    };
    bool Copyrighted() const
    {
        return _mp3_header_output->copyrighted;
    };
    bool Original() const
    {
        return _mp3_header_output->original;
    };
    uint32 Seconds() const
    {
        return _mp3_header_output->time;
    };

private:

    struct _mp3_header_internal { //http://www.mp3-tech.org/programmer/frame_header.html
//byte 1
        unsigned char frame_sync_a : 8; /* all bits should be set */
//byte 2
        unsigned char protection_bit : 1;
        unsigned char layer : 2;
        unsigned char id : 2;
        unsigned char frame_sync_b : 3; /* all bits should be set */
//byte 3
        unsigned char private_bit : 1;
        unsigned char padding_bit : 1;
        unsigned char frequency : 2;
        unsigned char bitrate_index : 4;
//byte 4
        unsigned char emphasis : 2;
        unsigned char original : 1;
        unsigned char copyright : 1;
        unsigned char mode_ext : 2;//only used in joint stereo
        unsigned char mode : 2;
    };

    Mp3_Headerinfo *_mp3_header_output;
}; //Info

#endif /* _MP3_HEADER_H_ */

