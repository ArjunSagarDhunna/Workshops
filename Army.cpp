#define _CRT_SECURE_NO_WARNINGS
#include "Army.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds
{
    // default constructor to set object to an empty state
    Army::Army() {
        setEmpty();
    }

    // function to set nationality to empty string and units and pow to 0
    void Army::setEmpty() {
        nationality[0] = '\0';
        units = 0;
        power = 0;
    }

    // function to set nationality, power and units to input parameters if all valid
    void Army::createArmy(const char* country, double pow, int troops) {

        // validate country is not null and length of country is greater than 0, and pow and troops are grater than 0
        if (country != nullptr && strlen(country) > 0 && pow > 0 && troops > 0)
        {
            // copy country to nationality
            if (strlen(country) > MAX_NAME_LEN) // number of characters in country is greater than MAX_NAME_LEN, copy first MAX_NAME_LEN to nationality from country
            {
                strncpy(nationality, country, MAX_NAME_LEN);
            }
            else // else copy the characters from nationality to country
                strcpy(nationality, country);

            // copy troops to units and pow to power
            units = troops;
            power = pow;
        }
        else // any invalid value, set th object to empty state
            setEmpty();
    }

    // function to update units and power
    void Army::updateUnits(int troops) {

        units += troops; // add input troops to units
        power += troops * 0.25; // add 25% of the newly provided troops as power

    }

    // getters
    // return nationality
    const char* Army::checkNationality() const {
        return nationality;
    }

    // return units
    int Army::checkCapacity() const {
        return units;
    }

    // return power
    double Army::checkPower() const {
        return power;
    }

    // function that returns true if nationality is empty string and units is less than or 0 else return false
    bool Army::isEmpty() const {
        return strlen(nationality) == 0 && units <= 0;
    }

    // function that returns true if power of this Army is greater than power of army else return false
    bool Army::isStrongerThan(const Army& army)const {
        return power > army.power;
    }

    // function that takes as input references of 2 Army objects and updates
    // the units and power of one of the Army object
    void battle(Army& arm1, Army& arm2) {

        // validate input armies are valid
        if (!arm1.isEmpty() && !arm2.isEmpty())
        {
            // display the armies for the battle and the army who won the battle
            cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality();
            // arm1 is stronger than arm2
            if (arm1.isStrongerThan(arm2)) {
                // decrement the units of arm1 by 50%
                arm2.updateUnits(-arm2.checkCapacity() / 2);
                cout << ", " << arm1.checkNationality() << " is victorious!" << endl;
            }
            else
            {
                // arm2 is stronger than arm1
                cout << ", " << arm2.checkNationality() << " is victorious!" << endl;
                // decrement the units of arm2 by 50%
                arm1.updateUnits(-arm1.checkCapacity() / 2);
            }

        }
    }

    // function that takes as inputs an array of Army objects and its size
    // and displays the nationality, units and power of each army that are not empty
    void displayDetails(const Army* armies, int size) {
        cout << "Armies reporting to battle: " << endl;

        // loop over the array
        for (int i = 0; i < size; i++)
        {
            // ith army is not empty, display the nationality, units and power
            if (!armies[i].isEmpty())
                cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " << armies[i].checkCapacity()
                << ", Power left: " << fixed << setprecision(1) << armies[i].checkPower() << endl;
        }
    }
}

// end of Army.cpp