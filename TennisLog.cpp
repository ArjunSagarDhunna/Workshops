/*
Name: Sandeep Digpal
Student number: 126454214
seneca email: sdigpal@myseneca.ca
Date: 24-09-2022
*/
#define CRT_SECURE_NO_WARNINGS
#include "TennisLog.h"
#include <cstring>
#include <fstream>
#include <iostream>

namespace sdds {


    TennisMatch::operator bool() const 
    {
        return m_matchId > 0 && m_tournamentId.length() > 0;
    }

    std::ostream& operator<<(std::ostream& os, const TennisMatch& match) 
    {
        if (!match) 
        {
            os << "Empty Match";
        }
        else 
        {
            os.fill('.');
            os.width(23);
            os << std::right << "Tourney ID : ";
            os.width(30);
            os << std::left << match.m_tournamentId << std::endl;
            os.width(23);
            os << std::right << "Match ID : ";
            os.width(30);
            os << std::left << match.m_matchId << std::endl;
            os.width(23);
            os << std::right << "Tourney : ";
            os.width(30);
            os << std::left << match.m_tournamentName << std::endl;
            os.width(23);
            os << std::right << "Winner : ";
            os.width(30);
            os << std::left << match.m_winner << std::endl;
            os.width(23);
            os << std::right << "Loser : ";
            os.width(30);
            os << std::left << match.m_loser << std::endl;
        }

        return os;
    }


    TennisLog::TennisLog() 
    {

    }


    TennisLog::~TennisLog() 
    {
        delete[] m_matches; 
    }


    TennisLog::TennisLog(const TennisLog& log) 
    {
        *this = log; 
    }


    TennisLog::TennisLog(TennisLog&& log) 
    {
        *this = std::move(log); 
    }


    TennisLog& TennisLog::operator=(const TennisLog& log) 
    {
        if (this != &log) 
        {
            delete[] m_matches;
            m_numMatches = log.m_numMatches;
            m_matches = new TennisMatch[m_numMatches];
            for (size_t i = 0; i < m_numMatches; i++) 
            {
                m_matches[i] = log.m_matches[i];
            }
        }
        return *this;
    }

    TennisLog& TennisLog::operator=(TennisLog&& log) 
    {
        if (this != &log && log.m_numMatches > 0) 
        {
            m_numMatches = log.m_numMatches;
            delete[] m_matches;
            m_matches = log.m_matches;
            log.m_matches = nullptr;
            log.m_numMatches = 0;
        }
        return *this;
    }

    TennisLog::TennisLog(const char* filename) 
    {
        std::string buffer;
        std::ifstream file(filename);

        size_t numMatches{ 0 };
        if (file.is_open()) 
        {
            std::getline(file, buffer);

            while (file) 
            {
                std::getline(file, buffer);
                numMatches++;
            }

            numMatches--;
            m_matches = new TennisMatch[numMatches];
            file.clear();
            file.seekg(0);
            std::getline(file, buffer);
            while (file) 
            {
                std::getline(file, buffer, ',');
                if (file) 
                {
                    m_matches[m_numMatches].m_tournamentId = buffer;
                    std::getline(file, buffer, ',');
                    m_matches[m_numMatches].m_tournamentName = buffer;
                    std::getline(file, buffer, ',');
                    m_matches[m_numMatches].m_matchId = std::stoul(buffer);
                    std::getline(file, buffer, ',');
                    m_matches[m_numMatches].m_winner = buffer;
                    std::getline(file, buffer);
                    m_matches[m_numMatches].m_loser = buffer;
                    m_numMatches++;
                }
            }
            file.close();
        }
        else 
        {
            std::cerr << "Error: Could not open file: " << filename << std::endl;
        }
    }


    void TennisLog::addMatch(const TennisMatch& match) 
    {
        TennisMatch* tempMatches = new TennisMatch[m_numMatches + 1];
        for (size_t i = 0; i < m_numMatches; i++) 
        {
            tempMatches[i] = m_matches[i];
        }

        delete[] m_matches;
        m_matches = tempMatches;
        m_matches[m_numMatches] = match;
        m_numMatches++;
    }

    TennisLog TennisLog::findMatches(const char* playerName) 
    {
        TennisLog log;
        for (size_t i = 0; i < m_numMatches; i++) 
        {
            if (strcmp(playerName, m_matches[i].m_winner.c_str()) == 0 ||
                strcmp(playerName, m_matches[i].m_loser.c_str()) == 0) 
            {
                log.addMatch(m_matches[i]);
            }
        }
        return log;
    }

    const TennisMatch TennisLog::operator[](size_t index) const 
    {
        TennisMatch match;
        if (index < m_numMatches) 
        {
            match = m_matches[index];
        }
        return match;
    }

    TennisLog::operator size_t() const 
    {
        return m_numMatches; 
    }

}