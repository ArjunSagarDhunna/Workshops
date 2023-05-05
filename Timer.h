/*
Name: Sandeep Digpal
Student number: 126454214
seneca email: sdigpal@myseneca.ca
Date: 24-09-2022
*/
#pragma once
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>

namespace sdds 
{
	class Timer
	{
		std::chrono::time_point<std::chrono::system_clock> m_start;
	public:
		void start();
		long long stop();
	};

}
#endif