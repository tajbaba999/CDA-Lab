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
    scanf("%s", &str);
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(str, kw[i]) == 0)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("%s is a keyword", str);
    }
    else
    {
        printf(" %s is not a keyword\n", str);
    }
    return 0;
}