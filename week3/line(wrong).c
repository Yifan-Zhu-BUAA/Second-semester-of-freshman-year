#include <stdio.h>
#include <stdlib.h>

//这个写错了感觉废了，虽然说部分函数还是可以用，没有考虑到两条已经存在的线因为一条新的线而连在一起的情况
typedef struct point
{
    int x;
    int y;
} PO;

typedef struct c_Line
{
    PO head;
    PO tail;
    int count;
} CLI;

int check_cli(CLI *cli,PO po);//返回点是否和线有连上，没有0，头1，尾2
void add_cli(CLI *cli,PO po,int type);//把点插到具体的连续线段中,type为1则修改头，2则修改尾巴
void in_cli(CLI*cl[],PO po1,PO po2);//把单独的线放进线表中

PO* creat_po(int x,int y);//point还是别分配空间了一次就没了,这个函数不用的
CLI* creat_cli(PO po1,PO po2);

int main()
{
    int n,count=0,x1,y1,x2,y2;
    PO po1,po2;
    scanf("%d",&n);
    CLI *cl[n];
    for(int i = 0; i < n; i++) {
        cl[i] = NULL;
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        po1.x=x1,po1.y=y1;
        po2.x=x2,po2.y=y2;
        in_cli(cl,po1,po2);
    }
    int i=0;
    while(cl[i]!=NULL)
    {
        if ((cl[i]->count) > count)
        {
            count=cl[i]->count;
            x1=cl[i]->head.x;
            y1=cl[i]->head.y;
        }
        i++;
    }
    printf("%d %d %d",count,x1,y1);
}

void in_cli(CLI*cl[],PO po1,PO po2)
{
    int check=0,i=0,tmp=0;
    while(cl[i]!=NULL)
    {   
        tmp=check_cli(cl[i],po1);
        if (tmp>0)
        {
            add_cli(cl[i],po2,tmp);
            return;
        }
        tmp=check_cli(cl[i],po2);
        if (tmp>0)
        {
            add_cli(cl[i],po1,tmp);
            return;
        }
        i++;
    }
    CLI *cl_add;
    cl_add=creat_cli(po1,po2);
    cl[i]=cl_add;
}

int check_cli(CLI *cli,PO po)
{
    if (cli->head.x==po.x)
    {
        if(cli->head.y==po.y) return 1;
    }
    if (cli->tail.x==po.x)
    {
        if(cli->tail.y==po.y) return 2;
    }
    return 0;
}

void add_cli(CLI *cli,PO po,int type)
{
    if (type==1)
    {
        cli->head=po;
    }
    else
    {
        cli->tail=po;
    }
    if (cli->head.x>cli->tail.x)
    {
        PO tmp;
        tmp=cli->head;
        cli->head=cli->tail;
        cli->tail=tmp;
    }
    (cli->count)++;
}

CLI* creat_cli(PO po1,PO po2)
{
    CLI *cl;
    cl=(CLI *)malloc(sizeof(CLI));
    cl->count=1;
    cl->head=po1;
    cl->tail=po2;
    return cl;
}
