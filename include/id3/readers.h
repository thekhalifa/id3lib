// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_READERS_H_
#define _ID3LIB_READERS_H_

#include "id3/id3lib_streams.h"
#include "id3/reader.h"

class ID3_CPP_EXPORT ID3_IStreamReader : public ID3_Reader
{
    istream &_stream;
protected:
    istream &getReader() const
    {
        return _stream;
    }
public:
    ID3_IStreamReader (istream &reader) : _stream (reader) { ; }
    virtual ~ID3_IStreamReader() { ; }
    virtual void close() { ; }

    virtual int_type peekChar()
    {
        return _stream.peek();
    }

    /** Read up to \c len chars into buf and advance the internal position
     ** accordingly.  Returns the number of characters read into buf.
     **/
    virtual size_type readChars (char buf[], size_type len)
    {
        return this->readChars (reinterpret_cast<uchar *> (buf), len);
    }
    virtual size_type readChars (char_type buf[], size_type len)
    {
        _stream.read ( (char *) buf, len);
        return _stream.gcount();
    }

    virtual pos_type getBeg()
    {
        return 0;
    }
    virtual pos_type getCur()
    {
        return _stream.tellg();
    }
    virtual pos_type getEnd()
    {
        pos_type cur = this->getCur();
        _stream.seekg (0, ios::end);
        pos_type end = this->getCur();
        this->setCur (cur);
        return end;
    }

    /** Set the value of the internal position for reading.
     **/
    virtual pos_type setCur (pos_type pos)
    {
        _stream.seekg (pos);
        return pos;
    }
};

class ID3_CPP_EXPORT ID3_IFStreamReader : public ID3_IStreamReader
{
    ifstream &_file;
public:
    ID3_IFStreamReader (ifstream &reader)
        : ID3_IStreamReader (reader), _file (reader) { ; }

    virtual void close()
    {
        _file.close();
    }
};

class ID3_CPP_EXPORT ID3_MemoryReader : public ID3_Reader
{
    const char_type *_beg;
    const char_type *_cur;
    const char_type *_end;
protected:
    void setBuffer (const char_type *buf, size_type size)
    {
        _beg = buf;
        _cur = buf;
        _end = buf + size;
    };
public:
    ID3_MemoryReader()
    {
        this->setBuffer (NULL, 0);
    }
    ID3_MemoryReader (const char_type *buf, size_type size)
    {
        this->setBuffer (buf, size);
    };
    ID3_MemoryReader (const char *buf, size_type size)
    {
        this->setBuffer (reinterpret_cast<const char_type *> (buf), size);
    };
    virtual ~ID3_MemoryReader() { ; }
    virtual void close() { ; }

    virtual int_type peekChar()
    {
        if (!this->atEnd()) {
            return *_cur;
        }

        return END_OF_READER;
    }

    /** Read up to \c len chars into buf and advance the internal position
     ** accordingly.  Returns the number of characters read into buf.
     **/
    virtual size_type readChars (char buf[], size_type len)
    {
        return this->readChars (reinterpret_cast<char_type *> (buf), len);
    }
    virtual size_type readChars (char_type buf[], size_type len);

    virtual pos_type getCur()
    {
        return _cur - _beg;
    }

    virtual pos_type getBeg()
    {
        return _beg - _beg;
    }

    virtual pos_type getEnd()
    {
        return _end - _beg;
    }

    /** Set the value of the internal position for reading.
     **/
    virtual pos_type setCur (pos_type pos)
    {
        pos_type end = this->getEnd();
        size_type size = (pos < end) ? pos : end;
        _cur = _beg + size;
        return this->getCur();
    }
};

#endif /* _ID3LIB_READERS_H_ */

