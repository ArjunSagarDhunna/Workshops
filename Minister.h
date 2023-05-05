#pragma once
#ifndef SDDS_MINISTER_H__
#define SDDS_MINISTER_H__
#include"MemberParliament.h"
#include<iostream>
namespace sdds 
{
	class Minister :public MemberParliament 
	{
	private:
		char PrimeMinister[50];
		double year;
	public:

		Minister(const char* idd, int age, double yearAO, const char* primeMinister, const char* district);
		void changePM(const char* pm);
		void assumeOffice(double year);
		ostream& write(ostream& os)const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream& os, const Minister& M);
	istream& operator>>(istream& istr, Minister& M);
}
#endif // !_SDDS_MINISTER_H_
