/*
Name: Sandeep Digpal
Student ID: 126454214
Seneca email: sdigpal@myseneca.ca
Date: 01-10-2022
*/

#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>

namespace sdds
{
   
    class Dictionary
    {
        std::string m_term{};
        std::string m_definition{};

    public:
        const std::string& getTerm() const { return m_term; }
        const std::string& getDefinition() const { return m_definition; }
        Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
      
        Dictionary();
        bool operator==(const Dictionary& obj);
        friend std::ostream& operator<<(std::ostream& out, const Dictionary& obj);
    };
}

#endif