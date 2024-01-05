#include <stdio.h>

void generatesubsets(int set[], int subsets[], int n, int index, int sum, int m)
{
    if (index == n)
    {
        if (sum == m)
        {
            printf("{");
            for (int i = 0; i < n; i++)
            {
                if (subsets[i])
                {
                    printf("%d ", set[i]);
                }
            }
            printf("} Sum %d\n", sum);
        }
        return;
    }

    subsets[index] = 1;
    generatesubsets(set, subsets, n, index + 1, sum + set[index], m);

    subsets[index] = 0;
    generatesubsets(set, subsets, n, index + 1, sum, m);
}

int main()
{
    int n;
    int m = 10;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int set[n];
    int subsets[n];

    printf("Enter the elements in set: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
        subsets[i] = 0;
    }

    printf("Subsets and their sums:\n");
    generatesubsets(set, subsets, n, 0, 0, m);

    return 0;
}
