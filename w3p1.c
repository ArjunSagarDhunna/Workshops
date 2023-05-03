/*
*****************************************************************************
                          Workshop - #3 (P1)
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
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
const double TAX = 0.13;
const char patSize = 'S';
double small, medium, large;
int psmall, pmedium, plarge, shirts, sub, tax, total;

printf("Set Shirt Prices\n");
printf("================\n");
printf("Enter the price for a SMALL shirt: $");
scanf("%lf", &small);
printf("Enter the price for a MEDIUM shirt: $");
scanf("%lf", &medium);
printf("Enter the price for a LARGE shirt: $");
scanf("%lf", &large);

printf("\n");

psmall = small * 100;
pmedium = medium * 100;
plarge = large * 100; 

printf("Shirt Store Price List\n");
printf("======================\n");
printf("SMALL  : $%.2lf\n", (double)psmall / 100);
printf("MEDIUM : $%.2lf\n", (double)pmedium / 100);
printf("LARGE  : $%.2lf\n", (double)plarge / 100);

printf("\n");

printf("Patty's shirt size is '%c'\n",patSize);
printf("Number of shirts Patty is buying: ");
scanf("%d", &shirts);
 
sub = psmall * shirts;
tax = ((sub * (TAX * 100)) + 50) / 100; 
total = (sub + tax);

printf("\nPatty's shopping cart...\n");
printf("Contains : %d shirts\n", shirts);
printf("Sub-total: $%8.4lf\n", (double)sub / 100);
printf("Taxes    : $%8.4lf\n",(double)tax / 100);
printf("Total    : $%8.4lf\n", (double)total / 100); 

return 0;
}*/

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
	tax = ((sub * (TAX * 100)) + 50)/100;
	total = (sub + tax);

	printf("Patty's shopping cart...");
	printf("\nContains :%d shirts", n);
	printf("\nSub-total: $%.4lf", (double)sub);
	printf("\nTaxes : $%3.4lf", (double)tax / 100);
	printf("\nTotal : $%.4lf", (double)total);
	return 0;
}