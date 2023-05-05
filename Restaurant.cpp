/*
Name: Sandeep Digpal
Student ID: 126454214
Seneca email: sdigpal@myseneca.ca
Date: 08-10-2022
*/
#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Restaurant.h"

using namespace std;
namespace sdds
{
    int call_count = 0;
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) 
    {
        m_nofReser = cnt;
        m_reservation = new Reservation[m_nofReser];
        for (auto i = 0u; i < m_nofReser; ++i)
        {
            m_reservation[i] = *reservations[i];
        }
    }
    Restaurant::Restaurant(const Restaurant& src) 
    {
        *this = src;
    }

    Restaurant& Restaurant::operator=(const Restaurant& src) 
    {
        if (this != &src) 
        {
            m_nofReser = src.m_nofReser;
            delete[] m_reservation;
            if (src.m_reservation != nullptr)
            {
                m_reservation = new Reservation[m_nofReser];
                for (auto i = 0u; i < m_nofReser; ++i)
                {
                    m_reservation[i] = src.m_reservation[i];
                }
            }
            else m_reservation = nullptr;
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant&& src)noexcept 
    {
        *this = move(src);
    }

    Restaurant& Restaurant::operator=(Restaurant&& src)noexcept 
    {
        if (this != &src) 
        {
            delete[] m_reservation;

            m_nofReser = src.m_nofReser;
            m_reservation = src.m_reservation;

            src.m_reservation = nullptr;
            src.m_nofReser = 0;
        }

        return *this;
    }

    Restaurant::~Restaurant()
    {
        delete[] m_reservation;
    }
    size_t Restaurant::size()
    {
        return m_nofReser;
    }
    ostream& operator<<(std::ostream& os, const Restaurant& src) 
    {
        os << "--------------------------" << endl;
        os << "Fancy Restaurant (" << ++call_count << ")" << endl;
        os << "--------------------------" << endl;

        if (src.m_nofReser < 1)
            os << "This restaurant is empty!" << endl;
        else {
            for (auto i = 0u; i < src.m_nofReser; ++i)
            {
                os << src.m_reservation[i];
            }
        }

        os << "--------------------------" << endl;

        return os;
    }
}