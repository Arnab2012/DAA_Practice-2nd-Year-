#include <stdio.h>
struct Item{
    int id;
    float weight;
    float profit;
    float ratio;
};
struct Item item[100];
void merge(int low,int mid,int high){
    int i=low,j=mid+1,k=0;
    struct Item b[high-low+1];
    while(i<=mid && j<=high){
        if(item[i].ratio>=item[j].ratio){
            b[k++]=item[i++];
        }
        else{
            b[k++]=item[j++];
        }
    }
    while(i<=mid){
        b[k++]=item[i++];
    }
    while(j<=high){
        b[k++]=item[j++];
    }
    k=0;
    for(int p=low;p<=high;p++){
        item[p]=b[k++];
    }
}
void mergeSort(int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        merge(low,mid,high);
    }
}
void knapsack(int n,int capacity){
    float x[100],tp=0;
    int i;
    for(i=0;i<n;i++){
        x[i]=0.0;
    }
    int u=capacity;
    for(i=0;i<n;i++){
        if(item[i].weight>u){
            break;
        }
        else{
            x[i]=1.0;
            tp=tp+item[i].profit;
            u=u-item[i].weight;
        }
    }
    if(i<n){
        x[i]=u/item[i].weight;
    }
    tp=tp+(x[i]*item[i].profit);
    printf("Fractional part in the knapsack is-->\n");
    for(int i=0;i<n;i++){
        printf("Element %d-->%0.2f\n",item[i].id,x[i]);
    }
    printf("\nMax profit is-->%f",tp);
}
int main()
{
    int n, m;
    printf("Enter the number of elements--> ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity--> ");
    scanf("%d", &m);
    printf("\nEnter the item id,weight and profits for each items-->\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %f %f", &item[i].id, &item[i].weight, &item[i].profit);
    }
    for (int i = 0; i < n; i++)
    {
        item[i].ratio = item[i].profit / item[i].weight;
    }
    mergeSort(0, n - 1);
    knapsack(n, m);
    return 0;
}