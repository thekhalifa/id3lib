// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_FLAGS_H_
#define _ID3LIB_FLAGS_H_

#include "flags.h"

class ID3_Flags
{
public:
    typedef flags_t TYPE;

    ID3_Flags() : _f (0) { ; }
    virtual ~ID3_Flags() { ; }

    TYPE   get() const
    {
        return _f;
    }
    bool   test (TYPE f) const
    {
        return (this->get() & f) == f;
    }
    bool   set (TYPE f)
    {
        bool r = (_f != f);
        _f = f;
        return r;
    }
    bool   add (TYPE f)
    {
        return this->set (this->get() | f);
    }
    bool   remove (TYPE f)
    {
        return this->set (this->get() & ~f);
    }
    bool   clear()
    {
        return this->set (0);
    }
    bool   set (TYPE f, bool b)
    {
        if (b) {
            return this->add (f);
        }

        return this->remove (f);
    }

    ID3_Flags &operator= (const ID3_Flags &f)
    {
        if (this != &f) {
            this->set (f.get());
        }

        return *this;
    }

private:
    TYPE _f;
};

#endif /* _ID3LIB_FLAGS_H_ */
