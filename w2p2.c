/*
*****************************************************************************
						  Workshop - #2 (P2)
Full Name  : ARJUN SAGAR DHUNNA
Student ID#: 157099219
Email      : adhunna@myseneca.ca
Section    : NCC

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
	// You will need this when converting from grams to pounds (lbs)
	const double GRAMS_IN_LBS = 453.5924;
	char type1, type2, type3, cream, strength, maker, grind1, grind2, grind3, best1, best2, best3;
	int weight1 = 0, weight2 = 0, weight3 = 0, serve = 0;
	float temp1 = 0, temp2 = 0, temp3 = 0;
	
	printf("Take a Break - Coffee Shop\n");
	printf("==========================\n\n");
	printf("Enter the coffee product information being sold today...\n\n");
	
	printf("COFFEE-1...\n");
	printf("Type ([L]ight,[B]lend): ");
	scanf("%c%*c", &type1);
	printf("Grind size ([C]ourse,[F]ine): ");
	scanf("%c%*c", &grind1);
	printf("Bag weight (g): ");
	scanf("%d%*c", &weight1);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf("%c%*c", &best1);
	printf("Ideal serving temperature (Celsius): ");
	scanf("%f%*c", &temp1);

	printf("\nCOFFEE-2...\n");
	printf("Type ([L]ight,[B]lend): ");
	scanf("%c%*c", &type2);
	printf("Grind size ([C]ourse,[F]ine): ");
	scanf("%c%*c", &grind2);
	printf("Bag weight (g): ");
	scanf("%d%*c", &weight2);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf("%c%*c", &best2);
	printf("Ideal serving temperature (Celsius): ");
	scanf("%f%*c", &temp2);

	printf("\nCOFFEE-3...\n");
	printf("Type ([L]ight,[B]lend): ");
	scanf("%c%*c", &type3);
	printf("Grind size ([C]ourse,[F]ine): ");
	scanf("%c%*c", &grind3);
	printf("Bag weight (g): ");
	scanf("%d%*c", &weight3);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf("%c%*c", &best3);
	printf("Ideal serving temperature (Celsius): ");
	scanf("%f%*c", &temp3);

	printf("\n---+---------------+---------------+---------------+-------+--------------\n");
	printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
	printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
	printf("   +---------------+---------------+---------------+ With  +--------------\n");
	printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
	printf("---+---------------+---------------+---------------+-------+--------------\n");
	
	printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",\
	((type1 == 'l') || (type1 == 'L')), ((type1 == 'b') || (type1 == 'B')), ((grind1 == 'c') || (grind1 == 'C')),\
	((grind1 == 'f') || (grind1 == 'F')), weight1, (weight1 / GRAMS_IN_LBS), ((best1 == 'y') || (best1 == 'Y')),\
	temp1, (temp1 * 1.8) + 32);
	
	printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", \
	((type2 == 'l') || (type2 == 'L')), ((type2 == 'b') || (type2 == 'B')), ((grind2 == 'c') || (grind2 == 'C')), \
	((grind2 == 'f') || (grind2 == 'F')), weight2, (weight2 / GRAMS_IN_LBS), ((best2 == 'y') || (best2 == 'Y')), \
	temp2, (temp2 * 1.8) + 32);

	printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n\n", \
	((type3 == 'l') || (type3 == 'L')), ((type3 == 'b') || (type3 == 'B')), ((grind3 == 'c') || (grind3 == 'C')), \
	((grind3 == 'f') || (grind3 == 'F')), weight3, (weight3 / GRAMS_IN_LBS), ((best3 == 'y') || (best3 == 'Y')), \
	temp3, (temp3 * 1.8) + 32);
	
	printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
	
	
	printf("Coffee strength ([M]ild,[R]ich): ");
	scanf("%c%*c",&strength);
	printf("Do you like your coffee with cream ([Y]es,[N]o): ");
	scanf("%c%*c",&cream);
	printf("Typical number of daily servings: ");
	scanf("%d%*c",&serve);
	printf("Maker ([R]esidential,[C]ommercial): ");
	scanf("%c%*c",&maker);
	
	printf("\nThe below table shows how your preferences align to the available products:\n\n");
	
	printf("--------------------+--------------------+-------------+-------+--------------\n");
	printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
	printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
	printf("--+-----------------+--------------------+-------------+-------+--------------\n");

	printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",\

		((strength == 'm' || strength == 'M') && (type1 == 'l' || type1 == 'L')) || ((strength == 'r' || strength == 'R') && (type1 == 'b' || type1 == 'B')),
		((maker == 'c' || maker == 'C') && (grind1 == 'f' || grind1 == 'F')) || ((maker == 'r' || maker == 'R') && (grind1 == 'c' || grind1 == 'C')),
		((serve >= 1 && serve <= 4) && (weight1 >= 0 && weight1 <= 250)) || ((serve >= 5 && serve <= 9) && (weight1 >= 251 && weight1 <= 500)) || ((serve >= 10) && (weight1 >= 501 && weight1 <= 1000)),
		((cream == 'y' || cream == 'Y') && (best1 == 'y' || best1 == 'Y')) || ((cream == 'n' || cream == 'N') && (best1 == 'n' || best1 == 'N')),
		((maker == 'c' || maker == 'C') && (temp1 >= 70.0 && temp1 <= 80.5)) || ((maker == 'r' || maker == 'R') && (temp1 >= 0 && temp1 <= 250)));
	
	printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",\

		((strength == 'm' || strength == 'M') && (type2 == 'l' || type2 == 'L')) || ((strength == 'r' || strength == 'R') && (type2 == 'b' || type2 == 'B')),
		((maker == 'c' || maker == 'C') && (grind2 == 'f' || grind2 == 'F')) || ((maker == 'r' || maker == 'R') && (grind2 == 'c' || grind2 == 'C')),
		((serve >= 1 && serve <= 4) && (weight2 >= 0 && weight2 <= 250)) || ((serve >= 5 && serve <= 9) && (weight2 >= 251 && weight2 <= 500)) || ((serve >= 10) && (weight2 >= 501 && weight2 <= 1000)),
		((cream == 'y' || cream == 'Y') && (best2 == 'y' || best2 == 'Y')) || ((cream == 'n' || cream == 'N') && (best2 == 'n' || best2 == 'N')),
		((maker == 'c' || maker == 'C') && (temp2 >= 70.0 && temp2 <= 80.5)) || ((maker == 'r' || maker == 'R') && (temp2 >= 60.0 && temp2 <= 69.9)));

	printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n",\

		((strength == 'm' || strength == 'M') && (type3 == 'l' || type3 == 'L')) || ((strength == 'r' || strength == 'R') && (type3 == 'b' || type3 == 'B')),
		((maker == 'c' || maker == 'C') && (grind3 == 'f' || grind3 == 'F')) || ((maker == 'r' || maker == 'R') && (grind3 == 'c' || grind3 == 'C')),
		((serve >= 1 && serve <= 4) && (weight3 >= 0 && weight3 <= 250)) || ((serve >= 5 && serve <= 9) && (weight3 >= 251 && weight3 <= 500)) || ((serve >= 10) && (weight3 >= 501 && weight3 <= 1000)),
		((cream == 'y' || cream == 'Y') && (best3 == 'y' || best3 == 'Y')) || ((cream == 'n' || cream == 'N') && (best3 == 'n' || best3 == 'N')),
		((maker == 'r' || maker == 'R') && (temp3 >= 60.0 && temp3 <= 60.9)) || ((maker == 'c' || maker == 'C') && (temp3 >= 70.0 && temp3 <= 80.5)));


	printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
	
	printf("Coffee strength ([M]ild,[R]ich): ");
	scanf("%c%*c", &strength);
	printf("Do you like your coffee with cream ([Y]es,[N]o): ");
	scanf("%c%*c", &cream);
	printf("Typical number of daily servings: ");
	scanf("%d%*c", &serve);
	printf("Maker ([R]esidential,[C]ommercial): ");
	scanf("%c%*c", &maker);
	
	printf("\nThe below table shows how your preferences align to the available products:\n\n");
	
	printf("--------------------+--------------------+-------------+-------+--------------\n");
	printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
	printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
	printf("--+-----------------+--------------------+-------------+-------+--------------\n");
	printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", \

		((strength == 'm' || strength == 'M') && (type1 == 'l' || type1 == 'L')) || ((strength == 'r' || strength == 'R') && (type1 == 'b' || type1 == 'B')),
		((maker == 'c' || maker == 'C') && (grind1 == 'f' || grind1 == 'F')) || ((maker == 'r' || maker == 'R') && (grind1 == 'c' || grind1 == 'C')),
		((serve >= 1 && serve <= 4) && (weight1 >= 0 && weight1 <= 250)) || ((serve >= 5 && serve <= 9) && (weight1 >= 251 && weight1 <= 500)) || ((serve >= 10) && (weight1 >= 501 && weight1 <= 1000)),
		((cream == 'y' || cream == 'Y') && (best1 == 'y' || best1 == 'Y')) || ((cream == 'n' || cream == 'N') && (best1 == 'n' || best1 == 'N')),
		((maker == 'c' || maker == 'C') && (temp1 >= 70.0 && temp1 <= 80.5)) || ((maker == 'r' || maker == 'R') && (temp1 >= 0 && temp1 <= 250)));

	printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", \
	
		((strength == 'm' || strength == 'M') && (type2 == 'l' || type2 == 'L')) || ((strength == 'r' || strength == 'R') && (type2 == 'b' || type2 == 'B')),
		((maker == 'c' || maker == 'C') && (grind2 == 'f' || grind2 == 'F')) || ((maker == 'r' || maker == 'R') && (grind2 == 'c' || grind2 == 'C')),
		((serve >= 1 && serve <= 4) && (weight2 >= 0 && weight2 <= 250)) || ((serve >= 5 && serve <= 9) && (weight2 >= 251 && weight2 <= 500)) || ((serve >= 10) && (weight2 >= 501 && weight2 <= 1000)),
		((cream == 'y' || cream == 'Y') && (best2 == 'y' || best2 == 'Y')) || ((cream == 'n' || cream == 'N') && (best2 == 'n' || best2 == 'N')),
		((maker == 'c' || maker == 'C') && (temp2 >= 70.0 && temp2 <= 80.5)) || ((maker == 'r' || maker == 'R') && (temp2 >= 60.0 && temp2 <= 69.9)));

	printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", \
	
		((strength == 'm' || strength == 'M') && (type3 == 'l' || type3 == 'L')) || ((strength == 'r' || strength == 'R') && (type3 == 'b' || type3 == 'B')),
		((maker == 'c' || maker == 'C') && (grind3 == 'f' || grind3 == 'F')) || ((maker == 'r' || maker == 'R') && (grind3 == 'c' || grind3 == 'C')),
		((serve >= 1 && serve <= 4) && (weight3 >= 0 && weight3 <= 250)) || ((serve >= 5 && serve <= 9) && (weight3 >= 251 && weight3 <= 500)) || ((serve >= 10) && (weight3 >= 501 && weight3 <= 1000)),
		((cream == 'y' || cream == 'Y') && (best3 == 'y' || best3 == 'Y')) || ((cream == 'n' || cream == 'N') && (best3 == 'n' || best3 == 'N')),
		((maker == 'r' || maker == 'R') && (temp3 >= 60.0 && temp3 <= 60.9)) || ((maker == 'c' || maker == 'C') && (temp3 >= 70.0 && temp3 <= 80.5)));

	printf("Hope you found a product that suits your likes!\n");
	return 0;
}