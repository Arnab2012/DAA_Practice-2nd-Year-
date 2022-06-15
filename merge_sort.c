#include <stdio.h>
int n, m = 1, b[100];
void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
    printf("\n");
    printf("Pass:%d--> ", m);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    m++;
    printf("\n");
}
void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main()
{
    printf("Enter the size of the array--> ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements-->\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nThe array before sortting-->\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("\nThe array after sortting-->\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}