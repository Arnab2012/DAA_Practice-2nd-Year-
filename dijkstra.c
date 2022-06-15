#include <stdio.h>
#include <limits.h>
struct Dijkstra
{
    int key;
    int parent;
    char sptset;
};
struct Dijkstra dijkstra[100];
int v, G[100][100], cost[100][100];

int extractMin()
{
    int min = INT_MAX, minIndex;
    for (int i = 0; i < v; i++)
    {
        if (dijkstra[i].sptset == 'F' && dijkstra[i].key < min)
        {
            min = dijkstra[i].key;
            minIndex = i;
        }
    }
    return minIndex;
}
void dijkstra1(int r)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            if (G[i][j] == 0)
                cost[i][j] = INT_MAX;
            else
                cost[i][j] = G[i][j];
        }
    }
    for (i = 0; i < v; i++)
    {
        dijkstra[i].key = cost[r][i];
        dijkstra[i].parent = r;
        dijkstra[i].sptset = 'F';
    }
    dijkstra[r].key = 0;
    for (i = 0; i < v; i++)
    {

        int u = extractMin();
        dijkstra[u].sptset = 'T';
        for (j = 0; j < v; j++)
        {
            if (G[u][j] > 0 && dijkstra[j].sptset == 'F' && dijkstra[j].key > G[u][j] + dijkstra[u].key)
            {
                dijkstra[j].key = G[u][j] + dijkstra[u].key;
                dijkstra[j].parent = u;
            }
        }
    }
    for (i = 0; i < v; i++)
    {
        if (i != r)
        {
            if (dijkstra[i].key == INT_MAX)
            {
                printf("\nThere is no path to node %c from %c!!!\n", (i + 65), (r + 65));
            }
            else
            {
                printf("\nDistance of node %c from %c is= %d", (i + 65), (r + 65), dijkstra[i].key);
                printf("\nPath= %c", (i + 65));
                j = i;
                do
                {
                    j = dijkstra[j].parent;
                    printf("<- %c", j + 65);
                } while (j != r);
                printf("\n");
            }
        }
    }
}
int main()
{
    char n;
    FILE *fp;
    fp = fopen("dijkstra.txt", "r");
    if (fp == NULL)
    {
        printf("\nError in opening the file!!!\n");
    }
    else
    {
        fscanf(fp, "%d", &v);
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                fscanf(fp, "%d", &G[i][j]);
            }
        }
        fclose(fp);
        printf("Entre the number of vertices--> ");
        scanf("%d", &v);
        printf("\nEnter the starting vertex--> ");
        getchar();
        scanf("%c", &n);
        printf("\nThe SSSP is--->\n");
        dijkstra1((int)n - 65);
    }
    return 0;
}