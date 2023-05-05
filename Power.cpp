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
#include "Power.h"

using namespace std;

namespace sdds {

	Power::Power() {
		this->setEmpty();
	}
	Power::Power(const char* name, int rarity) {
		this->createPower(name, rarity);
	}
	void Power::setEmpty() {
		max_name[0] = '\0';
		max_rarity = 0;
	}
	void Power::createPower(const char* name, int rarity) {
		if (name && name[0] != '\0' && rarity > 0) {
			strncpy(this->max_name, name, MAX_LEN);
			this->max_rarity = rarity;
		}
		else {
			this->setEmpty();
		}
	}
	const char* Power::checkName() const {
		return max_name;
	}
	int Power::checkRarity() const {
		return max_rarity;
	}
	bool Power::isEmpty() const {
		return (max_name[0] == '\0' || max_rarity == 0);
	}
	void displayDetails(Power* powers, int size) {
		cout << "List of available powers: " << endl;
		for (int i = 0; i < size; i++) {
			if (!powers[i].isEmpty()) {
				cout << "  Name: " << powers[i].checkName() << ", "
					<< "Rarity: " << powers[i].checkRarity() << endl;
			}
		}
	}
}