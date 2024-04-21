#include <stdio.h>
#include <stdlib.h>
//链表的队

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *Front,*Rear;

void initQueue()
{
    Front=NULL;
    Rear=NULL;
}

int isEmpty()
{
    return Front== NULL;
}

void enQueue(int item)
{
    Node *p;
    if( (p=(Node*)malloc(sizeof(Node)))==NULL)
    {
        printf("can't get it");
        exit(-1);
    }
    p->data=item;
    p->link=NULL;
    if (Front==NULL)
    {
        Front=p;
    }
    else
        Rear->link=p;
    Rear=p;
}

int deQueue()
{
    Node *p;
    int item;
    if (isEmpty())
    {
        printf("empty");
        exit(-1);
    }
    else
    {
        p=Front;
        Front=Front->link;
        item=p->data;
        free(p);
        return item;
    }
}

void destoryLQueue()
{
    while(Front != NULL)
    {
        Rear=Front->link;
        free(Front);
        Front=Rear;
    }
}

int main(void)
{
    return 0;
}
