/*
*****************************************************************************
                          Workshop - #8 (P1)
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
#define MAX_NUM_PRODUCTS 30
#define NUM_GRAMS_PER_SERVING 64

struct CatFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
};



int getIntPositive(int* i);


double getDoublePositive(double* d);


void openingMessage(const int);

struct CatFoodInfo getCatFoodInfo(const int);


void displayCatFoodHeader();

void displayCatFoodData(int, double*, int, double*);

void start();