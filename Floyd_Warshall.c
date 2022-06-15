#include <stdio.h>
#include <limits.h>
int n,d[100][100],G[100][100],p[100][100];
void APSP(int i,int j){
    if(i==j){
        printf("%d",i);
    }
    else if(i!=j && p[i][j]==INT_MIN){
        printf("There is no path");
    }
    else{
        APSP(i,p[i][j]);
        printf("-->%d",j);
    }
}
void display(int (*D)[100],int (*P)[100],int k){
    printf("\nD%d matrix is-->\n",k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(D[i][j]==INT_MAX){
                printf(" INF ");
            }
            else{
                printf("%3d",D[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nP%d matrix is-->\n",k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(P[i][j]==INT_MIN){
                printf(" NULL ");
            }
            else{
                printf("%3d",P[i][j]);
            }
        }
        printf("\n");
    }
}
void Floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                d[i][j]=0;
                p[i][j]=INT_MIN;
            }
            else if(G[i][j]==0){
                d[i][j]=INT_MAX;
                p[i][j]=INT_MIN;
            }
            else{
                d[i][j]=G[i][j];
                p[i][j]=i;
            }
        }
    }
    display(d,p,0);
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(k!=i && k!=j && d[i][k]!=INT_MAX && d[k][j]!=INT_MAX && d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
        display(d,p,k);
    }
}

int main()
{
    int a, b;
    FILE *fp;
    fp = fopen("floyd.txt", "r");
    if (fp == NULL)
    {
        printf("Error to open the file!!!\n");
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
        Floyd();
        printf("Enter the source vertex--> ");
        scanf("%d", &a);
        printf("Enter the destination vertex--> ");
        scanf("%d", &b);
        if (a >= 1 && b >= 1 && a <= n && b <= n)
        {
            printf("\nThe shortest path from vertex %d to vertex %d is-->:\n ", a, b);
            APSP(a, b);
            printf(" and the corresponding cost is : %d\n", d[a][b]);
        }
        else
            printf("\nInvalid Input !");
    }
    return 0;
}