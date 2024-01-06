#include <stdio.h>
#include <string.h>
int size_of_grid, b, a, cnt = 0;
int arr[128][128];
void place(int x1, int y1, int x2, int y2, int x3, int y3)
{
    cnt++;
    arr[x1][y1] = cnt;
    arr[x2][y2] = cnt;
    arr[x3][y3] = cnt;
}
int tile(int n, int x, int y)
{
    int r, c;
    if (n == 2)
    {
        cnt++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[x + i][y + j] == 0)
                {
                    arr[x + i][y + j] = cnt;
                }
            }
        }
        return 0;
    }
    // finding hole location
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (arr[i][j] != 0)
                r = i, c = j;
        }
    }
    if (r < x + n / 2 && c < y + n / 2)
        place(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2);
    else if (r >= x + n / 2 && c < y + n / 2)
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);
    else if (r < x + n / 2 && c >= y + n / 2)
        place(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2 - 1);
    else if (r >= x + n / 2 && c >= y + n / 2)
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1);
    tile(n / 2, x, y + n / 2);
    tile(n / 2, x, y);
    tile(n / 2, x + n / 2, y);
    tile(n / 2, x + n / 2, y + n / 2);
    return 0;
}
int main()
{
    printf("Enter the size of grid:\n");
    scanf("%d", &size_of_grid);
    memset(arr, 0, sizeof(arr));
    printf("Enter the coordinates where tile cant be placed\n");
    scanf("%d %d", &a, &b);
    arr[a][b] = -1;
    tile(size_of_grid, 0, 0);
    for (int i = 0; i < size_of_grid; i++)
    {
        for (int j = 0; j < size_of_grid; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}