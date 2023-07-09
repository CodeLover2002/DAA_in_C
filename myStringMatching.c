#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void ComputePrefix(char *pat,int M,int *lps)
{
    int j=0;
    lps[0]=0;
    int i=1;
    while(i<M)
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(j!=0) 
                j=lps[j-1];
            else
            {
                lps[i]=0;
                i++;                
            }
        }
    }
    printf("The Prefix Array is: \n");
    for(int i=0;i<M;i++)
        printf("%d ",lps[i]);
    printf("\n");
}
void KMPMatcher(char *s,char *p)
{   
    int flag=0;
    int M=strlen(p);
    int N=strlen(s);
    int *lps=(int *)malloc(M*sizeof(int));
    int i=0,j=0;
    ComputePrefix(p,M,lps);
    while(i<N)
    {
        if(s[i]==p[j])
        {
            i++;
            j++;
        }
        if(j==M)
        {   
            flag++;
            printf("Pattern found through KMPSearch at index %d with shift %d\n",i-j,i-M);
            j=lps[j-1];
            
        }
        else if(i<N && s[i]!=p[j])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        
        }
        
    
    }
    if(flag==0)
        printf("Pattern Not Found through KMPSearch.\n");
    else
        printf("The pattern is found %d times.\n",flag);

}
void BruteForce(char *s,char *p)
{   
    int ls=strlen(s);
    int lp=strlen(p);
    int flag=0;
    int i,j,k;
    for(i=0;i<=ls-lp;i++)
    {   
        j=0;
        k=i;
        while(s[k]==p[j])
        {
            k++;
            j++;
        }
        if(j==lp)
        {
           printf("Pattern Found through Brute Force at position %d\n",i);
           flag++;
        }       
    }
    if(flag==0)
         printf("Pattern Not Found through Brute Force Algorithm.\n");
    else
        printf("The pattern is found %d times.\n",flag);
}
int main()
{
    char *txt="ABABABACDABABDCBABABABG";
    char *pat="ABABAB";
    KMPMatcher(txt,pat);
    BruteForce(txt,pat);
    
}