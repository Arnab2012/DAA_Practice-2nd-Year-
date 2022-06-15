#include <stdio.h>
#include <limits.h>

int d[100];
char p[100];
struct edge
{
    int v1;
    int v2;
    int wt;
};
struct edge e[100];
int k, ed, G[100][100];
void path(int i)
{
    if (p[i] == 'N')
    {
        return;
    }
    else
    {
        path((int)(p[i] - 64));

        printf("  %c to %c", p[i], (char)(i + 64));
    }
}

char Bellman(int s)
{
    for (int i = 1; i <= k; i++)
    {
        d[i] = INT_MAX;
        p[i] = 'N';
    }
    d[s] = 0;
    for (int i = 1; i <= k - 1; i++)
    {
        for (int j = 0; j < ed; j++)
        {
            if (d[e[j].v1] != INT_MAX && d[e[j].v1] + e[j].wt < d[e[j].v2])
            {
                d[e[j].v2] = d[e[j].v1] + e[j].wt;
                p[e[j].v2] = (char)(e[j].v1 + 64);
            }
        }
    }

    for (int j = 0; j < ed; j++)
    {
        if (d[e[j].v1] != INT_MAX && d[e[j].v1] + e[j].wt < d[e[j].v2])
        {
            return 'F';
        }
    }

    return 'T';
}
int main()
{
    FILE *fp;
    char a, b;
    int weight;
    printf("Enter the number of vertices--> ");
    scanf("%d", &k);
    printf("Enter number of edges--> ");
    scanf("%d", &ed);
    fp = fopen("bellman.txt", "r");
    if (fp == NULL)
    {
        printf("Error to open the file!!!");
    }
    else
    {
        int y = 0;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                fscanf(fp, "%d", &weight);
                if (weight != 0)
                {
                    e[y].v1 = i;
                    e[y].v2 = j;
                    e[y++].wt = weight;
                }
            }
        }
        fclose(fp);

        printf("\nEnter the start vertex--> ");
        getchar();
        scanf("%c", &a);
        printf("\nEnter the destination vertex--> ");
        getchar();
        scanf("%c", &b);
        if ((int)a - 64 == (int)b - 64)
        {
            printf("Source vertex is equal to destination vertex!!!");
        }
        else
        {
            char c = Bellman((int)a - 64);
            if (c == 'T')
            {
                printf("\nThe Shortest path from %c to %c is-->\n", a, b);
                path((int)b - 64);
                printf(" and the cost is--> %d", d[(int)b - 64]);
            }
            else
            {
                printf("\nNegetive edge cycle occurs!!!");
            }
        }
    }
    return 0;
}