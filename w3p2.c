#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define LOT_SIZE 15
#define COLOUR_MIN 0
#define COLOUR_MAX 2

int main(void)
{
    // C=car, P=pick-up, M=motorcycle, [any other value: n/a]
    char vehicleType[LOT_SIZE] = { 'M','C','P','P','C',
                                   'C','P','?','P','P',
                                   'M','?','M','M','C' };
    // 0=black, 1=white, 2=blue, [any other value: other]
    int colourCode[LOT_SIZE] = { 1,  2,  1,  0,  0,
                                 1,  2, -4,  2,  0,
                                 0, 99,  2,  1,  2 };
    // Positive value contains a vehicle
    int parkingSpot[LOT_SIZE] = { 373, 163, 413, 253, 463,
                                  283, 183,  -1, 333, 503,
                                  253,   0, 423, 173, 223 };
    // Estimated black book value
    double estValue[LOT_SIZE] = { 81005.0,  9332.0, 36925.0,     0.0, 63255.0,
                                   8905.0, 86095.0,     0.0, 94005.0, 12035.0,
                                  24075.0,     0.0, 10050.0, 15025.0, 46905.0 };

    int i = 0, querying = 1, qryColour, qrySpot, matches;
    double minValue, totalValue;

    printf("Current Parking Lot Data\n"
        "========================\n\n");

    do {
        if (parkingSpot[i] > 0)
        {
            printf("Spot#:%3d ", parkingSpot[i]);

            switch (vehicleType[i])
            {
            case 'P':
                printf("PICK-UP    ");
                break;
            case 'C':
                printf("CAR        ");
                break;
            case 'M':
                printf("MOTORCYCLE ");
                break;
            }

            if (colourCode[i] == 0)
            {
                printf("(black) ");
            }
            else if (colourCode[i] == 1)
            {
                printf("(white) ");
            }
            else if (colourCode[i] == 2)
            {
                printf("(blue)  ");
            }
            else
            {
                printf("(other) ");
            }
            printf(" Est:$%9.2lf\n", estValue[i]);
        }

        i++;

    } while (i < LOT_SIZE);

    while (querying)
    {
        printf("\n"
            "Search Parking Lot by Vehicle Attribute\n"
            "---------------------------------------\n\n");
        printf("Match by COLOUR OR SPOT#...\n");
        printf("COLOUR OPTIONS: 0=black, 1=white, 2=blue, [any other value=other]\n");
        printf("\tVehicle Colour: ");
        scanf("%d", &qryColour);
        printf("\tParking Spot# : ");
        scanf("%d", &qrySpot);

        printf("\n"
            "Results:\n");
        printf("============================\n");
        printf("Spot#'s    : ");

        totalValue = estValue[0];
        matches = 0;
        i = 0;

        for (i = 0; i < LOT_SIZE; i++)
        {
            if (parkingSpot[i] > 0)
            {
                if ((colourCode[i] == qryColour ||
                    ((qryColour < COLOUR_MIN || qryColour > COLOUR_MAX) &&
                        (colourCode[i] < COLOUR_MIN || colourCode[i] > COLOUR_MAX))) &&
                    parkingSpot[i] == qrySpot)
                {
                    printf("%d ", parkingSpot[i]);
                    totalValue += estValue[i];
                    matches++;
                    i++;
                }
            }
        }

        if (!matches)
        {
            printf("---\n"
                "<NO RESULTS FOUND>\n\n");
        }
        else
        {
            printf("\n"
                "Matches found: %d\n"
                "Total Value  : $%9.2lf\n\n", matches, totalValue);
        }

        printf("Make another query? (0=no): ");
        scanf("%d", &querying);
    }

    return 0;
}