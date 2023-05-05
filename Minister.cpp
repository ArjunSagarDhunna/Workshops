#define _CRT_SECURE_NO_WARNINGS
#include "Minister.h"
#include<string.h>
namespace sdds 
{
	Minister::Minister(const char* idd, int age, double yearAO, const char* primeMinister, const char* Mdistrict):MemberParliament(idd, age) 
	{
		year = yearAO;
		this->NewDistrict(Mdistrict);
		strcpy(PrimeMinister, primeMinister);
	}

	void Minister::changePM(const char* pm)
	{
		strcpy(PrimeMinister, pm);
	}

	void Minister::assumeOffice(double yearAO)
	{
		this->year = yearAO;
	}

	ostream& Minister::write(ostream& os) const
	{
		MemberParliament::write(os);
		os << " | " << PrimeMinister << "/" << year;

		return os;
	}

	istream& Minister::read(istream& in)
	{
		MemberParliament::read(in);
		cout << "Reports TO: ";
		in >> PrimeMinister;
		cout << "Year Assumed Office: ";
		in >> year;
		return in;
	}
	ostream& operator<<(ostream& os, const Minister& M) 
	{
		return M.write(os);
	}
	istream& operator>>(istream& istr, Minister& M) 
	{
		return M.read(istr);
	}

}
