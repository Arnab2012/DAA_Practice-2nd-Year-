#include <stdio.h>

int n, m = 1;
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int partition(int a[], int low, int high)
{
    int i = low, j = high + 1;
    // int mid=(low+high)/2;
    int pivot = a[low];
    while (i < j)
    {
        do
        {
            i++;
        } while (i <= j && a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a, i, j);
        }
    }
    swap(a, low, j);
    printf("\n");
    printf("Pass:%d--> ", m);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    m++;
    printf("\n");
    return j;
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
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
    quickSort(a, 0, n - 1);
    printf("\nThe array after sortting-->\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}