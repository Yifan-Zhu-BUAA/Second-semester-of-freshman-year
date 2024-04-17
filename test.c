#include <stdio.h>
#include <ctype.h>
//运算符判断，如果符号优先级低于当前运算符则依次出栈，然后
//将当前的入栈,如果栈顶高于等于当前则入栈
char stack_c[100];
int stack_cal[100];
int n=0,top=-1,check[];

typedef struct custom
{
    int wait_time;
    int id;
    int type;//业务类型
    int in_time;//进来的时间周期
    struct custom *next;
} Cus;


void delete(char str[],int pos_n,int n_len)
{
    int n_str=strlen(str),i;
    for (i=pos_n;i<n_str-n_len;i++)
    {
        str[i]=str[i+n_len];
    }
    str[i]='\0';
}
int cal_cus_n(Cus *total[],int cycle_now)
{
    int n=0;
    Cus *temp=total[cycle_now-1];
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    return n;
}
char str[10]="abc",in[10]="jj";

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
int main(void)
{
    // Cus *total[2];
    // // creat_cus(total,2);
    // printf("%d\n",22/7);
    // int win=3,cus=50;
    // while(cus/win>=7)
    // {
    //     win++;
    //     printf("%d\n",win);
    // }
    // while(21/win<7)
    // {
    //     win--;
    //     printf("%d\n",win); 
    // }
    // printf("%d",21/3);
    int n=0;
    char str[11];
    if (! n) printf("1");
    scanf("%d",&n);
    scanf("%s",str);
    printf("%d %s\n",n,str);
}