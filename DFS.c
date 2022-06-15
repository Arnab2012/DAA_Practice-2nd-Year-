#include <stdio.h>
int top = -1, s[100], gr[100][100], visited[100], n;

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int item)
{
    top = top + 1;
    s[top] = item;
}
int pop()
{
    return s[top--];
}
void DFS(int v)
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    push(v);
    visited[v] = 1;
    while (!isEmpty())
    {
        int u = pop();
        printf("%d ", u);
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == 0 && gr[u][j] == 1)
            {
                push(j);
                visited[j] = 1;
            }
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