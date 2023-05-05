/*
Name: Sandeep Digpal
Student ID: 126454214
Seneca email: sdigpal@myseneca.ca
Date: 08-10-2022
*/
#pragma once
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>
namespace sdds
{
    class Reservation
    {
        std::string m_reservationID{};
        std::string m_name{};
        std::string m_email{};
        size_t m_nop{};
        size_t m_day{};
        size_t m_hr{};
    public:
        Reservation();
        void update(int day, int time);
        Reservation(const std::string& res);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& src);
    };

}
#endif
