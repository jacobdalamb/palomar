// reads color and displays corresponding gas
#include <stdio.h>
int main(void)
{
char gas; // input - indicates color of gas
// read first character of color
printf("Enter the color of the gas> ");
scanf("%c", &gas); // scan first letter
// display first character followed by gas
printf("The gas is %c: ", gas);
switch (gas)
{
case 'O':
case 'o':
printf("ammonia\n");
break;
case 'B':
case 'b':
printf("carbon monoxide\n");
break;
case 'Y':
case 'y':
printf("hydrogen\n");
break;
case 'G':
case 'g':
printf("oxygen\n");
break;
default:
printf("Contents unknown\n");
}
return (0);
}
