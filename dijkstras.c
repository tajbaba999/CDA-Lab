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
}

int main()
{

    int n = 8;
    int graph[M][M] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {300, 0, 0, 0, 0, 0, 0, 0},
                       {1000, 800, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1200, 0, 0, 0, 0, 0},
                       {0, 0, 0, 1500, 0, 250, 0, 0},
                       {0, 0, 0, 1000, 0, 0, 900, 1400},
                       {0, 0, 0, 0, 0, 0, 0, 1000},
                       {1700, 0, 0, 0, 0, 0, 0, 0}};
    spath(graph, 4);
}