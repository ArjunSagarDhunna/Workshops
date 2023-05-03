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
#include <stdio.h>

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year = 0, mnth = 0;
    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%*c %d%*c", &year, &mnth);
        if (year < MIN_YEAR || year > MAX_YEAR)
        printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        
        if (mnth < JAN || mnth > DEC)
        printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        
    } while ((year<MIN_YEAR || year>MAX_YEAR) || (mnth<JAN || mnth>DEC));
    printf("\n*** Log date set! ***\n\nLog starting date: %d",year);
    switch (mnth)
    {
    case 1: printf("-JAN-01\n");break;
    case 2: printf("-FEB-01\n");break;
    case 3: printf("-MAR-01\n");break;
    case 4: printf("-APR-01\n");break;
    case 5: printf("-MAY-01\n");break;
    case 6: printf("-JUN-01\n");break;
    case 7: printf("-JUL-01\n");break;
    case 8: printf("-AUG-01\n");break;
    case 9: printf("-SEP-01\n");break;
    case 10: printf("-OCT-01\n");break;
    case 11: printf("-NOV-01\n");break;
    case 12: printf("-DEC-01\n");break;
    }

    return 0;
}