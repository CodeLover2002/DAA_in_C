#include<stdio.h>
#include<stdlib.h>
void merge(int *L,int *R,int nL,int nR,int *a)
{
    int i=0,j=0,k=0;
    while(i<nL && j<nR)
    {
        if (L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<nL)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<nR)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int N,int *a)
{   if(N<2)
        return;
    int mid=N/2;
    int Left[mid],Right[N-mid];
    for(int i=0;i<mid;i++)
    {
        Left[i]=a[i];
    }
    for(int j=mid;j<N;j++)
    {
        Right[j-mid]=a[j];
    }
    mergesort(mid,Left);
    mergesort(N-mid,Right);
    merge(Left,Right,mid,N-mid,a);
}
int main()
{
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d",&n); 
    int *a;
   a=(int *)malloc(n*sizeof(int));
   printf("Enter the elements of the array: \n");
   for(int i=0;i<n;i++)
    scanf("%d",&a[i]) ;
    mergesort(n,a);
    printf("The sorted array is: \n");
    for(int j=0;j<n;j++)
        printf("%d ",a[j]);
    return 0;
}