#include <stdio.h>
#include <stdlib.h>

int main()
{
int columns, rows, id, hours, overTimeHours, count_emp, number_emp;
float tax, net, gross, rate, total_net, average_net;
printf("Enter number of employees: ");
scanf("%d", &number_emp);
total_net = 0.0;
for (columns = 1; columns <= 1; columns++)
{
for (count_emp = 0; count_emp < number_emp; count_emp += 1)
{
printf("\nWhat is your id number? ");
scanf("%d", &id);
printf("What is your hourly wage? $");
scanf("%f", &rate);
printf("How many hours did you work for? ");
scanf("%d", &hours);
if (hours > 40)
{
overTimeHours = hours % 40;
gross = (rate * 40) + (rate * 1.5 * overTimeHours);
}
else
{
gross = rate * hours;
}
tax = gross * 3.625 / 100;
net = gross - tax;
printf("\nID: %d Gross Pay: $%.2f Taxes: $%.2f Net Pay: $%.2f\n", id, gross, tax, net);
total_net = total_net + net;
average_net = total_net / number_emp;
}
printf("\nTotal: $%.2f Average: $%.2f\n", total_net, average_net);
}
return 0;
}
