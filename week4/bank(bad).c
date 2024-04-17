#include <stdio.h>
#include <stdlib.h>
/*题目说了很多无关的，其实只用考虑对私窗口及其增加，出题人题目没改好还打错字了
每个人的等待周期并不可以在进来时就计算，因为可能出现新窗口开放或关闭导致时间变动
所以我感觉还是定义一个结构好了然后到他了再将当前周期减去他的进入周期
先读取全部再计算,用指针链表吧*/

typedef struct custom
{
    int wait_time;//最终计算的等待时间
    int id;
    int type;//业务类型
    int in_time;//进来的时间周期
    struct custom *next;
} Cus;

void creat_cus(Cus *total[],int n);//根据输入创建链表
void cal_cus(Cus *total[],int n);
int cal_cus_n(Cus *total[],int cycle_now);//返回当前轮次有的客户数量
int deal(Cus *total[],Cus *win[],int win_n);//用来处理客户，并且返回此轮的客户完成数量
int check_win(Cus *win[],int win_n);//检查窗口还有没有人，有人返回1，没人返回0
int main(void)
{
    int n,cycle=0;//n为total的数量，cycle为当前周期
    scanf("%d",&n);
    Cus *total[n];
    creat_cus(total,n);
    // cal_cus(total);
    // print_cus(total);
    Cus *temp;
    for (int i=0;i<n;i++)//打印一下
    {
        temp=total[i];
        while(temp!=NULL)
        {
            printf("%d %d %d %d\n",temp->id,temp->in_time,temp->type,temp->wait_time);
            temp=temp->next;
        }
    }

}

void creat_cus(Cus *total[],int n)
{
    int cus_n,id=0,type;//cus_n是每个周期的人数
    Cus *temp=NULL,*next=NULL;
    // total=malloc(n * sizeof(Cus *));//好像重复定义了，这个是不需要的；
    for (int i=0;i<n;i++)//初始化
    {
        total[i]=NULL;
    }
    for (int i=0;i<n;i++)//创建每个时间周期
    {
        scanf("%d",&cus_n);
        for (int j=0;j<cus_n;j++)
        {
            if (j==0)
            {
                temp=malloc(sizeof(Cus));
                temp->next=NULL;
                temp->wait_time=0;
                temp->type=0;
                temp->in_time=i+1;
                total[i]=temp;
            }
            else
            {
                next=malloc(sizeof(Cus));
                next->next=NULL;
                next->in_time=i+1;
                next->wait_time=0;
                next->type=0;
                temp->next=next;
                temp=next;
            }
        }
    }
    for (int i=0;i<n;i++)//把id和业务类型承接上
    {
        temp=total[i];
        while(temp!=NULL)
        {
            scanf("%d",&type);
            temp->type=type;
            temp->id=++id;
            temp=temp->next;
        }
    }
}



void cal_cus(Cus *total[],int n)
{
    int win_n=3,cycle_now=0,cus_now=0,cus_cycle_n=0;//win为窗口数，cyclen为当前经过的周期数，
    //cusnow为当前排队人数,最后那个是当前准备进入窗口客户的进入周期数
    Cus *win[10]={NULL};//计算表示当前的窗口，
    while(1)
    {
        cycle_now++;
        if (cycle_now<n)
        {
            cus_now+=cal_cus_n(total,cycle_now);
        }
        
        while (cycle_now/win_n>=7)
        {
            win_n++;
        }

        // cycle_now-=deal(total,win,win_n);发现deal必须在主函数里运行最好
        for (int i=0;i<win_n;i++)
        {
            win[i]->type--;
        }

        // while (cycle_now/win_n<7)
        // {
        //     win_n--;
        // }

        if(cycle_now>=n && !check_win(win,win_n)) break;//当周期走完并且窗口没客户时结束
    }

}


int cal_cus_n(Cus *total[],int cycle_now)
{
    int n=0;
    Cus *temp=total[cycle_now];
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    return n;
}

int deal(Cus *total[],Cus *win[],int win_n)
{
    static int cus_cycle_n=0;//当前处理客户的周期

}

int check_win(Cus *win[],int win_n)
{

}