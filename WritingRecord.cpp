/****************************************************************************************************************
*								Workshop - 8
* Name:		Arjun Sagar Dhunna
* Email:		adhunna@myseneca.ca
* StudentId: 	157099219
*
****************************************************************************************************************/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds
{
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee> &emp, const GeneratingList<Salary> &sal)
	{
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers

		// quadratic complexity
		for (size_t i = 0; i < emp.size(); i++)
		{ // loop though emp then loop through sal to compare id
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (sal[j].id == emp[i].id)
				{
					if (!emp.sinValidation(emp[i].id))
					{
						throw std::string("Invalid SIN");
					}

					// create new EmployeeWage object to validate before adding
					EmployeeWage *newEmp = new EmployeeWage(emp[i].name, sal[j].salary);

					// validate salary using rangeValidator()
					try
					{
						newEmp->rangeValidator();
						// use overloaded += operator in GeneratingList to move the object
						activeEmp += newEmp;
						delete newEmp; // delete after moving the resource to activeEmp
					}

					// catch (char* except)
					catch (const std::string except)
					{
						delete newEmp; // deallocate if invalid salary
						throw except;
					}

					// validate SIN using GeneratingList::sinValidation()
					// do this validation earlier so you don't have to deallocate newEmp
					// if (!sal.sinValidation(sal[j].id))
					// {
					// 	delete newEmp;
					// 	throw std::string("Invalid SIN");
					// }
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee> &emp, const GeneratingList<Salary> &sal)
	{
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (size_t i = 0; i < emp.size(); i++)
		{ // loop though emp then loop through sal to compare id
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (sal[j].id == emp[i].id)
				{
					if (!emp.sinValidation(emp[i].id))
					{
						throw std::string("Invalid SIN");
					}

					// create new EmployeeWage object to validate before adding stored in a std::nique_ptr
					std::unique_ptr<EmployeeWage> newEmp(new EmployeeWage(emp[i].name, sal[j].salary));

					// validate salary using rangeValidator()
					// try
					// {
					newEmp->rangeValidator();
					// use overloaded += operator in GeneratingList to move the object
					activeEmp += std::move(newEmp);
					// delete newEmp; // no need to delete a unique_ptr
					// }
					// catch (const std::string except)
					// {
					// 	//delete newEmp; // no need to delete a unique_ptr
					// 	throw except;
					// }
				}
			}
		}
		return activeEmp;
	}
}