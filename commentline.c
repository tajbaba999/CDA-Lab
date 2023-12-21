#include <stdio.h>

int main()
{
    char s[20];
    int val;
    printf("Enter the string:");
    scanf("%s", s);
    if (s[0] == '/' && s[1] == '/')
    {
        val = 1;
    }
    if ((s[0] == '/' && s[1] == '*') && (s[strlen(s) - 1] == '/' && s[strlen(s) - 2] == '*'))
    {
        val = 1;
    }
    if (val == 1)
        printf("%s is a comment line \n", s);
    else
        printf("%s is not a comment line \n", s);
    return 0;
}