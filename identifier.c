#include <stdio.h>
#include <string.h>

int main()
{
    char kw[32][10] = {
        "int",
        "char",
        "float",
        "double",
    };
    printf("Enter the string :");
    char str[25];
    int cnt = 0, flag;
    scanf("%s", str);
    if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || (str[0] == '_'))
    {
        for (int i = 1; i < strlen(str); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') ||
                (str[i] >= 'A' && str[i] <= 'Z') ||
                (str[i] == '_') ||
                (str[i] >= 0 && str[i] <= 9))
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
        }
    }
    if (flag == 1)
    {
        printf("%s is not a identifier", str);
    }
    else
    {
        printf(" %s is ` a identifier\n", str);
    }
    return 0;
}