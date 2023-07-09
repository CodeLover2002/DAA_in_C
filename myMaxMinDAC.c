#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
int n=10;
int max,min; 
int a[]={10,20,45,50,56,64,78,89,91,100};
int Maxmin1()
{   
    int c=0;
    max=min=a[0];
    for(int i=1;i<n;i++)
    {
        c++;
        if(a[i]>max)
            max=a[i];
        c++;
        if(a[i]<min)
            min=a[i];
    }
    return c;
}
int Maxmin2()
{
    int c2=0;
    max=min=a[0];
    for(int i=1;i<n;i++)
    {
        c2++;
        if(a[i]>max)
            max=a[i];
        else 
        {   
            c2++;
            if(a[i]<min)
                min=a[i];
        }
    }
    return c2;
}
void MaxminDAC(int *arr,int i,int j)
{   int max1,min1;
    if(i==j)
    {   max=min=arr[i];
        return;
    }
    else if(i==j-1)
    {
        if(a[i]>a[j])
        {
            max=a[i];
            min=a[j];
        }
        else
        {
            min=a[i];
            max=a[j];  
        }
    }
    else
    {   int mid=(i+j)/2;
        MaxminDAC(arr,i,mid);
        max1=max;
        min1=min;
        MaxminDAC(arr,mid+1,j);
        if(max1>max)
            max=max1;
        if(min1<min)
            min=min1;
    }
}
int main()
{   
    int v1= Maxmin1();
    int v2= Maxmin2();
    if(v1>=v2)
        printf("Maxmin2 is better than Maxmin1 with %d iterations.\n",v2);
    else
        printf("Maxmin1 is better than Maxmin2 with %d iterations.\n",v1);
    int arr[]={10,20,45,50,56,64,78,89,91,100};
    int n=sizeof(arr)/sizeof(arr[0]);
    MaxminDAC(arr,0,n-1);
    printf("The minimum element is %d and the maximum element is %d",min,max);
    
}