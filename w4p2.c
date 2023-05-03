/*
*****************************************************************************
                          Workshop - #4 (P2)
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

#include <stdio.h>

int main(void)
{
    int end;
    do
    {    
        int a = 0, num_apples = 0, num_oranges = 0, num_pears = 0, num_tomatoes = 0, num_cabbages = 0, apples_picked = 0, oranges_picked = 0, pears_picked = 0, tomatoes_picked = 0, cabbages_picked = 0;
        printf("Grocery Shopping\n");
        printf("================\n");
        do 
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &num_apples);

            if (num_apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (num_apples < 0);
        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &num_oranges);

            if (num_oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (num_oranges < 0);
        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &num_pears);

            if (num_pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (num_pears < 0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &num_tomatoes);

            if (num_tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (num_tomatoes < 0);
        printf("\n");
        do 
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &num_cabbages);

            if (num_cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (num_cabbages < 0);


        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");
        while (num_apples > 0)
        {
            apples_picked = 1;
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &a);
            if ((0 < a) && (a <= num_apples))
            {
                num_apples = num_apples - a;
                if (num_apples > 0)
                    printf("Looks like we still need some APPLES...\n");
            }
            else if (a > num_apples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", num_apples);
            }
            else if (a <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
        }
        if (apples_picked == 1)
            printf("Great, that's the apples done!\n\n");
        while (num_oranges > 0)
        {
            oranges_picked = 1;
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &a);
            if ((0 < a) && (a <= num_oranges))
            {
                num_oranges = num_oranges - a;
                if (num_oranges > 0)
                   printf("Looks like we still need some ORANGES...\n");
            }
            else if (a > num_oranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", num_oranges);
            }
            else if (a <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
        }
        if (oranges_picked == 1)
            printf("Great, that's the oranges done!\n\n");
        while (num_pears > 0)
        {
            pears_picked = 1;
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &a);
            if ((0 < a) && (a <= num_pears))
            {
                num_pears = num_pears - a;
                if (num_pears > 0)
                    printf("Looks like we still need some PEARS...\n");
            }
            else if (a > num_pears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", num_pears);
            }
            else if (a <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
        }
        if (pears_picked == 1)
            printf("Great, that's the pears done!\n\n");
        while (num_tomatoes > 0)
        {
            tomatoes_picked = 1;
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &a);
            if ((0 < a) && (a <= num_tomatoes))
            {
                num_tomatoes = num_tomatoes - a;
                if (num_tomatoes > 0)
                    printf("Looks like we still need some TOMATOES...\n");
            }
            else if (a > num_tomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", num_tomatoes);
            }
            else if (a <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
        }
        if (tomatoes_picked == 1)
            printf("Great, that's the tomatoes done!\n\n");
        while (num_cabbages > 0)
        {
            cabbages_picked = 1;
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &a);
            if ((0 < a) && (a <= num_cabbages))
            {
                num_cabbages = num_cabbages - a;
                if (num_cabbages > 0)
                    printf("Looks like we still need some CABBAGES...\n");
            }
            else if (a > num_cabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", num_cabbages);
            }
            else if (a <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
        }
        if (cabbages_picked == 1)
            printf("Great, that's the cabbages done!\n\n");


        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &end);
        printf("\n");

    } while (end >= 1);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}