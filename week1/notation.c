#include <stdio.h>

void fright(char str[]);
void fleft(char str[]);

int main()
{
    char str[81];
    gets(str);
    if (str[1]=='\0') printf("%ce0",str[0]);
    else if (str[0]=='0') fright(str);
    else fleft(str);
}

void fright(char str[])
{
    int count=0,i=2;
    while(str[i++]=='0');
    i-=1;
    count=i-1;
    printf("%c",str[i++]);
    if (str[i]!='\0') printf(".");
    while(str[i]!='\0')
    {
        printf("%c",str[i++]);
    }
    printf("e-%d",count);
}

void fleft(char str[])
{
    int i=0,count=0;
    while(str[i++]!='.');
    count=i-2;
    i=0;
    printf("%c",str[i++]);
    if (str[i]!='\0') printf(".");
    while(str[i]!='\0')
    {
        if (str[i]!='.') printf("%c",str[i++]);
        else i++;
    }
    printf("e%d",count);
}