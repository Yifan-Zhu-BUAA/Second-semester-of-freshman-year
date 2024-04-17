#include <stdio.h>
#include <stdlib.h>


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

CLI* creat_cli(PO po1,PO po2);
void check_cli(CLI *cl[],PO po,int check[],int n,int *px,int *py,int *ptemp);//返回链接到的最长,x和y用来记录起点的x和y
void change_head(int x,int y,int *px,int *py);//用来找头节点的，如果x更小则更改头结点

int main()
{
    int n,count=0,temp,x1,y1,x2,y2;
    PO po1,po2;
    scanf("%d",&n);
    CLI *cl[n];
    int check[n];
    for(int i=0; i<n;i++) 
    {
        cl[i] = NULL;
        check[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        po1.x=x1,po1.y=y1;
        po2.x=x2,po2.y=y2;
        cl[i]=creat_cli(po1,po2);
    }
    for(int i=0;i<n;i++)//开始计数的，两头都计数，返回两头找到的最大值，用temp来记录
    {
        
        if (check[i]==0)
        {
            check[i]=1;
            temp=0;
            x2=cl[i]->head.x;
            y2=cl[i]->head.y;
            check_cli(cl,cl[i]->head,check,n,&x2,&y2,&temp);
            check_cli(cl,cl[i]->tail,check,n,&x2,&y2,&temp);
            temp+=1;
            if (temp>count)
            {
                x1=x2;
                y1=y2;
                count=temp;
            }
        }
    }
    printf("%d %d %d",count,x1,y1);
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

void check_cli(CLI *cl[],PO po,int check[],int n,int *px,int *py,int *ptemp)
{   
    int x,y;
    for (int i=0;i<n;i++)
    {
        if (check[i]==0)//没被连在线上
        {
            if ((x=cl[i]->head.x)==po.x)//检测头是不是重合
            {
                if ((y=cl[i]->head.y)==po.y)
                {
                    check[i]=1;
                    (*ptemp)++;
                    change_head(cl[i]->head.x,cl[i]->head.y,px,py);
                    check_cli(cl,cl[i]->tail,check,n,px,py,ptemp);
                    return;
                }
            }
            if (cl[i]->tail.x==po.x)//检测尾是不是重合
            {
                if (cl[i]->tail.y==po.y)
                {
                    check[i]=1;
                    (*ptemp)++;
                    change_head(cl[i]->head.x,cl[i]->head.y,px,py);
                    check_cli(cl,cl[i]->head,check,n,px,py,ptemp);
                    return;
                }
            }
        }
    }
}

void change_head(int x,int y,int *px,int *py)
{
    if(x<*px)
    {
        *px=x;
        *py=y;
    }
}