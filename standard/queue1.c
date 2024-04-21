//这个是队的数组形式，诶还是数组好啊简单啊
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 1000
int Queue[Maxsize];
int Front,Rear,Count;

void initQueue()
{
    Front=0;
    Rear =Maxsize-1;
    Count=0;
}

int isEmpty()
{
    return Count==0;
}

int isFull()
{
    return Count==Maxsize;
}

void enQueue(int queue[],int item)
{//入队
    if (isFull())
    {
        printf("worng!");
        exit(-1);
    }
    else
    {
        Rear=(Rear+1)%Maxsize;
        queue[Rear]=item;
        Count++;
    }
}

int deQueue(int queue[])
{
    int out;
    if (isEmpty())
    {
        printf("enpty");
    }
    else
    {
        out=queue[Front];
        Count--;
        Front=(Front+1)%Maxsize;
        return out;
    }
}

int main(void)
{
    return 0;
}

