// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void main()
{
    int i, iden = 0, operators = 0, numbers = 0;
    char s[30];
    printf("enter equation\n");
    fflush(stdout);
    scanf("%s", &s);
    for (i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        if (isalpha(ch))
        {
            printf("%c is identifier\n", ch);
            iden++;
        }
        else if (isdigit(ch))
        {
            printf("%c is integer\n", ch);
            numbers++;
        }
        else
        {
            printf("%c is operator\n", ch);
            operators++;
        }
    }
    printf("no of identifiers:%d\n", iden);
    printf("no of integers:%d\n", numbers);
    printf("no of opertors:%d\n", operators);
    printf("no of tokens:%d\n", iden + operators + numbers);
}