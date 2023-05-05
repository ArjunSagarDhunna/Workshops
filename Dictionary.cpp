/*
Name: Sandeep Digpal
Student ID: 126454214
Seneca email: sdigpal@myseneca.ca
Date: 01-10-2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Dictionary.h"
#include <iomanip>

namespace sdds
{
    Dictionary::Dictionary()
    {

    }
    bool Dictionary::operator==(const Dictionary& obj)
    {
        return (m_term == obj.m_term && m_definition == obj.m_definition);
    }
    std::ostream& operator<<(std::ostream& out, const Dictionary& obj)
    {
        out << std::setw(20) << std::right << obj.getTerm() << ": " << obj.getDefinition();
        return out;
    }
}