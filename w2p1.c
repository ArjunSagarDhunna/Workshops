#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    const double testValue = 330.99;
    const int prodID1 = 111, prodID2 = 222, prodID3 = 111;
    char taxed1 = 'Y', taxed2 = 'N', taxed3 = 'N';
    double price1 = 111.49, price2 = 222.99, price3 = 334.49;
    
    printf("Product Information\n===================\n");
    printf("Product-1 (ID:%d)\n", prodID1);
    printf("  Taxed: %c\n", taxed1);
    printf("  Price: $%.4lf\n\n", price1);
    printf("Product-2 (ID:%d)\n", prodID2);
    printf("  Taxed: %c\n", taxed2);
    printf("  Price: $%.4lf\n\n", price2);
    printf("Product-3 (ID:%d)\n", prodID3);
    printf("  Taxed: %c\n", taxed3);
    printf("  Price: $%.4lf\n\n", price3);
    printf("The average of all prices is: $%.4lf\n\n", (price1 + price2 + price3)/3);
    printf("About Relational and Logical Expressions!\n========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    printf("Some Data Analysis...\n=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", taxed1=='Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n",taxed2=='N' && taxed3=='N');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, price3<testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", price3>(price1&&price2));
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n",price1>=(price3-price2), price3 - price2);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n",price2>=((price1 + price2 + price3) / 3));
    printf("7. Based on product ID, product 1 is unique -> %d\n\n",prodID1 == (prodID2 || prodID3));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n",prodID2 != (prodID3 || prodID1));
    printf("9. Based on product ID, product 3 is unique -> %d\n\n",prodID3 == (prodID2 || prodID1));
    return 0;
}