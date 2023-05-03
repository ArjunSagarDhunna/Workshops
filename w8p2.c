/*
*****************************************************************************
						  Workshop - #8 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* value)
{
	int n;
	do
	{
		scanf("%d", &n);
		if (n <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (n <= 0);
	if (value != NULL)
		*value = n;
	return n;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* value)
{
	double n;
	do
	{
		scanf("%lf", &n);
		if (n <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (n <= 0);
	if (value != NULL)
		*value = n;
	return n;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int value)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product ", value);
	printf("data for analysis.\n");
	printf("NOTE: A 'serving' is %dg\n", grams_per_serve);
	return;
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int n)
{
	struct CatFoodInfo food = { 0, 0, 0, 0 };
	printf("\nCat Food Product #%d\n", n + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.sku);
	printf("PRICE         : $");
	getDoublePositive(&food.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);

	return food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int calories, double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
	return;
}


//-----------------------------------------------------------------------------------------
//PART -2
//8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(double* pound, double* kg)
{
	double n = *pound / lbs_kg;
	if (kg != NULL)
		*kg = n;
	return n;
}
//9. convert lbs: g (call convert kg, then*1000)
int convertLbsG(double* pound, int* Grm)
{
	double z = *pound;
	double n= convertLbsKg(&z,&n) * 1000;
	if (Grm != NULL)
		*Grm = n;
	return n;
}
// 10. convert lbs: kg and g
void convertLbs(const double* pound, double* converted_to_KG, int* converted_toG)
{
	*converted_to_KG = *pound / lbs_kg;
	*converted_toG = *pound / lbs_kg * 1000;
}
// 11. calculate: servings based on gram Perserv
double calculateServings(int gram_per_serving, int weight_in_grams, double* total_servings)
{
	*total_servings = ((double)weight_in_grams / gram_per_serving);
	return *total_servings;
}
// 12 calculate: cost per serving
double calculateCostPerServing(double price, double total_Serving, double* Cost_per_servings)
{
	*Cost_per_servings = price / total_Serving;
	return *Cost_per_servings;
}
// 13 calculate: cost per calorie
double calculate_CoatPerCal(double price, double calories,double total_Serving, double* cost_per_calories)
{
	*cost_per_calories = (price / calories)/ total_Serving;
	return *cost_per_calories;
}
// 14 Derive a reporting detail record on the cat food  product
struct ReportData calculateReportData(struct CatFoodInfo food)
{
	struct ReportData report = { 0,0,0,0,0,0,0,0 };
	report.SKU = food.sku;
	report.Price = food.price;
	report.total_servings = calculateServings(grams_per_serve, convertLbsG(&food.weight, &report.Weight_in_G), &report.total_servings);
	report.cost_per_servings = calculateCostPerServing(food.price, report.total_servings, &report.cost_per_servings);
	report.Weighr_in_LBS = food.weight;
	report.calories_per_servings = calculate_CoatPerCal(food.price, food.calories, report.total_servings, &report.calories_per_servings);
	report.Total_cal = food.calories;
	report.Weight_in_KG = convertLbsKg(&food.weight, &report.Weight_in_KG);
	report.Weight_in_G = convertLbsG(&food.weight, &report.Weight_in_G);

	return report;
}
// 15. Display the formatted table for the analysis result
void displayReportHeader()
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", grams_per_serve );
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}
// 16. Display the formatted data row in the analysis
void displayReportData(struct ReportData Data, int t)
{
	int i = 0;
	
		if (i == t )
		{
			printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", Data.SKU, Data.Price, Data.Weighr_in_LBS, Data.Weight_in_KG, Data.Weight_in_G, Data.Total_cal, Data.total_servings, Data.cost_per_servings, Data.calories_per_servings);
		
		}
		
		else
		{
			printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", Data.SKU, Data.Price, Data.Weighr_in_LBS, Data.Weight_in_KG, Data.Weight_in_G, Data.Total_cal, Data.total_servings, Data.cost_per_servings, Data.calories_per_servings);
		}
}
// 17. Display the findings (cheapest)
void diplayFinalAnalysis(int SKU, double price)
{
	printf("\nFinal Analysis");
	printf("\n--------------");
	printf("\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:00%d Price: $%.2lf\n\nHappy shopping!\n", SKU, price);
}
//--------------------------------------------------------------------------------------------------------------
// 7. Logic entry point
void start()
{
	struct CatFoodInfo food[max_products] = { {0} };
	int num_products = 3, i;
	openingMessage(num_products);
	for (i = 0; i < num_products; i++)
		food[i] = getCatFoodInfo(i);
	displayCatFoodHeader();
	for (i = 0; i < num_products; i++)
		displayCatFoodData(food[i].sku, &food[i].price, food[i].calories, &food[i].weight);
	struct ReportData report[max_products] = { { 0 } };
	for (i = 0; i < num_products; i++)
		report[i] = calculateReportData(food[i]);
	displayReportHeader();
	int j , t;
	i = 0;
	for (i = 0; i < num_products; i++)
	{
		for (j = 0; j < num_products; j++)
		{
			if (report[j].cost_per_servings < report[i].cost_per_servings)
			{
				t = j;
			}

		}
		j = 0;

	}
	for (i = 0; i < num_products; i++)
	{
		if (i != 0)
		{
			displayReportData(report[i], t - i);
		}
		else
		{
			displayReportData(report[i], t);
		}
	}
	diplayFinalAnalysis(food[t].sku, food[t].price);
	return;

};




