#pragma once
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

//----------------------------------------------------------------------------
// macros
#define max_products 3
#define grams_per_serve 64
#define lbs_kg 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int sku;       // Stock Keeping Unit
	double price;  // Product Price
	int calories;  // Per Serving
	double weight; // weight in Pounds
};
struct ReportData
{
	int SKU;
	double Price;
	int Total_cal;
	double Weight_in_KG;
	double Weighr_in_LBS;
	int Weight_in_G;
	double total_servings;
	double cost_per_servings;
	double calories_per_servings;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* n);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* n);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int n);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int n);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(int m, double* o, int n, double* p);

// 7. Logic entry point
void start(void); // is called by main() which is in file main1.c
//8 convert lbs to kg
double convertLbsKg(double* pound, double* kg);
//9 convert Lbs to Gram
int convertLbsG(double* pound, int* Grm);
// 10. convert lbs: kg and g
void convertLbs(const double* pound, double* converted_to_KG, int* converted_toG);
// 11. calculate: servings based on gram Perserv
double calculateServings(int gram_per_serving, int weight_in_grams, double* total_servings);
// 12 calculate: cost per serving
double calculateCostPerServing(double price, double total_Serving, double* Cost_per_servings);
// 13 calculate: cost per calorie
double calculate_CoatPerCal(double price, double calories, double total_Serving, double* cost_per_calories);
// 14 Derive a reporting detail record on the cat food  product
struct ReportData calculateReportData(struct CatFoodInfo food);
// 15. Display the formatted table for the analysis result
void displayReportHeader();
// 16. Display the formatted data row in the analysis
void displayReportData(struct ReportData Data, int t);
// 17. Display the findings (cheapest)
void diplayFinalAnalysis(int SKU, double price);

