#include <stdio.h>
int m=1;
void adjustHeap(int a[], int i, int n)
{
    int j = 2 * i, key = a[i];
    while (j <= n)
    {
        if (j < n && a[j] < a[j + 1])
        {
            j = j + 1;
        }
        if (key >= a[j])
        {
            break;
        }
        a[j / 2] = a[j];
        j = j*2;
    }
    a[j / 2] = key;
}
void makeheap(int a[], int n)
{
    for (int i = (n / 2); i >= 1; i--)
    {
        adjustHeap(a, i, n);
    }
}
void heapsort(int a[], int n)
{
    makeheap(a, n);
    for (int i = n; i >= 2; i--)
    {
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        adjustHeap(a, 1, i - 1);
        printf("\n");
        printf("Pass:%d--> ",m);
        for(int j=1;j<=n;j++){
            printf("%d ",a[j]);
        }
        m++;
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the size of the array--> ");
    scanf("%d", &n);
    int a[n + 1];
    printf("Enter the array elements-->\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nThe array before sortting-->\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    heapsort(a, n);
    printf("\nThe array after sortting-->\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}