/*
*****************************************************************************
                          Workshop - #6 (P2)
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
#define MAXITEMS 10

#include <stdio.h>

int main(void)
{
    int flag = 0, items_listed = 0, i = 0;
    int  p[MAXITEMS] = { 0 };
    int forecast, year, Year, Month, month;
    double  netIncome = 0, costs = 0;
    double  m, M, y, Y;
    double cost[MAXITEMS] = { 0 };
    char f[MAXITEMS] = { 0 };
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    while (flag == 0)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < 500)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        if (netIncome > 400000)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
        if ((netIncome >= 500) && (netIncome <= 400000))
        {
            flag = 1;
        }

    }
    flag = 0;
    while (flag == 0)
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &items_listed);
        if ((items_listed < 1) || (items_listed > MAXITEMS))
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else
        {
            flag = 1;
        }
    }
    for (i = 0; i < items_listed; i++)
    {
        printf("\nItem-%d Details:\n", (i + 1));
        flag = 0;
        while (flag == 0)
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < 100)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {
                costs = costs + cost[i];
                flag = 1;
            }
        }
        flag = 0;
        while (flag == 0)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &p[i]);
            if (p[i] < 1 || p[i]>3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {
                flag = 1;
            }
        }
        flag = 0;
        while (flag == 0)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%s", &f[i]);
            if (f[i] != 'y' && f[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase \'y\' or \'n\'\n");
            }
            else
            {
                flag = 1;
            }
        }
    }
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < items_listed; i++)
    {
        printf("%3d  %5d  %7c    %11.2lf\n", (i + 1), p[i], f[i], cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", costs);

    int financeFlag = 1;

    do
    {
        flag = 1;

        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &forecast);
        printf("\n");

        if (forecast < 0 || forecast>2)
        {
            printf("ERROR: Invalid menu selection.\n");
            flag = 1;
        }

        else if (forecast == 0)
        {
            flag = 0;
        }

        else if (forecast == 1)
        {
            printf("====================================================\n");

            costs = 0;
            for (i = 0; i < items_listed; i++)
            {
                costs += cost[i];
                if (f[i] == 'y')
                {
                    financeFlag = 1;
                }
            }

            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", costs);

            netIncome *= 12;
            y = costs / (netIncome);
            year = (int)y;

            m = (int)costs % (int)netIncome;
            m = (m * 12) / netIncome;
            m *= 10;
            month = (int)m;
            int result = month % 10;
            int round = (result >= 5);
            month /= 10;
            month += round;
            netIncome /= 12;

            printf("Forecast: %d years, %d months\n", year, month);
            if (financeFlag == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            flag = 1;
        }
        else if (forecast == 2)
        {
            financeFlag = 0;
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &forecast);
            printf("\n");

            printf("====================================================\n");

            costs = 0;
            for (i = 0; i < items_listed; i++)
            {
                if (p[i] == forecast)
                {
                    costs += cost[i];
                }
                if (p[i] == forecast && f[i] == 'y')
                {
                    financeFlag = 1;
                }
            }
            printf("Filter:   by priority (%d)\n", forecast);
            printf("Amount:   $%1.2lf\n", costs);

            netIncome *= 12;
            Y = costs / (netIncome);
            Year = (int)Y;


            M = (int)costs % (int)netIncome;
            M = (M * 12) / netIncome;
            M *= 10;
            Month = (int)M;
            int result = Month % 10;
            int round = (result >= 1);
            Month /= 10;
            Month += round;
            netIncome /= 12;

            printf("Forecast: %d years, %d months\n", Year, Month);

            if (financeFlag == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");
            flag = 1;


        }
    } while (flag);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}