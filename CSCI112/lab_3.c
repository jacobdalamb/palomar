#include <stdio.h>
double celsius_at_depth(double depth, double celsius);
double fahrenheit(double celsius);
int main(void)
{
double depth, celsius;
printf("Enter the depth in kms to calculate the temperature> ");
scanf("%lf", &depth);
celsius = (10 * depth) + 20;
printf("At a depth of %.2fkms, the temperature in degrees Celsius is %.2f\n",
depth, celsius_at_depth(depth, celsius));
printf("At a depth of %.2fkms, the temperature in degrees Fahrenheit is %.2f",
depth, fahrenheit(celsius));
return (0);
}
double celsius_at_depth(double depth, double celsius)
{
return (celsius - 10 * depth) / 20;
}
double fahrenheit(double celsius)
{
return (1.8 * celsius) + 32;
}
