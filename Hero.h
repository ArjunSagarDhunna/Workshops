#pragma once
#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include "Power.h"

namespace sdds {
    class Hero {
        char max_name[MAX_LEN];
        int num_power;
        Power* max_power;
        int p_level;
    public:
        Hero();
        Hero(const char* name, Power* power, int count_powers);
        ~Hero();
        std::ostream& display() const;
        Hero& operator+=(Power&);
        Hero& operator-=(int);
        friend bool operator<(const Hero&, const Hero&);
        friend bool operator>(const Hero&, const Hero&);
        friend bool operator>>(Power&, Hero&);
        friend bool operator<<(Hero&, Power&);
    };
}
#endif
