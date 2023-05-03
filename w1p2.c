/*#include "fundamentals.h"

void fundamentals()	
{
	printf("*** Start of Indexing Strings Demo ***\n");
	char buffer1[80];
	char num_input[10];//initialization
	int position;//initialization
	while (TRUE)
	{
		printf("Type a string (q - to quit):\n");
		gets(buffer1);
		if (strcmp(buffer1, "q") == 0) break;
		while (TRUE)
		{
			printf("Type the character position within the string:\n");
			gets(num_input);
			position = atoi(num_input);
			// if will handle case where limit will be exceeded by the user via input.
			if (position >= strlen(buffer1))
			{
				printf("Wrong position... type again, please\n");
				continue;
			}
			
			printf("The character found at %d position is \'%c\'\n", position, buffer1[position]);
			break;
		}
	}
	printf("*** End of Indexing Strings Demo ***\n\n");
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double a, b, c;
	const double TAX = 0.13;
	int small, medium, large, n, tax, total, sub;
	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $"); //input value of small shirt in decimal
	scanf("%lf", &a);

	printf("Enter the price for a MEDIUM shirt: $"); //input value of med shirt in decimal
	scanf("%lf", &b);

	printf("Enter the price for a LARGE shirt: $"); //input value of large shirt in decimal
	scanf("%lf", &c);

	small = a * 100;								//converting decimal into integer
	medium = b * 100;								//converting decimal into integer
	large = c * 100;								//converting decimal into integer

	printf("Shirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2lf\n", (double)small / 100);	//converting same integer into decimal
	printf("MEDIUM : $%.2lf\n", (double)medium / 100);	//converting same integer into decimal
	printf("LARGE  : $%.2lf\n\n", (double)large / 100);	//converting same integer into decimal
	printf("Patty's shirt size is 'S'\n");
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &n);

	sub = a * n;
	tax = ((sub * (TAX * 100)) + 50) / 100;
	total = (sub + tax);

	printf("Patty's shopping cart...");
	printf("\nContains :%d shirts", n);
	printf("\nSub-total: $%.4lf", (double)sub);
	printf("\nTaxes : $%3.4lf", (double)tax / 100);
	printf("\nTotal : $%.4lf", (double)total);
	return 0;
}