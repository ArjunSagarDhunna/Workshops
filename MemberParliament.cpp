#define _CRT_SECURE_NO_WARNINGS
#include"MemberParliament.h"
#include<string.h>
#include<iomanip>
#include<iostream>
using namespace std;
namespace sdds 
{
	MemberParliament::MemberParliament(const  char* Pid, int Age) 
	{
		strcpy(ID, Pid);
		this->Age = Age;
		strcpy(this->Dir, "Unassigned");
	}
	void MemberParliament::NewDistrict(const char* Pdistrict) 
	{
		cout << "|" << setw(8) << right << ID << "| |" << setw(20) << right << this->Dir << " ---> ";
		strcpy(this->Dir, Pdistrict);
		cout << setw(23) << left << Dir << "|" << endl;
	}
	ostream& MemberParliament::write(ostream& os) const 
	{
		os << "| " << ID << " | " << Age << " | " << Dir;
		return os;
	}
	istream& MemberParliament::read(istream& in) 
	{
		cout << "Age: ";
		in >> Age;
		cout << "Id: ";
		in >> ID;
		cout << "District: ";
		in >> Dir;
		return in;
	}
	ostream& operator<<(ostream& os, const MemberParliament& M) 
	{
		return  M.write(os);
	}
	istream& operator>>(istream& istr, MemberParliament& M) 
	{
		return M.read(istr);
	}
}