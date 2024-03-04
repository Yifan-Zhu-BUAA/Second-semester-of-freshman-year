#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int cal(int num[81],char str1[81]);

int main()
{
    char str1[81],str2[81],tem[10],c;
    int num[81];
    int i,j,k,temn;
    gets(str1);
    for (i=0,j=0;str1[i]!='\0';i++)
    {
        if(str1[i]!=' ') str2[j++]=str1[i];
    }
    str2[j]='\0';
    for (i=0,j=0,k=0,temn=0;(c=str2[k])!='\0';k++)
    {
        if (isdigit(c))
        {
            tem[temn++]=c;
        }
        else
        {
            if (temn>0)
            {
                tem[temn]='\0';
                num[i++]=atoi(tem);
                temn=0;
            }
            str1[j++]=c;
        }
    }
    str1[j]='\0';
    // for (j=0;j<i;j++)
    // {
    //     printf("%d",num[j]);
    // }
    // printf("%s\n",str1);
    printf("\n%d",cal(num,str1));
}

int cal(int num[81],char str1[81])
{
    int i,j,temn,k;
    char tem2[81],c;
    for (i=j=k=temn=0;(c=str1[j])!='\0';j++)
    {
        if (c=='*')
        {
            i++;
            //printf("%d",num[i]);
            num[k]=num[k]*num[i];
            //printf("%d",num[k]);
        }
        else if(c=='/')
        {
            num[k]=num[k]/num[++i];
            //printf("%d",num[k]);
        }
        else if(c=='=')
        {
            continue;
        }
        else
        {
            num[++k]=num[++i];
            //printf("%d",num[k]);
            tem2[temn++]=c;
        }
    }
    tem2[temn++]='\0';
    for (i=j=temn=0;(c=tem2[j])!='\0';j++)
    {
        if (c=='+')
        {
            i++;
            num[0]+=num[i];
            //printf("%d",num[0]);
        }
        else if(c=='-')
        {
            i++;
            num[0]-=num[i];
            //printf("%d",num[0]);
        }
        else i++;
    }
    return num[0];
}