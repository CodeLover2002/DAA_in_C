#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int factorial(int n,int a)
{
    if(n==1)
    return a;
    
    return(factorial(n-1,n*a));
}
int main()
{
    int n;
    printf("Enter the number whose factorial you want to find: \n");
    scanf("%d",&n);
    printf("The factorial of %d is %d.",n,factorial(n,1));
}
