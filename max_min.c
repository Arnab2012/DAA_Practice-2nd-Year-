#include <stdio.h>

void MaxMin(int a[], int i, int j, int *max, int *min)
{
    int max1, mid, min1;
    if (i == j)
    {
        *max = a[i];
        *min = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] > a[j])
        {
            *max = a[i];
            *min = a[j];
        }
        else
        {
            *max = a[j];
            *min = a[i];
        }
    }
    else
    {
        mid = (i + j) / 2;
        MaxMin(a, i, mid, max, min);
        MaxMin(a, mid+1, j, &max1, &min1);
        if (*max < max1)
        {
            *max = max1;
        }
        if (*min > min1)
        {
            *min = min1;
        }
    }
}
int main()
{
    int n, max, min;
    printf("Enter the size of the array--> ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements-->\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array is-->\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    MaxMin(a, 0, n - 1, &max, &min);
    printf("The max value of the array is-->%d\n", max);
    printf("The min value of the array is-->%d\n", min);
    return 0;
}