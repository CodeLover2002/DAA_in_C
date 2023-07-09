#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n,*a;
int LinearSearch(int x)
{   int c=0;
    for(int i=0;i<n;i++)
    {   
        c++;
        if(a[i]==x)
            break;
    }
    return c;
}
int BinSearch(int x)
{   
    int c1=0;
    int low=0,high=n-1,mid;
    while(low<=high)
    {  mid=(low+high)/2;
        c1++;
        if(a[mid]==x)
            break;
        c1++;
        if(a[mid]<x)
            low=mid+1;
        else
            high=mid-1;
    }
    return c1;
}
int main()
{
    int x;
    printf("Enter the number of elements of the array: \n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the array elements: \n");
    for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
    printf("Enter the element to be searched: \n");
    scanf("%d",&x);
    int v1=LinearSearch(x);
    int v2=BinSearch(x);
    if(v1>v2)
        printf("Binary Search is better.");
    else    
        printf("Linear Search is better.");
}