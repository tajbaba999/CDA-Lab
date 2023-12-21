#include <stdio.h>
#define MAX 10

int main()
{
    char ele[MAX][MAX];
    int w[MAX][MAX], c[MAX][MAX], p[MAX], q[MAX];
    int temp, min, min1;
    int i, j, k, b, n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input probabilities for the elements P(i)
    for (i = 1; i <= n; i++)
    {
        printf("Enter the probability P(%d): ", i);
        scanf("%d", &p[i]);
    }

    printf("\n");

    // Input probabilities for the imaginary elements q(i)
    for (i = 0; i <= n; i++)
    {
        printf("Enter the probability q(%d): ", i);
        scanf("%d", &q[i]);
    }

    printf("\n");

    printf("W \t\t C \t\t R\n");

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                w[i][j] = q[i];
                c[i][j] = 0;
                printf("w[%d][%d] : %d \t c[%d][%d]: %d \t r[%d][%d] : %d\n", i, j, w[i][j], i, j, c[i][j], i, j, 0);
            }
        }
    }
    printf("\n");

    for (int b = 0; b < n; b++)
    {
        for (int i = 0, j = b + 1; j <= n && i <= n; j++, i++)
        {
            if (i != j && i < j)
            {
                w[i][j] = w[i][j - 1] + p[i] + q[j];
                min = 3000;

                for (int k = i + 1; k <= j; j++)
                {
                    min1 = c[i][j - 1] + c[k][j] + w[i][j];
                    if (min > min1)
                    {
                        min = min1;
                        temp = k;
                    }
                }

                c[i][j] = min;
            }
            printf("\nw[%d][%d] : %d \t c[%d][%d]: %d \t r[%d][%d] : %d",
                   i, j, w[i][j], i, j, c[i][j], i, j, temp - 1);
        }
        printf("\n");
    }
    printf("Minimum cost: %d\n", c[0][n]);
}