#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
struct element_t
{
int number;
char name[50];
char symbol[5];
char class[25];
float weight;
int electrons[7];
};
struct element_t scan_element();
void print_element(struct element_t r);
int main()
{
struct element_t w;
w = scan_element();
print_element(w);
return 0;
}
struct element_t scan_element()
{
struct element_t w1;
printf("Enter element number: ");
scanf("%d", &w1.number);
printf("Enter element name: ");
scanf("%s", w1.name);
printf("Enter element symbol: ");
scanf("%s", w1.symbol);
printf("Enter element class: ");
scanf("%s", w1.class);
printf("Enter atomic weight: ");
scanf("%f", &w1.weight);
printf("Enter the number of electrons in each shell:\n");
for (int i = 0; i < 7; i++)
{
scanf("%d", &w1.electrons[i]);
}
return w1;
}
void print_element(struct element_t r)
{
printf("%d\t%s\t%s\t%s\t%f\t", r.number, r.name, r.symbol, r.class, r.weight);
for (int i = 0; i < 7; i++)
{
printf("%d ", r.electrons[i]);
}
}
