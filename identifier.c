#include <stdio.h>
#include <string.h>

int main()
{
    char kw[32][10] = {"auto", "double", "int", "struct", "break", "else", "long", "Switch", "case", "enum", "register", "typedef", "char", "extern", "Return", "union", "const", "float", "short", "unsigned", "continue", "For", "signed", "void", "default", "goto", "sizeof", "volatile", "Do", "if", "static", "while"};

    char str[25];
    int cnt = 0, flag = 0;
    printf("Enter a string \n");
    scanf("%s", str);

    if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_')
    {
        for (int i = 1; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ||
                (str[i] == '_') || (str[i] >= '0' && str[i] <= '9'))
            {
                cnt++;
            }
        }
    }

    for (int i = 0; i < 32; i++)
    {
        if (strcmp(str, kw[i]) == 0)
        {
            flag = 1;
            break; // No need to continue checking if the keyword is found
        }
    }

    if (flag == 1 || cnt != strlen(str) - 1)
    {
        printf("Given identifier is not valid\n");
    }
    else
    {
        printf("Given identifier is valid\n");
    }

    return 0;
}
