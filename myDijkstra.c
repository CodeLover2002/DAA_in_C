#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#define N 4
int s,d[N],p[N],flag[N],w[N][N];
void initializeSS()
{
    for(int i=0;i<N;i++)
    {
        d[i]=INT_MAX;
        p[i]=-1;
        flag[i]=0;
    }
    d[s]=0;
}
int extractMin()
{
    int vertex,min=INT_MAX;
    for(int i=0;i<N;i++)
    {
        if(flag[i]==0 && d[i]<min)
        {
            vertex=i;
            min=d[i];
        }
    }
    flag[vertex]++;
    return vertex;
}
void relax(int u,int v)
{   
    int vertex;
    for(int i=0;i<N;i++)
    {    
        if(w[u][v]!=0 &&flag[i]!=0)
            {
                if(d[v]>d[u]+w[u][v])
                   { 
                        d[v]=d[u]+w[u][v];
                        p[v]=u;
                   }
            }
    }
}
void dijkstra()
{
   initializeSS();
   int count = N,u;
   while(count>0)
   {
        u=extractMin();
        for(int i=0;i<N;i++)
        {
            if(w[u][i]!=0)
                relax(u,i);
        }
   
   count--;
   }
}
int main()
{

    printf("Enter source vertex\n");
    scanf("%d",&s);
    printf("Enter weighted Adjacency Matrix\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&w[i][j]);
            if(w[i][j]==999)
                w[i][j]=0;
        }
    }
    
    dijkstra();
    printf("Shortest Path   Parent\n");
    for(int i=0;i<N;i++)
    {
       printf("     %d       %d",d[i],p[i]);
        printf("\n");
        
    }
}