#include <stdio.h>

#define MAX 10

void main()
{
    char ele[MAX][MAX];
    int w[MAX][MAX], c[MAX][MAX], p[MAX], q[MAX];
    int temp, min, min1;
    int i, j, b, k, n;
    printf("Enter the elements : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the elemnts P(%d):", i);
        scanf("%d", &p[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the elemnts Q(%d):", i);
        scanf("%d", &q[i]);
    }
    printf("\n");
    printf("W\tC\t\tR\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
            {
                w[i][j] = q[i];
                c[i][j] = 0;
                printf("w[%d][%d] : %d\tc[%d][%d] : %d\tr[%d][%d] : %d\n", i, j, w[i][j], i, j, c[i][j], i, j, 0);
            }
        }
    }
    printf("\n");
    for (int b = 0; b < n; b++)
    {
        for (int i = 0, j = b + 1; j < n + 1 && i < n + 1; j++, i++)
        {
            if (i != j && i < j)
            {
                w[i][j] = w[i][j - 1] + p[i] + q[j];
                min = 3000;
                for (int k = i + 1; k <= j; k++)
                {
                    min1 = c[i][k - 1] + c[k][j] + w[i][j];
                    if (min > min1)
                    {
                        min = min1;
                        temp = k;
                    }
                    c[i][j] = min;
                }
            }
            printf("w[%d][%d] : %d \t c[%d][%d]: %d \t r[%d][%d] :%d\n", i, j, w[i][j], i, j, c[i][j], i, j, k - 1);
        }
        printf("\n");
    }
    printf("minimun cost:%d", c[0][n]);
}