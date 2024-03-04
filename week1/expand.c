#include <stdio.h>
#include <ctype.h>

void pr(int a,int b);

int main()
{
    char str[81],c;
    int i=0;
    gets(str);
    while ((c=str[i])!='\0')
    {
        if (c=='-')
        {
            if ((i==0) || str[i+1]=='\0') 
            {
                printf("-");
            }
            else if(isdigit(str[i-1])&&isdigit(str[i+1])) pr(str[i-1],str[i+1]);
            else if(islower(str[i-1])&&islower(str[i+1])) pr(str[i-1],str[i+1]);
            else if(isupper(str[i-1])&&isupper(str[i+1])) pr(str[i-1],str[i+1]);
            else printf("-");
        }
        else printf("%c",c);
        i++;
    }
}
void pr(int a,int b)
{
    for (char c=a+1;c<b;c++)
    {
        printf("%c",c);
    }
}