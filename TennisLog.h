/*
Name: Sandeep Digpal
Student number: 126454214
seneca email: sdigpal@myseneca.ca
Date: 24-09-2022
*/
#pragma once
#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <iostream>
#include <string>

namespace sdds {

	struct TennisMatch 
	{
		std::string m_tournamentId{};
		std::string m_tournamentName{};
		unsigned int m_matchId{};
		std::string m_winner{};
		std::string m_loser{};
		operator bool() const;
	};

	std::ostream& operator<<(std::ostream&, const TennisMatch&);

	class TennisLog
	{
		TennisMatch* m_matches{};
		size_t m_numMatches{};
	public:
		TennisLog();
		~TennisLog();
		TennisLog(const TennisLog&);
		TennisLog(TennisLog&&);
		TennisLog(const char* filename);
		void addMatch(const TennisMatch&);
		TennisLog findMatches(const char* playerName);
		const TennisMatch operator[](size_t) const;
		operator size_t() const;
		TennisLog& operator=(const TennisLog&);
		TennisLog& operator=(TennisLog&&);
	};

}
#endif