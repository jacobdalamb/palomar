#include <stdio.h>
int main(void)
{
int apples, bag, leftOver; // variables for apples, number of bags and number of apples left over
// Prompt for user input and get the number of apples available
printf("How many apples are available?> ");
scanf("%d", &apples);
bag = apples / 12;
leftOver = apples % 12;
// Display the results
printf("There are %d apples available, %d in each bag and %d left over",
apples, bag, leftOver);
return (0);
}
