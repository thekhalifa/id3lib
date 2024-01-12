// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_WRITERS_H_
#define _ID3LIB_WRITERS_H_

#include "id3/writer.h"
#include "id3/id3lib_streams.h"
#include <cstring>

class ID3_CPP_EXPORT ID3_OStreamWriter : public ID3_Writer
{
    ostream &_stream;
    pos_type _beg;
protected:
    ostream &getWriter() const
    {
        return _stream;
    }
public:
    ID3_OStreamWriter (ostream &writer) : _stream (writer), _beg (_stream.tellp()) { ; }
    virtual ~ID3_OStreamWriter() { ; }

    virtual void close() { ; }
    virtual void flush()
    {
        _stream.flush();
    }

    virtual int_type writeChar (char_type ch)
    {
        _stream.put (ch);
        return ch;
    }

    /** Write up to \c len chars into buf and advance the internal position
     ** accordingly.  Returns the number of characters write into buf.
     **/
    virtual size_type writeChars (const char buf[], size_type len)
    {
        _stream.write (buf, len);
        return len;
    }
    virtual size_type writeChars (const char_type buf[], size_type len)
    {
        _stream.write (reinterpret_cast<const char *> (buf), len);
        return len;
    }

    virtual pos_type getBeg()
    {
        return _beg;
    }
    virtual pos_type getCur()
    {
        return _stream.tellp();
    }
};

class ID3_CPP_EXPORT ID3_OFStreamWriter : public ID3_OStreamWriter
{
    ofstream &_file;
public:
    ID3_OFStreamWriter (ofstream &writer)
        : ID3_OStreamWriter (writer), _file (writer) { ; }

    virtual void close()
    {
        _file.close();
    }
};

class ID3_CPP_EXPORT ID3_IOStreamWriter : public ID3_Writer
{
    iostream &_stream;
    pos_type  _beg;
protected:
    iostream &getWriter() const
    {
        return _stream;
    }
public:
    ID3_IOStreamWriter (iostream &writer) : _stream (writer), _beg (_stream.tellp()) { ; }
    virtual ~ID3_IOStreamWriter() { ; }

    virtual void close() { ; }
    virtual void flush()
    {
        _stream.flush();
    }

    virtual int_type writeChar (char_type ch)
    {
        _stream.put (ch);
        return ch;
    }

    /** Write up to \c len chars into buf and advance the internal position
     ** accordingly.  Returns the number of characters write into buf.
     **/
    virtual size_type writeChars (const char buf[], size_type len)
    {
        _stream.write (buf, len);
        return len;
    }
    virtual size_type writeChars (const char_type buf[], size_type len)
    {
        _stream.write (reinterpret_cast<const char *> (buf), len);
        return len;
    }

    virtual pos_type getBeg()
    {
        return _beg;
    }
    virtual pos_type getCur()
    {
        return _stream.tellp();
    }
};

class ID3_CPP_EXPORT ID3_FStreamWriter : public ID3_IOStreamWriter
{
    fstream &_file;
public:
    ID3_FStreamWriter (fstream &writer)
        : ID3_IOStreamWriter (writer), _file (writer) { ; }

    virtual void close()
    {
        _file.close();
    }
};

class ID3_CPP_EXPORT ID3_MemoryWriter : public ID3_Writer
{
    const char_type *_beg;
    /* */ char_type *_cur;
    const char_type *_end;
protected:
    void setBuffer (char_type *buf, size_t size)
    {
        _beg = buf;
        _cur = buf;
        _end = buf + size;
    };
public:
    ID3_MemoryWriter()
    {
        this->setBuffer (NULL, 0);
    }
    ID3_MemoryWriter (char_type buf[], size_t size)
    {
        this->setBuffer (buf, size);
    }
    virtual ~ID3_MemoryWriter() { ; }
    virtual void close() { ; }
    virtual void flush() { ; }

    /** Write up to \c len chars from buf and advance the internal position
     ** accordingly.  Returns the number of characters written from buf.
     **/
    virtual size_type writeChars (const char buf[], size_type len)
    {
        return this->writeChars (reinterpret_cast<const char_type *> (buf), len);
    }
    virtual size_type writeChars (const char_type buf[], size_type len)
    {
        size_type remaining = _end - _cur;
        size_type size = (remaining > len) ? len : remaining;
        ::memcpy (_cur, buf, size);
        _cur += size;
        return size;
    }

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
};

#endif /* _ID3LIB_WRITERS_H_ */

