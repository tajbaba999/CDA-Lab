#include <stdio.h>

int queue[100] = {0}, front = 1, rear = 1;
int isVisited[10];
int count = 1;

bfs(int graph[5][5], int v, int u)
{
    if (count == v)
        return;

    for (int i = 0; i < v; i++)
    {
        if (isVisited[i] == 0 && graph[u][i] == 1)
        {
            isVisited[i] = 1;
            count++;
            queue[rear++] = i;
        }
    }
    bfs(graph, v, queue[front++]);
}

void main()
{
    // printf("Enter the input :");
    // scanf("%d",&)
    int graph[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 1, 1, 0}, {1, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int v = 5;
    isVisited[0] = 1;
    bfs(graph, v, 0);
    for (int i = 0; i < v; i++)
    {
        printf("%d ", queue[i]);
    }
}
