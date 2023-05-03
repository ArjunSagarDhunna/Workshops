/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
a declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    char loop_types = ' ';
    int loop_repetation = 0, a = 0;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    while (loop_repetation != 0 || loop_types != 'Q')
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf("%c%d%*c", &loop_types, &loop_repetation);

        if ((loop_types == 'D') && (loop_repetation >= 3 && loop_repetation <= 20))
        {
            printf("DO-WHILE: ");
            a = 0;
            do
            {
                printf("D");
                a++;
            } while (a < loop_repetation);
            printf("\n\n");
        }
        else if ((loop_types == 'W') && (loop_repetation >= 3 && loop_repetation <= 20))
        {
            printf("WHILE   : ");
            a = 0;
            do
            {
                printf("W");
                a++;
            } while (a < loop_repetation);
            printf("\n\n");
        }
        else if ((loop_types == 'F') && (loop_repetation >= 3 && loop_repetation <= 20))
        {
            printf("FOR     : ");
            a = 0;
            do
            {
                printf("F");
                a++;
            } while (a < loop_repetation);
            printf("\n\n");
        }
        else if (loop_types == 'Q' && loop_repetation != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }
        else if ((loop_types != 'D')&&(loop_types != 'W')&&(loop_types !='F')&&(loop_types!='Q'))
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
        else if ((loop_repetation >= 3 || loop_repetation <= 20) && (loop_types != 'Q'))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }

    }
    printf("\n+--------------------+");
    printf("\nLoop application ENDED");
    printf("\n+--------------------+\n");
    
    return 0;
}
    