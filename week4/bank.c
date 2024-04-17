#include <stdio.h>

typedef struct custom
{
    int id;
    int time_type;//直接当做周期来用
    int wait_time;//排队时间
} cus;

cus que[200];//用来储存队列
int head=0,tail=0;//head是队头，tail是队尾

int win[5];
int win4_open=0,win5_open=0,win_num=3;//开了就是1，没开就是0,win_num表示开启的窗口数量
void win_deal(void);
void print_que(void);

int main(void)
{
    int n=0,id=1,time_type=0,temp=0;
    scanf("%d",&n);
    int cycle[n],cycle_n;//表示每个周期来的人数
    for (int i=0;i<n;i++)
    {//先读取每个周期来多少人
        scanf("%d",&cycle_n);
        cycle[i]=cycle_n;
    }
    int cy_now=0;//表示当前轮数
    while(1)
    {
        if (cy_now<n)
        {
            for (int j=0;j<cycle[cy_now];j++)
            {//客户进入队列
                scanf("%d",&time_type);
                que[tail].id=id++;
                que[tail].time_type=time_type;
                que[tail].wait_time=0;
                tail++;
            }
            cy_now++;//周期加1
            if ((tail-head)/(float)win_num>=7.0 && win_num<=5)
            {//检测到排队人数除以窗口数大于等于七则加窗口
                if (win4_open==0)
                {
                    win_num++;
                    win4_open=1;
                }
                else if (win5_open==0)
                {
                    win_num++;
                    win5_open=1;
                }
            }
            if ((tail-head)/(float)win_num>=7.0 && win_num<=5)
            {//检测到排队人数除以窗口数大于等于七则加窗口
                if (win4_open==0)
                {
                    win_num++;
                    win4_open=1;
                }
                else if (win5_open==0)
                {
                    win_num++;
                    win5_open=1;
                }
            }
        }

        win_deal();

        for (int i=head;i<tail;i++)
        {//在队列中的人等待周期加1
            que[i].wait_time++;
        }

        while (win_num>3 && (tail-head)/(float)win_num<7.0 && temp!=head)
        {//当有人进入窗口时，检测到排队人数除以窗口数小于七则减窗口
            win_num--;
            if (win5_open==1) win5_open=0;
            else win4_open=0;
        }
        temp=head;
        if (cy_now==n && head == tail) break;//当队头大于队尾就是没人时,并且接收客户接收完了就结束周期
    }

    print_que();
}

void win_deal()
{

    for (int i=0;i<3;i++)
    {//先接受客户
        if (win[i]==0 && head<tail)
        {
            win[i]=que[head++].time_type;
        }
    }
    if (win4_open>0 && win[3]==0 && head<tail) win[3]=que[head++].time_type;
    if (win5_open>0 && win[4]==0 && head<tail) win[4]=que[head++].time_type;

    for (int i=0;i<5;i++)
    {//处理业务
        if(win[i]>0) win[i]--;
    }

}

void print_que()
{
    for (int i=0;i<tail;i++)
    {
        printf("%d : %d\n",que[i].id,que[i].wait_time);
    }
}

