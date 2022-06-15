#include <stdio.h>
int front = -1, rear = -1, q[100], gr[100][100], visited[100], n;

int isEmpty()
{
    if (front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert(int item)
{
    rear = rear + 1;
    q[rear] = item;
}
int delete ()
{
    front = front + 1;
    return q[front];
}
void BFS(int v)
{
    for (int i = 0; i <= n - 1; i++)
    {
        visited[i] = 0;
    }
    insert(v);
    visited[v] = 1;
    while (!isEmpty())
    {
        int u = delete ();
        printf("%c ", u + 65);
        for (int j = 0; j <= n - 1; j++)
        {
            if (visited[j] == 0 && gr[u][j] == 1)
            {
                insert(j);
                visited[j] = 1;
            }
        }
    }
}
int main()
{
    FILE *fp;
    char a;
    fp = fopen("bfs.txt", "r");
    if (fp == NULL)
    {
        printf("Error to open the file!!!");
    }
    else
    {
        fscanf(fp, "%d", &n);
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                fscanf(fp, "%d", &gr[i][j]);
            }
        }
        fclose(fp);
        printf("Enter the number of vertices--> ");
        scanf("%d", &n);
        printf("\nEnter the strating vertex--> ");
        getchar();
        scanf("%c", &a);
        printf("\nBFS traversal of the graph is--> ");
        BFS((int)a - 65);
    }
    return 0;
}