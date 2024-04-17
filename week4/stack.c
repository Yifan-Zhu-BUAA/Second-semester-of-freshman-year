//写一个栈，实现1入栈，0出栈和-1退出的操作就行
#include <stdio.h>
#define Max 100

int stack[Max];
int top=-1;

void push(int x)
{
    if (top >= Max -1)
    {
        printf("error ");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop(void)
{
    if (top<0)
    {
        printf("error ");
    }
    else
    {
        printf("%d ",stack[top]);
        top--;
    }
}

int main(void)
{
    int i;
    while(1)
    {
        scanf("%d",&i);
        if (i==-1) break;
        switch(i)
        {
            case 1:
            {
                scanf("%d",&i);
                push(i);
            };break;
            case 0:pop();break;
        }
    }
}