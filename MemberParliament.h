#pragma once
#ifndef SDDS_MEMBERPARLIAMENT_H__
#define SDDS_MEMBERPARLIAMENT_H__ 
#include<iostream>
using namespace std;
namespace sdds 
{
	class MemberParliament 
	{
	private:
		char ID[32];
		char Dir[64];
		int Age;
	public:
		MemberParliament(const  char* ID, int Age);
		void NewDistrict(const char* Dir);
		ostream& write(ostream& os)const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream& os, const MemberParliament& M);
	istream& operator>>(istream& istr, MemberParliament& M);
}
#endif // !_SDDS_MINISTER_H_
