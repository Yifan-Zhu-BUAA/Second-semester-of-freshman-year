#include <stdio.h>
#include <stdlib.h>

void minus(char big[],int i,char sma[],int j);

int main()
{
    char str1[81],str2[81];
    int i=0,j=0;
    gets(str1);
    gets(str2);
    while(str1[i++]!='\0');
    i--;
    while(str2[j++]!='\0');
    j--;
    if (!strcmp(str1,str2)) printf("0");
    else if (i>j) minus(str1,i,str2,j);
    else if (i<j)
    {
        printf("-");
        minus(str2,j,str1,i);
    }
    else
    {
        if (str1[0]>str2[0]) minus(str1,i,str2,j);
        else printf("-"),minus(str2,j,str1,i);
    }
}
void minus(char big[],int i,char sma[],int j)
{
    int k=0,tem=0;//tem用来判断有没有进位，进位为1，否则为0
    char ans[81];//储存结果的倒序
    i--,j--;
    while(j>=0)
    {
            if ((big[i]-tem)>=sma[j])
        {
            ans[k++]=big[i--]-sma[j--]-tem+'0';
            tem=0;
        }
        else
        {
            ans[k++]=big[i--]-sma[j--]-tem+'0'+10;
            tem=1;
        }
    }
    while(i>=0)
    {
        if ((big[i]-tem)<'0') ans[k++]=big[i--]+9;
        else 
        {
            ans[k++]=big[i--]-tem;
            tem=0;
        }
    }
    k--;
    while(ans[k--]=='0');
    k++;
    while (k>=0)
    {
        printf("%c",ans[k--]);
    }
}