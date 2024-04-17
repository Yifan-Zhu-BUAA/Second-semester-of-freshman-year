#include <stdio.h>
#include <stdlib.h>

int maxsum(int num[],int n);

int main(void)
{
    int n,nu;
    scanf("%d",&n);
    int num[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("%d",maxsum(num,n));
}

int maxsum(int num[],int n)
{
    int thissum=0,maxsum=0;
    for (int i=0;i<n;i++)
    {
        if ((thissum+num[i])>0)
        {
            thissum+=num[i];
        }
        else
        {
            thissum=0;
        }
        if (thissum>maxsum) maxsum=thissum;
    }
    return maxsum;
}