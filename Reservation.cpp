/*
Name: Sandeep Digpal
Student ID: 126454214
Seneca email: sdigpal@myseneca.ca
Date: 08-10-2022
*/
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Reservation.h"

namespace sdds
{
    Reservation::Reservation() 
    {
        m_reservationID = "";
        m_name = "";
        m_email = "";
        m_nop = 0u;
        m_day = 0u;
        m_hr = 0u;
    }

    void Reservation::update(int day, int time)
    {
        m_day = day;
        m_hr = time;
    }

    Reservation::Reservation(const std::string& res) 
    {
        std::string tempStr = res;
        size_t tempInd = 0u;

        tempStr.erase(0, tempStr.find_first_not_of(' '));
        tempInd = tempStr.find(':');
        m_reservationID = tempStr.substr(0, tempInd);
        m_reservationID.erase(m_reservationID.find_last_not_of(' ') + 1);
        tempStr.erase(0, tempInd + 1);

        tempStr.erase(0, tempStr.find_first_not_of(' '));
        tempInd = tempStr.find(',');
        m_name = tempStr.substr(0, tempInd);
        m_name.erase(m_name.find_last_not_of(' ') + 1);
        tempStr.erase(0, tempInd + 1);

        tempStr.erase(0, tempStr.find_first_not_of(' '));
        tempInd = tempStr.find(',');
        m_email = tempStr.substr(0, tempInd);
        m_email.erase(m_email.find_last_not_of(' ') + 1);
        tempStr.erase(0, tempInd + 1);

        tempStr.erase(0, tempStr.find_first_not_of(' '));
        tempInd = tempStr.find(',');
        m_nop = std::stoi(tempStr.substr(0, tempInd));
        tempStr.erase(0, tempInd + 1);

        tempStr.erase(0, tempStr.find_first_not_of(' '));
        tempInd = tempStr.find(',');
        m_day = std::stoi(tempStr.substr(0, tempInd));
        tempStr.erase(0, tempInd + 1);

        tempStr.erase(0, tempStr.find_first_not_of(' '));
        tempInd = tempStr.find(',');
        m_hr = std::stoi(tempStr.substr(0, tempInd));
        tempStr.erase(0, tempInd + 1);
    }
    std::ostream& operator<<(std::ostream& os, const Reservation& src) 
    {
        std::string typeOfPeople{};
        os << "Reservation " << std::setw(10) << std::right << src.m_reservationID << ": " << std::setw(20) << std::right << src.m_name << "  " << std::setw(20) << std::left << "<" + src.m_email + ">";

        if (src.m_hr >= 6 && src.m_hr <= 9)
        {
            os << "    Breakfast";
        }
        else if (src.m_hr >= 11 && src.m_hr <= 15)
        {
            os << "    Lunch";
        }
        else if (src.m_hr >= 17 && src.m_hr <= 21)
        {
            os << "    Dinner";
        }
        else os << "    Drinks";

        if (src.m_nop > 1)
        {
            typeOfPeople = " people.";
        }
        else typeOfPeople = " person.";

        os << " on day " << src.m_day << " @ " << src.m_hr << ":00 for " << src.m_nop << typeOfPeople << std::endl;
        return os;

    }


}