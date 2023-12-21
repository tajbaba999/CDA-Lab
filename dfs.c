#include <stdio.h>

int v = 5;
int visited[5] = {0};
void dfs(int u, int graph[][v])
{
    if (!visited[u])
    {
        printf("%d", u);
        visited[u] = 1;
        for (int i = 0; i < v; i++)
        {
            if (graph[u][i] == 0 && !visited[i])
            {
                dfs(i, graph);
            }
        }
    }
}

void main()
{
    int arr[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 1, 1, 0}, {1, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    dfs(0, arr);
}