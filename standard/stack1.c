//数组形式
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
int stack[MAXSIZE];
int top;

void initStack()
{
    top=-1;
}

int isEmpty()
{
    return top==-1;
}

int isFull()
{
    return top==MAXSIZE-1;
}

void push(int stack[],int item)
{
    if(isFull())
    {
        printf("Full Stack!");
        exit(-1);
    }
    else
        stack[++top]=item;
}

int pop(int stack[])
{
    if (isEmpty())
    {
        printf("Full stack!");
        exit(-1);
    }
}

int main()
{
    return 0;
}