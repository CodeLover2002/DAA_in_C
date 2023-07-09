#include<stdio.h>
#include<stdlib.h>
void swap(int *i, int *j)
{
    int temp=*i;
    *i = *j;
    *j = temp;
}
void heapify(int *arr, int N,int i)
{
    int largest=i;
    int left=(2*i+1);
    int right=(2*i+2);
    if(left<N && arr[left]>arr[largest])
        largest=left;
    if(right<N && arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,N,largest);

    }
}
void heapsort(int *arr, int N)
{
    int i;
    for(i=N/2-1;i>=0;i--)
    {
        heapify(arr,N,i);
    }
    for(i=N-1;i>=0;i--)
    {
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    printf("The sorted array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}