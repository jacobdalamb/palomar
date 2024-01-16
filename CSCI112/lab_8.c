#include <string.h>
#include <ctype.h>
#include <stdio.h>
void reversestringfunction(char input[], char output[]);
void palindromefunction(char orginalInput[], char upperInput[], char
upperReverseInput[]);
int main(void)
{
char inputString[20], upperString[20], upperReverseString[20];
char userinput;
do
{
printf("Enter a word - up to 20 characters:\n");
gets(inputString);
int count;
for (count = 0; count <= strlen(inputString); count++)
{
upperString[count] = toupper(inputString[count]);
}
upperString[count] = '\0';
reversestringfunction(upperString, upperReverseString);
printf("\n%s uppercase is %s and %s is the reverse\n", inputString,
upperString, upperReverseString);
palindromefunction(inputString, upperString, upperReverseString);
printf("\n\nEnter another set of data: Y or N? ");
userinput = toupper(getchar());
getchar();
} while (userinput != 'N');
}
void reversestringfunction(char input[], char output[])
{
int count = 0;
for (int i = strlen(input) - 1; i >= 0; i--)
{
output[count] = input[i];
count++;
}
output[count] = '\0';
}
void palindromefunction(char orginalInput[], char upperInput[], char
upperReverseInput[])
{
int count = 0;
for (int i = 0; i <= strlen(orginalInput); i++)
{
if (upperInput[i] != upperReverseInput[i])
    {
    count++;
    }
    }
    if (count > 0)
    {
    printf("%s is not a palindrome", orginalInput);
    }
    else
    {
    printf("%s is a palindrome", orginalInput);
    }
    }
