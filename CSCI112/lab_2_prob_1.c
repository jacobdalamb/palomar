#include <stdio.h>
#define RATE 0.35 // Constant to store the value of the reimbursement rate
int main(void)
{
    double startMiles, endMiles, distance, reimbursement;
    // variables for starting and ending odometer readings, distance between the odometer readings andreimbursement
    // Prompt for user input and get starting odometer reading
    printf("Enter the starting odometer reading> ");
    scanf("%lf", &startMiles);
    // Prompt for user input and get ending odometer reading
    printf("Enter the ending odometer reading> ");
    scanf("%lf", &endMiles);
    // Calculate the distance
    distance = endMiles - startMiles;
    // Compute the rate of reimbursement
    reimbursement = distance * RATE;
    // Display the results, format it to 2 precision
    printf("The total distance traveled is %.2f miles.\n", distance);
    printf("At $0.35 reimbursement rate per mile, the total reimbursement is $%.2f.", reimbursement);
return (0); }
