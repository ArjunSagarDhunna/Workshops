/*************************************************/
/*Workshop 3 part1
Name: Arju Sagar Dhunna
student id: 157099219
Seneca email: adhunna@senecacollege.ca*/
/*************************************************/

#ifndef ARMY_H
#define ARMY_H

#define MAX_NAME_LEN 50

namespace sdds
{
    class Army
    {
    private:
        // data members
        char nationality[MAX_NAME_LEN + 1];
        int units;
        double power;

    public:
        Army(); // default constructor
        void setEmpty(); // set army to empty state
        void createArmy(const char* country, double pow, int troops); // set data members
        void updateUnits(int troops); // update units and power
        // getters
        const char* checkNationality() const;
        int checkCapacity() const;
        double checkPower() const;
        bool isEmpty() const; // check if army is in empty state
        bool isStrongerThan(const Army& army)const; // check if this army is stronger than parameter army
    };

    // global functions
    void battle(Army& arm1, Army& arm2);
    void displayDetails(const Army* armies, int size);
}

#endif // ARMY_H


