#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INF 999
int n;
void FloydWarshall(int a[n][n])
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
}
int main()
{
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the weighted adjacency matrix of the graph: (Enter 0 for same vertex and 999 if no edge)\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    FloydWarshall(a);
    printf("The shortest path matrix is: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}