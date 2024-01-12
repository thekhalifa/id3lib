// SPDX-License-Identifier: LGPL-3.0-only

#include "field_impl.h"
#include "id3/utils.h" // has <config.h> "id3/id3lib_streams.h" "id3/globals.h" "id3/id3lib_strings.h"
#include "io_helpers.h"

using namespace dami;

/** \fn ID3_Field& ID3_Field::operator=(uint32 val)
 ** \brief A shortcut for the Set method.
 **
 ** \code
 **   myFrame.GetField(ID3FN_PICTURETYPE)->= 0x0B;
 ** \endcode
 **
 ** \param val The data to assign to this field
 ** \sa Set(uint32)
 **/

/** \brief Sets the value of the field to the specified integer.
 ** \param data The data to assign to this field
 **/
void ID3_FieldImpl::Set (uint32 val)
{
    this->SetInteger (val);
}

void ID3_FieldImpl::SetInteger (uint32 val)
{
    if (this->GetType() == ID3FTY_INTEGER) {
        this->Clear();

        _integer = val;
        _changed = true;
    }
}

/** \fn uint32 ID3_Field::Get() const
 ** \brief Returns the value of the integer field.
 **
 ** \code
 **   uint32 picType = myFrame.GetField(ID3FN_PICTURETYPE)->Get();
 ** \endcode
 **
 ** \return The value of the integer field
 **/
uint32 ID3_FieldImpl::Get() const
{
    return this->GetInteger();
}

uint32 ID3_FieldImpl::GetInteger() const
{
    uint32 val = 0;

    if (this->GetType() == ID3FTY_INTEGER) {
        val = _integer;
    }

    return val;
}

bool ID3_FieldImpl::ParseInteger (ID3_Reader &reader)
{
    ID3D_NOTICE ("ID3_FieldImpl::ParseInteger(): beg = " << reader.getBeg());
    ID3D_NOTICE ("ID3_FieldImpl::ParseInteger(): cur = " << reader.getCur());
    ID3D_NOTICE ("ID3_FieldImpl::ParseInteger(): end = " << reader.getEnd());
    bool success = false;

    if (!reader.atEnd()) {
        this->Clear();
        size_t fixed = this->Size();
        size_t nBytes = (fixed > 0) ? fixed : sizeof (uint32);
        this->Set (io::readBENumber (reader, nBytes));
        _changed = false;
        success = true;
    }

    return success;
}

void ID3_FieldImpl::RenderInteger (ID3_Writer &writer) const
{
    io::writeBENumber (writer, _integer, this->Size());
}

