#include <stdio.h>
#include <stdlib.h>
typedef struct structure
{
int number;
char name[50];
char symbol[5];
float weight;
} element_t;
void print_element(FILE *fpBinary, FILE *fTxtOne, FILE *fpTxtTwo);
int main()
{
FILE *fpBinary;
FILE *fpTxtOne;
FILE *fpTxtTwo;
fpTxtOne = fopen("element_one.txt", "r");
fpTxtTwo = fopen("element_two.txt", "r");
fpBinary = fopen("binary.txt", "wb");
if (fpTxtOne == NULL || fpTxtTwo == NULL)
{
printf("Error reading file\n");
exit(1);
}
print_element(fpBinary, fpTxtOne, fpTxtTwo);
fclose(fpTxtOne);
fclose(fpTxtTwo);
return 0;
}
void print_element(FILE *fpBinary, FILE *fpTxtOne, FILE *fpTxtTwo)
{
element_t element_one, element_two;
while (fscanf(fpTxtOne, "%d%s%s%f", &element_one.number, element_one.name,
element_one.symbol, &element_one.weight) != EOF)
{
fflush(stdin);
}
fwrite(&element_one, sizeof(element_one), 1, fpBinary);
fclose(fpBinary);
fpBinary = fopen("binary.txt", "a");
while (fscanf(fpTxtTwo, "%d%s%s%f", &element_two.number, element_two.name,
element_two.symbol, &element_two.weight) != EOF)
{
fflush(stdin);
}
fclose(fpBinary);
fpBinary = fopen("binary.txt", "rb");
printf("%d\t%s\t%s\t%.2f\n", element_one.number, element_one.name,
element_one.symbol, element_one.weight);
printf("%d\t%s\t%s\t%.2f\n", element_two.number, element_two.name,
element_two.symbol, element_two.weight);
fclose(fpBinary);
}
