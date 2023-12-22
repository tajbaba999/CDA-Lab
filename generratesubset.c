#include <stdio.h>

void generatesubsets(int set[], int subset, int n, int index, int sum, int m)
{
    if (index == n)
    {
        if (sum == m)
        {
            printf("{") for (int i = 0; i < n; i++)
            {
                if (subset[i])
                {
                    printf("%d", set[i])
                }
            }
            printf("} sum %d\n", sum);
        }
        return;
    }

    generatesubsets(set, subset, n, index + 1, sum + set[index], m);
}

int main()
{
    int n;
    int m = 10;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int set[n];
    int subset[n];

    printf("Enter the number of sub : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
        subset[i] = 0;
    }

    printf("generate number of subbsets");
    generatesubsets(set, subset, n, 0, 0, m);
}