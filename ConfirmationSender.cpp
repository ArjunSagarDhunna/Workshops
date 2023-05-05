/*
Name: Sandeep Digpal
Student ID: 126454214
Seneca email: sdigpal@myseneca.ca
Date: 08-10-2022
*/
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds
{
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
    {
        *this = src;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
    {
        if (this != &src)
        {
            if (m_reservation)
            {
                delete[] m_reservation;
                m_reservation = nullptr;
            }
            m_nofConfirmation = src.m_nofConfirmation;

            m_reservation = new const Reservation * [src.m_nofConfirmation];
            for (auto i = 0u; i < m_nofConfirmation; ++i)
            {
                m_reservation[i] = src.m_reservation[i];
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)noexcept 
    {
        *this = move(src);
    }
    ConfirmationSender& ConfirmationSender:: operator=(ConfirmationSender&& src)noexcept 
    {
        if (this != &src) 
        {
            if (m_reservation != nullptr)
            {
                delete[] m_reservation;
                m_reservation = nullptr;
            }

            m_nofConfirmation = src.m_nofConfirmation;

            m_reservation = src.m_reservation;
            src.m_reservation = nullptr;
            src.m_nofConfirmation = 0u;
        }
        return *this;
    }
    ConfirmationSender::~ConfirmationSender() 
    {
        delete[]  m_reservation;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) 
    {
        bool flag{};

        for (auto i = 0u; i < m_nofConfirmation && !flag; ++i) 
        {
            if (m_reservation[i] == &res)
                flag = true;
        }

        if (!flag) 
        {
            const Reservation** temp = new const Reservation * [m_nofConfirmation + 1u];


            for (auto i = 0u; i < m_nofConfirmation; ++i)
                temp[i] = m_reservation[i];

            temp[m_nofConfirmation] = &res;
            delete[] m_reservation;
            m_reservation = nullptr;
            m_reservation = temp;
            m_nofConfirmation++;

        }
        return *this;
    }
    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) 
    {
        bool flag{};
        for (auto i = 0u; i < m_nofConfirmation; ++i) 
        {
            if (m_reservation[i] == &res) 
            {
                m_reservation[i] = nullptr;
                flag = true;
            }
        }

        if (flag) 
        {
            const Reservation** temp = new const Reservation * [m_nofConfirmation - 1u];
            for (auto i = 0u, j = 0u; i < m_nofConfirmation; ++i) 
            {
                if (m_reservation[i])
                    temp[j++] = m_reservation[i];
            }
            delete[] m_reservation;
            m_reservation = nullptr;
            m_reservation = temp;
            m_nofConfirmation--;
        }
        return *this;
    }
    ostream& operator<<(std::ostream& os, ConfirmationSender& src) 
    {
        os << "--------------------------" << endl;
        os << "Confirmations to Send" << endl;
        os << "--------------------------" << endl;

        if (src.m_nofConfirmation == 0)
        {
            os << "There are no confirmations to send!" << endl;
        }
        else
        {
            for (size_t i = 0; i < src.m_nofConfirmation; ++i)
                os << *src.m_reservation[i];
        }

        os << "--------------------------" << endl;

        return os;
    }
}