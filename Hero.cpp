//****************************************************************************
//Workshop 5 Part 2
//Full Name  : Arjun Sagar Dhunna
//Student ID#: 157099219
//Email      : adhunna@myseneca.ca
//Authenticity Declaration:
//I have done all the coding by myself and only copied the code that my 
//professor provided to complete my workshops and assignments. 
//*****************************************************************************
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include<cstring>
#include<string>
#include "Hero.h"

using namespace std;

namespace sdds {

    Hero::Hero() {
        max_name[0] = '\0';
        num_power = 0;
        max_power->setEmpty();
        p_level = 0;
    }

    Hero::Hero(const char* name, Power* power, int count_powers) {
        int totalRarity = 0;
        strcpy(max_name, name);
        num_power = count_powers;
        this->max_power = power;
        for (int i = 0; i < num_power; i++) {
            totalRarity += power[i].checkRarity();
        }
        p_level = totalRarity * num_power;
    }

    std::ostream& Hero::display() const {
        cout << "Name: " << max_name << endl;
        displayDetails(max_power, num_power);
        cout << "Power Level: " << p_level;
        return cout;
    }

    Hero& Hero::operator+=(Power& test) {
        int totalRarity = 0;
        num_power++;
        Power* temp = this->max_power;
        this->max_power = new Power[num_power];
        for (int i = 0; i < num_power; i++) {
            if (i < num_power - 1) {
                this->max_power[i] = temp[i];
            }
            else this->max_power[i] = test;
        }
        for (int i = 0; i < num_power; i++) {
            totalRarity += max_power[i].checkRarity();
        }
        p_level = totalRarity * num_power;
        return *this;
    }

    Hero& Hero::operator-=(int op) {
        p_level -= op;
        return *this;
    }

    bool operator<(const Hero& hero1, const Hero& hero2) {
        if (hero1.p_level < hero2.p_level) {
            return true;
        }
        else return false;
    }

    bool operator>(const Hero& hero1, const Hero& hero2) {
        if (hero1.p_level > hero2.p_level) {
            return true;
        }
        else return false;
    }

    bool operator>>(Power& power, Hero& hero) {
        hero.operator+=(power);
        return true;
    }

    bool operator<<(Hero& hero, Power& power) {
        hero.operator+=(power);
        return true;
    }

    Hero::~Hero() {
        delete[] max_power;
        max_power = nullptr;
    }
}
