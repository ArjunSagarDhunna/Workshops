#define _CRT_SECURE_NO_WARNINGS
#define MAXITEMS 10

#include <stdio.h>

int main(void)
{
    int exit = 0, listofitems = 0, k, p[MAXITEMS]={0};
    double netIncome = 0, cost[MAXITEMS]={0}, costs = 0;
    char f[MAXITEMS]={0};
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    while (exit == 0)
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
            exit = 1;
        }

    }
    exit = 0;
    while (exit == 0)
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &listofitems);
        if ((listofitems < 1) || (listofitems > MAXITEMS))
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else
        {
            exit = 1;
        }
    }
    for (k = 0; k < listofitems; k++)
    {
        printf("\nItem-%d Details:\n", (k + 1));
        exit = 0;
        while (exit == 0)
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[k]);
            if (cost[k] < 100)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {
                costs = costs + cost[k];
                exit = 1;
            }
        }
        exit = 0;
        while (exit == 0)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &p[k]);
            if (p[k] < 1 || p[k]>3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {
                exit = 1;
            }
        }
        exit = 0;
        while (exit == 0)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%s", &f[k]);
            if (f[k] != 'y' && f[k] != 'n')
            {
                printf("      ERROR: Must be a lowercase \'y\' or \'n\'\n");
            }
            else
            {
                exit = 1;
            }
        }
    }
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (k = 0; k < listofitems; k++)
    {
        printf("%3d  %5d  %7c    %11.2lf\n", (k + 1), p[k], f[k], cost[k]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", costs);
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}