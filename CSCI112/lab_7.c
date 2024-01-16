#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
void fgetAnswers();
int main(void)
{
FILE *inp;
FILE *outp;
int answerKey, id, test, missed[50] = {}, score, numOfID;
float numOfQuestions, percentage;
char answers[50], studentAnswer[50];
inp = fopen("examdat.txt", "r");
outp = fopen("report.txt", "w");
answerKey = fscanf(inp, "%f %s", &numOfQuestions, answers);
fprintf(outp, "Answer Key\n");
fprintf(outp, "Question\t");
for (int i = 0; i < numOfQuestions; i++)
{
fprintf(outp, "%d\t", i + 1);
}
fprintf(outp, "\nAnswer \t");
for (int i = 0; i < numOfQuestions; i++)
{
fprintf(outp, "%c\t", answers[i]);
}
fprintf(outp, "\nID \tScore\n");
test = fscanf(inp, "%d %s", &id, studentAnswer);
while (test != EOF)
{
percentage = 100.00;
score = numOfQuestions;
for (int i = 0; i < numOfQuestions; i++)
{
if (studentAnswer[i] != answers[i])
{
missed[i]++;
score--;
percentage = (score / numOfQuestions) * 100;
}
}
fprintf(outp, "%d \t%.2f%%\n", id, percentage);
test = fscanf(inp, "%d %s", &id, studentAnswer);
}
fprintf(outp, "Question\t");
for (int i = 0; i < numOfQuestions; i++)
{
fprintf(outp, "%d\t", i + 1);
}
fprintf(outp, "\nMissed by \t");
for (int i = 0; i < numOfQuestions; i++)
{
fprintf(outp, "%d \t", missed[i]);
}
fclose(inp);
fclose(outp);
return (0);
}
void fgetAnswers()
{
}
