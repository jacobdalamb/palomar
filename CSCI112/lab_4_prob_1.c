#include <stdio.h>
#include <math.h>
int main(void)
{
double weight, height, bmi;
printf("Enter your weight in pounds> ");
scanf("%lf", &weight);
printf("Enter your height in inches> ");
scanf("%lf", &height);
bmi = (703 * weight) / pow(height, 2);
printf("Your BMI is %.2f\n", bmi);
if (bmi < 18.5)
printf("You are underweight\n");
else if (bmi > 18.5 && bmi < 24.9)
printf("You are normal\n");
else if (bmi > 25.0 && bmi < 29.9)
printf("You are overweight");
else if (bmi >= 30.0)
printf("You are obese");
}
