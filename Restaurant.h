/*
Name: Sandeep Digpal
Student ID: 126454214
Seneca email: sdigpal@myseneca.ca
Date: 08-10-2022
*/
#pragma once
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"
namespace sdds
{
    class Restaurant
    {
        Reservation* m_reservation{ nullptr };
        size_t m_nofReser{ 0u };
        static size_t call_count;
    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& src);
        Restaurant& operator=(const Restaurant& src);
        Restaurant(Restaurant&& src)noexcept;
        Restaurant& operator=(Restaurant&& src)noexcept;
        ~Restaurant();
        size_t size();
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& src);
    };
}
#endif