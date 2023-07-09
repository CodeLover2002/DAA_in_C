#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *a,N,count=0;
int place(int pos)
{
    for(int i=1;i<pos;i++)
    {
        if(a[i]==a[pos]||abs(a[i]-a[pos])==abs(i-pos))
            return 0;
    }
    return 1;
}
void printsol()
{   
    printf("Solution %d:\n",count);
    for(int j=1;j<=N;j++)
        { 
            printf("%d ",a[j]);
        }
    
     printf("\n");

}
void queen()
{
   int k=1;
   a[k]=0;
   while(k!=0)
   {
        a[k]=a[k]+1;
        while(a[k]<=N && !place(k))
            a[k]++;
        if(a[k]<=N)
        {
            if(k==N)
            {   
                count++;
                printsol();
                
            }
            else{
                k++;
                a[k]=0;
            }
        
        }
        else
            k--;   
   }
   
}
int main()
{
    printf("Enter the number of queens: \n");
    scanf("%d",&N);
    a=(int *)malloc((N+1)*sizeof(int));
    queen();
}
