#include <stdio.h>

void knapack(int num, float weight[], float profit[], float ratio[], float capacity)
{
    float tp = 0;
    int i;
    int u = capacity;
    for (i = 0; i < num; i++)
    {
        if (weight[i] > u)
        {
            break;
        }
        else
        {
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }
    if (i < num)
    {
        tp = tp + (u / weight[i] * profit[i]);
        printf("Maximum profit generated: %.2f\n", tp);
    }
}

int main()
{
    float weight[20], profit[20], capacity, ratio[10], temp;
    int i, j;
    int num = 5;
    printf("Enter the number of weights: ");
    for (i = 0; i < num; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);
    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    knapack(num, weight, profit, ratio, capacity);
    return 0;
}
