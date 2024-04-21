#include <stdio.h>
#include <stdlib.h>
//链表形式的栈定义
struct node
{
    int data;
    struct node *link;//指向前一个
};

struct node *top;

void initStack()
{
    top=NULL;
}

int isEmpty()
{
    return top==NULL;
}

void push(int item)
{
    struct node *p;
    if ((p=(struct node *)malloc(sizeof(struct node)))==NULL)
    {
        printf("worng");
        exit(-1);
    }
    else
    {
        p->data=item;
        p->link=top;
        top=p;
    }
}

int pop()
{
    struct node *p;
    int item;
    if(isEmpty())
    {
        printf("empty");
    }
    else
    {
        p=top;
        item=top->data;
        top=top->link;
        free(p);
        return item;
    }
}

int main(void)
{
    return 0;
}