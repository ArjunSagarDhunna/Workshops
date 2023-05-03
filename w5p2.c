/*
*****************************************************************************
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
#include <stdio.h>

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year = 0, mnth = 0, day ;
    double mrng = 0,eve = 0, mrng_total = 0, eve_total = 0, total = 0;
    printf("General Well-being Log\n");
    printf("======================\n");
    
    for ( ; ; )
    {
        for ( ; ; )
        {
            printf("Set the year and month for the well-being log (YYYY MM): ");
            scanf("%d%*c %d%*c", &year, &mnth);

            if (year < MIN_YEAR || year > MAX_YEAR)
            {
                printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            }

            if (mnth < JAN || mnth > DEC)
            {
                printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
            }

            if (year <= MAX_YEAR && year >= MIN_YEAR && mnth <= DEC && mnth >= JAN)
            {
                printf("\n*** Log date set! ***\n");
                break;

            }
        }
        for (day=1; day <= LOG_DAYS; day++)
        {
            if (mnth == 1)
                printf("\n%d-JAN-0%d\n",year, day);
            else if (mnth == 2)
                printf("\n%d-FEB-0%d\n", year, day);
            else if (mnth == 3)
                printf("\n%d-MAR-0%d\n", year, day);
            else if (mnth == 4)
                printf("\n%d-APR-0%d\n", year, day);
            else if (mnth == 5)
                printf("\n%d-MAY-0%d\n", year, day);
            else if (mnth == 6)
                printf("\n%d-JUN-0%d\n", year, day);
            else if (mnth == 7)
                printf("\n%d-JUL-0%d\n", year, day);
            else if (mnth == 8)
                printf("\n%d-AUG-0%d\n", year, day);
            else if (mnth == 9)
                printf("\n%d-SEP-0%d\n", year, day);
            else if (mnth == 10)
                printf("\n%d-OCT-0%d\n", year, day);
            else if (mnth == 11)
                printf("\n%d-NOV-0%d\n", year, day);
            else if (mnth == 12)
                printf("\n%d-DEC-0%d\n", year, day);
            for (mrng = 0; mrng >= 0 || mrng <= 5; )
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mrng);
                if (mrng < 0 || mrng > 5)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else
                {
                    mrng_total += mrng;
                    break;
                }
            }
            for (eve = 0; eve >= 0 || eve <= 5; )
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eve);
                if (eve < 0 || eve > 5)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else
                {
                    eve_total += eve;
                    break;
                }
            }
        }
        printf("\nSummary\n=======\n");
        printf("Morning total rating: %4.3lf", mrng_total);
        printf("\nEvening total rating:  %4.3lf", eve_total);
        printf("\n----------------------------");
        printf("\nOverall total rating: %4.3lf", mrng_total + eve_total);

        printf("\n\nAverage morning rating: %4.1lf", mrng_total / LOG_DAYS);
        printf("\nAverage evening rating: %4.1lf", eve_total / LOG_DAYS);
        printf("\n----------------------------");
        total = ((mrng_total / LOG_DAYS) + (eve_total / LOG_DAYS)) / 2;
        printf("\nAverage overall rating: %4.1lf", total);
        printf("\n");
        break;
    }
            
    return 0;
}