#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define n 5
int a[n][n]={{0,1,0,0,1},{1,0,1,1,1},{0,1,0,1,0},{0,1,1,0,1},{1,1,0,1,0}};
int visited[n]={0};int vs[n]= {0};
void BFS(int s)
{
    int q[n]={0};
    int front=0,rear=0;
    q[rear++]=s;
    visited[s]=1;
    printf("BFS Traversal: \n");
    while(front!=rear)
    {
        int v=q[front++];
        printf("%d ",v);
        for(int i=0;i<n;i++)
        {
            if(a[v][i]!=0 && !visited[i])
            {
                q[rear++]=i;
                visited[i]=1;
            }
        }
        
    }
    return ;
    
}
void DFS(int s)
{
    vs[s]=1;
    printf("%d ",s);
    for(int i=0;i<n;i++)
    {
        if(a[s][i]!=0 && !vs[i])
            DFS(i);
    }
}
int main()
{
    BFS(0);
    printf("DFS Traversal: \n");
    DFS(0);
}