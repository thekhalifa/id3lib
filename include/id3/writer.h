// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_WRITER_H_
#define _ID3LIB_WRITER_H_

#include "id3/globals.h" //has <stdlib.h> "id3/sized_types.h"

class ID3_CPP_EXPORT ID3_Writer
{
public:
    typedef uint32 size_type;
    typedef uint8  char_type;
    typedef uint32 pos_type;
    typedef  int32 off_type;
    typedef  int16 int_type;
    static const int_type END_OF_WRITER;

    /** Close the writer.  Any further actions on the writer should fail. **/
    virtual void close() = 0;

    /** Flush the writer. **/
    virtual void flush() = 0;

    /** Return the beginning position in the writer **/
    virtual pos_type getBeg()
    {
        return static_cast<pos_type> (0);
    }

    /** Return the first position that can't be written to.  A return value of
     ** -1 indicates no (reasonable) limit to the writer.
     **/
    virtual pos_type getEnd()
    {
        return static_cast<pos_type> (-1);
    }

    /** Return the next position that will be written to */
    virtual pos_type getCur() = 0;

    /** Return the number of bytes written **/
    virtual size_type getSize()
    {
        return this->getCur() - this->getBeg();
    }

    /** Return the maximum number of bytes that can be written **/
    virtual size_type getMaxSize()
    {
        return this->getEnd() - this->getBeg();
    }

    /** Write a single character and advance the internal position.  Note that
     ** the interal position may advance more than one byte for a single
     ** character write.  Returns END_OF_WRITER if there isn't a character to
     ** write.
     **/
    virtual int_type writeChar (char_type ch)
    {
        if (this->atEnd()) {
            return END_OF_WRITER;
        }

        this->writeChars (&ch, 1);
        return ch;
    }

    /** Write up to \c len characters into buf and advance the internal position
     ** accordingly.  Returns the number of characters write into buf.  Note that
     ** the value returned may be less than the number of bytes that the internal
     ** position advances, due to multi-byte characters.
     **/
    virtual size_type writeChars (const char_type buf[], size_type len) = 0;
    virtual size_type writeChars (const char buf[], size_type len)
    {
        return this->writeChars (reinterpret_cast<const char_type *> (buf), len);
    }

    virtual bool atEnd()
    {
        return this->getCur() >= this->getEnd();
    }
};

#endif /* _ID3LIB_WRITER_H_ */

