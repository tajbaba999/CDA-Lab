#include <stdio.h>
#include <limits.h>

#define M 8
int n;

void spath(int graph[n][n], int u)
{
    int dist[M];
    int s[M] = {0};
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[u] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int v;
        int min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (dist[j] < min && s[j] == 0)
            {
                min = dist[j];
                v = j;
            }
        }
        s[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[v][j] != 0 && s[j] == 0)
            {
                // Correction: Use 'v' instead of 'i' in the line below
                if (dist[j] > dist[v] + graph[v][j])
                {
                    // Correction: Use 'v' instead of 'i' in the line below
                    dist[j] = dist[v] + graph[v][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dist[i]);
    }
}

int main()
{
    n = 8;
    int graph[M][M] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {300, 0, 0, 0, 0, 0, 0, 0},
        {1000, 800, 0, 0, 0, 0, 0, 0},
        {0, 0, 1200, 0, 0, 0, 0, 0},
        {0, 0, 0, 1500, 0, 250, 0, 0},
        {0, 0, 0, 1000, 0, 0, 900, 1400},
        {0, 0, 0, 0, 0, 0, 0, 1000},
        {1700, 0, 0, 0, 0, 0, 0, 0}};
    spath(graph, 4);

    return 0;
}
