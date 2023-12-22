#include <stdio.h>
#include <string.h>

int main()
{
    char stack[20], ip[20], opt[10][10][2], ter[10];
    int i, j, k, n, top = 0, col, row;

    // Initialize stack and input
    for (i = 0; i < 10; i++)
    {
        stack[i] = ip[i] = '\0';
        for (j = 0; j < 10; j++)
        {
            opt[i][j][0] = opt[i][j][1] = '\0';
        }
    }

    printf("Enter the number of terminals:\n");
    scanf("%d", &n);

    printf("Enter the terminals:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", ter + i);
    }

    printf("Enter the table values:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the value for %c %c:", ter[i], ter[j]);
            scanf("%s", opt[i][j]);
        }
    }

    stack[top] = '$';
    printf("Enter the input string:\n");
    scanf("%s", ip);

    i = 0;

    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("%s\t\t\t%s\t\t\t", stack, ip);

    while (i <= strlen(ip))
    {
        col = row = -1;

        // Find column index for stack[top] and row index for ip[i]
        for (k = 0; k < n && (col == -1 || row == -1); k++)
        {
            if (stack[top] == ter[k])
            {
                col = k;
            }
            if (ip[i] == ter[k])
            {
                row = k;
            }
        }

        // Check if the string is accepted
        if (stack[top] == '$' && ip[i] == '$')
        {
            printf("String is accepted\n");
            break;
        }
        else if (opt[col][row][0] == '<' || opt[col][row][0] == '=')
        {
            stack[++top] = opt[col][row][0];
            stack[++top] = ip[i];
            printf("Shift %c", ip[i]);
            i++;
        }
        else
        {
            if (opt[col][row][0] == '>')
            {
                while (stack[top] != '<')
                {
                    --top;
                }
                top = top - 1;
                printf("Reduce");
            }
            else
            {
                printf("\nString is not accepted");
                break;
            }
        }

        printf("\n%s\t\t\t%s\t\t\t", stack, ip);
    }

    return 0;
}
