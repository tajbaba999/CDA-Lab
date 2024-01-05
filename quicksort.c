#include <stdio.h>
#include <time.h>
void quicksort(int number[25], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}
int main()
{
    int i, count, number[25];
    printf("SIZE OF ARRAY: ");
    scanf("%d", &count);
    // printf("Enter array elements: ");
    for (i = 0; i < count; i++)
        number[i] = count - i;
    clock_t t = clock();
    quicksort(number, 0, count - 1);
    t = clock() - t;
    printf("Time taken: %f \n", ((float)t * 1000) / CLOCKS_PER_SEC);
    printf("Sorted elements: ");
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);
    printf("\n");
    return 0;
}