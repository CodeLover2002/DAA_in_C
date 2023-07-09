#include<stdio.h>
#include<stdlib.h>
struct Item
{
    int pv;
    int wt;
    float pwr;
};
void Initial(struct Item *s, int w,int p)
{
    s->pv=p;
    s->wt=w;
    s->pwr=(s->pv)/(s->wt*1.0);
}



int main()
{
    int n;
    float maxp=0;
    printf("Enter number of items:\n");
    scanf("%d",&n);
    struct Item *p[n],*temp;
    for(int i=0;i<n;i++)
    {
        p[i]=(struct Item *)malloc(sizeof(struct Item));
    
    }
    int l,o;
    for(int i=0;i<n;i++)
    {
        printf("Enter weight and profit of item:%d\n",i+1);
        scanf("%d%d",&o,&l);
        Initial(p[i],o,l);

    }
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j]->pwr<p[j+1]->pwr)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                flag++;
            }

        }
        if(flag==0)
            break;
    }
    int tw,i;
    printf("Enter total weight of the knapsack: \n");
    scanf("%d",&tw);
    for(i=0;i<n;i++)
    {
        if(tw<p[i]->wt)
            break;
        maxp+=p[i]->pv;
        tw-=p[i]->wt;
        printf("1.00 ");
        
    }
    if(tw>0)
    {
        float x=tw/(p[i]->wt*1.00);
        maxp+=(p[i]->pwr*tw);
        printf("%.2f ",x);
    }
    printf("\nTotal profit of the knapsack is:%.2f \n",maxp);


    return 0;
}