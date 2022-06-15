#include <stdio.h>
#include <stdbool.h>

int n, x[100], G[100][100], c = 0;
void NextValue(int k, int m)
{
    do
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }
        int j;
        for (j = 1; j <= (k - 1); j++)
        {
            if (G[k][j] == 1 && x[k] == x[j])
            {
                break;
            }
        }
        if (j == k)
        {
            return;
        }

    } while (true);
}
void print()
{
    printf("\nSolution:%d-->\n", ++c);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
}
void mColoring(int k, int m)
{
    do
    {
        NextValue(k, m);
        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            print();
        }
        else
        {
            mColoring(k + 1, m);
        }
    } while (true);
}
int main()
{
    int m;
    FILE *fp;
    fp = fopen("color.txt", "r");
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
                fscanf(fp, "%d", &G[i][j]);
            }
        }
        fclose(fp);
        printf("Enter the number of vertices--> ");
        scanf("%d", &n);
        printf("\nEnter the number of colors--> ");
        scanf("%d", &m);
        mColoring(1, m);
        if (c == 0)
        {
            printf("No such Solutions exist!!!");
        }
    }
    return 0;
}