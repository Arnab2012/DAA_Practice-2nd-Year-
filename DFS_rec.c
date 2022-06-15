#include <stdio.h>
int gr[100][100],visited[100]={0}, n;

void DFS(int a)
{
    visited[a] = 1;
    printf("%d ", a);
    for (int i = 1; i <= n; i++)
    {
        if (gr[a][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    FILE *fp;
    int a;
    fp = fopen("dfs.txt", "r");
    if (fp == NULL)
    {
        printf("Error to open the file!!!");
    }
    else
    {
        fscanf(fp, "%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                fscanf(fp, "%d", &gr[i][j]);
            }
        }
        fclose(fp);
        printf("Enter the number of vertices--> ");
        scanf("%d", &n);
        printf("\nEnter the strating vertex--> ");
        // getchar();
        scanf("%d", &a);
        printf("\nBFS traversal of the graph is--> ");
        DFS(a);
    }
    return 0;
}