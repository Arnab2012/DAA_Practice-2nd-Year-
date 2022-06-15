#include <stdio.h>
#include <stdlib.h>
int x[100], c = 0;

int place(int k, int i)
{
    for (int j = 1; j <= (k - 1); j++)
    {
        if (x[j] == i || abs(j - k) == abs(x[j] - i))
        {
            return 0;
        }
    }
    return 1;
}
void print(int n)
{
    printf("\nSolution:%d--> ", ++c);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}
void print1(int n){
    printf("\nSolution:%d-->\n", ++c);
    for(int i=1;i<=n;i++){
        printf("\t%d",i);
    }
    for(int i=1;i<=n;i++){
        printf("\n\n%d",i);
        for(int j=1;j<=n;j++){
            if(x[i]==j){
                printf("\tQ");
            }
            else{
                printf("\t-");
            }
        }
    }
}
void nQueen(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i) == 1)
        {
            x[k] = i;
            if (k == n)
            {
                //print(n);
                print1(n);
            }
            else
            {
                nQueen(k + 1, n);
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of queens--> ");
    scanf("%d", &n);
    printf("\nPossible solutions are-->\n\n");
    nQueen(1, n);
    if (c == 0)
    {
        printf("\nNo such solutions exist!!!\n");
    }
    return 0;
}