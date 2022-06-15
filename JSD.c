#include <stdio.h>
#include <limits.h>
struct Job{
    char id;
    int profit;
    int deadline;
};
int m=INT_MIN,n;
struct Job job[100];
void mergejobs(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    struct Job b[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (job[i].profit >= job[j].profit)
        {
            b[k++] = job[i++];
        }
        else
        {
            b[k++] = job[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = job[i++];
    }
    while (j <= high)
    {
        b[k++] = job[j++];
    }
    k = 0;
    for (int p = low; p <= high; p++)
    {
        job[p] = b[k++];
    }
}
void mergeSort_jobs(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort_jobs(low, mid);
        mergeSort_jobs(mid + 1, high);
        mergejobs(low, mid, high);
    }
}
int min(int x,int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}
void findMax(){
    for(int i=0;i<n;i++){
        if(job[i].deadline>m){
            m=job[i].deadline;
        }
    }
}
void JSD(){
    int p=0,k=min(m,n);
    int slot[k];
    for(int i=0;i<k;i++){
        slot[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=min(job[i].deadline-1,n);j>=0;j--){
            if(slot[j]==0){
                p=p+job[i].profit;
                printf("%c ",job[i].id);
                slot[j]=1;
                break;
            }
        }
    }
    printf("Max profit is-->%d",p);
}
int main()
{
    printf("Enter the number of jobs--> ");
    scanf("%d", &n);
    printf("Enter profit and deadline-->\n");
    for (int i = 0; i < n; i++)
    {
        job[i].id = (char)(65 + i);
        scanf("%d %d", &job[i].profit, &job[i].deadline);
    }
    findMax();
    mergeSort_jobs(0, n - 1);
    printf("Jobs are-->\n");
    JSD();
    return 0;
}