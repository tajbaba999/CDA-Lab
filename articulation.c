#include <stdio.h>

int dfn[10], a[10][10], l[10], n, num = 1, children[10];

int min(int a, int b)
{
    return (a < b ? a : b); // Corrected the condition
}

void art(int u, int v)
{
    dfn[u] = num;
    l[u] = num;
    num++;
    children[u] = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[u][i] == 1)
        {
            int w = i;
            if (dfn[w] == 0)
            {
                children[u]++;
                art(w, u);
                l[u] = min(l[u], l[w]);
                if (l[w] >= dfn[u])
                {
                    printf("%d is an articulation point\n", u);
                }
            }
            else if (w != v)
            {
                l[u] = min(l[u], dfn[w]);
            }
        }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int s, artp[10];

    printf("Enter the root vertex: ");
    scanf("%d", &s);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        dfn[i] = 0;
        artp[i] = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Articulation points are:\n");
    art(s, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i != s) && a[i][j] && l[j] >= dfn[i])
            {
                artp[i] = i;
            }
        }
    }

    printf("Articulation points after DFS:\n");
    for (int i = 0; i < n; i++)
    {
        if (artp[i] != 0)
        {
            printf("%d\n", artp[i]);
        }
    }

    return 0;
}
