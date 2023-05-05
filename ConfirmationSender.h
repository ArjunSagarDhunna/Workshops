/*
Name: Sandeep Digpal
Student ID: 126454214
Seneca email: sdigpal@myseneca.ca
Date: 08-10-2022
*/
#pragma once
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
namespace sdds
{
    class ConfirmationSender
    {
        const Reservation** m_reservation{ nullptr };
        size_t m_nofConfirmation{ 0u };
    public:
        ConfirmationSender() {};
        ConfirmationSender(const ConfirmationSender& src);
        ConfirmationSender& operator=(const ConfirmationSender& src);
        ConfirmationSender(ConfirmationSender&& src)noexcept;
        ConfirmationSender& operator=(ConfirmationSender&& src)noexcept;
        ~ConfirmationSender();

        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& os, ConfirmationSender& src);
    };
}
#endif