#include <stdio.h>
#include <stdlib.h>

int check[95]={0};
int encode[95];

typedef struct loop
{
    char c;
    struct loop* next;
    struct loop* front;
} Loop;

Loop* creat_one(char c);//创建一个Loop
void printloop(Loop *head);//把内容都打印出来
void creat_encode(Loop *head);//创建整个encode，制作密文
Loop* c_encode(Loop *head);//对一次密文进行操作，用取余得到头，删除最初点位
void f_encode_print(FILE *fread,FILE *fout);

int main(void)
{
    char c;
    Loop *head=NULL,*front=NULL,*temp=NULL;
    FILE *fread,*fout;
    while((c=getchar())!='\n')
    {
        if (head==NULL)
        {
            head=creat_one(c);
            front=head;
            check[c-32]=1;
        }
        else if(check[c-32]==0)
        {
            temp=creat_one(c);
            front->next=temp;
            temp->front=front;
            front=temp;
            check[c-32]=1;
        }
    }
    for (int i=0;i<95;i++)
    {
        if (check[i]==0)
        {
            temp=creat_one(i+32);
            front->next=temp;
            temp->front=front;
            front=temp;
        }
    }
    front->next=head;
    head->front=front;
    creat_encode(head);

    // printloop(head);
    // for (int i=0;i<95;i++)
    // {
    //     printf("%c",encode[i]);
    // }
    fread=fopen("in.txt","r");
    if (fread==NULL)
    {
        return 1;
    }
    fout=fopen("in_crpyt.txt","w");
    if (fout==NULL)
    {
        return 1;
    }
    f_encode_print(fread,fout);
}

Loop* creat_one(char c)
{
    Loop *loop;
    loop=(Loop *)malloc(sizeof(Loop));
    loop->c=c;
    loop->next=NULL;
    loop->front=NULL;
    return loop;
}

void printloop(Loop *head)
{
    Loop *check=head;
    printf("%c ",head->c);
    head=head->next;
    while(head!=check)
    {
        printf("%c ",head->c);
        head=head->next;
    }
}

void creat_encode(Loop *head)
{
    char first=head->c;
    for (int i=0;i<94;i++)//搞成94？
    {
        head=c_encode(head);
    }
    encode[head->c-32]=first;
}

Loop* c_encode(Loop *head)
{
    Loop *tmp=head->front;//用来最后返回的
    static int count=95;//搞95就是方便我自己看而已，我就喜欢
    char ming=head->c;
    int step=ming%(count-1);
    count--;
    head->front->next=head->next;
    head->next->front=head->front;//删除head
    free(head);
    for (int i=0;i<step;i++)
    {
        tmp=tmp->next;
    }
    encode[ming-32]=tmp->c;
    return tmp;
}

void f_encode_print(FILE *fread,FILE *fout)
{
    int ch;
    while((ch=fgetc(fread)) != EOF)
    {
        if (ch>=32 && ch<=126)
        {
            fputc(encode[ch-32],fout);
        }
        else fputc(ch,fout);
    }
}