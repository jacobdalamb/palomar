#include <stdio.h>
int main(void)
{
FILE *output;
int price, tens, twenties, fifties;
output = fopen("MoneyReceipt.txt", "w");
printf("\nEnter amount (only numbers divisible by 10): ");
scanf("%d", &price);
printf("Amount Requested: $%d\n", price);
fprintf(output, "Amount Requested: $%d\n", price);
if (((price % 10) == 0) && (price > 0))
{
if (price >= 50)
{
fifties = price / 50;
price = price % 50;
printf("Bill Amount: $50\t Quanity: %d\n", fifties);
fprintf(output, "Bill Amount: $50\t Quanity: %d\n", fifties);
}
if ((price >= 20) && (price < 50))
{
twenties = price / 20;
price = price % 20;
printf("Bill Amount: $20\t Quanity: %d\n", twenties);
fprintf(output, "Bill Amount: $20\t Quanity: %d\n", twenties);
}
if (price == 10)
{
tens = 1;
price = price % 10;
printf("Bill Amount: $10\t Quanity: %d\n", tens);
fprintf(output, "Bill Amount: $20\t Quanity: %d\n", twenties);
}
}
else
{
printf("Invalid request, enter amount desired in multiples of $10");
}
fclose(output);
return (0);
}
