#include <stdio.h>

int v = 5;
int isVisited[5] = {0};
dfs(int graph[][v], int u)
{
    if (!isVisited[u])
    {
        printf("%d", u);
        isVisited[u] = 1;
        for (int i = 0; i < v; i++)
        {
            if (graph[u][i] && isVisited[i])
            {
                dfs(graph, i);
            }
        }
    }
}

void main()
{
    // printf("Enter the input :");
    // scanf("%d",&)
    int graph[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 1, 1, 0}, {1, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    dfs(graph, 0);
}
