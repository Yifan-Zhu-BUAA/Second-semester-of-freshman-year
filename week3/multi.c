#include<stdio.h>
#include<stdlib.h>
typedef struct poly
{
    int a;
    int n;
    struct poly* next;
} PO;

PO *creat_poly();//用来创建first和second，返回头
PO *creat_po(int a,int n);//在creat_poly里面连接poly的
PO *insert_po(PO *in,PO *head);//应该只有在最后的final才会用到了
PO *creat_final(PO *first,PO *second,PO* final);//用来创建final的
void print_poly(PO *head);//最后输出的打印函数

int main()
{   
    PO *first=NULL,*second=NULL,*final=NULL,*temp,*next;
    first=creat_poly();
    second=creat_poly();
    // while(first!=NULL)
    // {
    //     printf("%d",first->a);
    //     first=first->next;
    // }
    temp=first;
    final=creat_final(first,second,final);
    // final=creat_final(second,first,final);
    print_poly(final);
}

PO *creat_poly()
{   
    int a,n;
    char c;
    PO *head=NULL,*temp=NULL,*next=NULL;
    while(1)
    {
        scanf("%d %d",&a,&n);
        next=creat_po(a,n);
        if(head==NULL)
        {
            head=next;
            temp=next;
        }
        else 
        {
            temp->next=next;
            temp=next;
        }
        if ((c=getchar())=='\n') return head;
    }
}

PO *creat_po(int a,int n)
{
    PO *p=(PO *)malloc(sizeof(PO));
    if (NULL==p)
    {
        printf("can't get the point");
        return NULL;
    }
    p->a=a;
    p->n=n;
    p->next=NULL;
    return p;
}

PO *creat_final(PO *first,PO *second,PO* final)
{
    PO *tmp_second=second,*tmp;
    int a,n;
    while(first!=NULL)
    {
        while(tmp_second!=NULL)
        {
            a=first->a * tmp_second->a;
            n=first->n+tmp_second->n;
            tmp=creat_po(a,n);
            final=insert_po(tmp,final);
            tmp_second=tmp_second->next;
        }
        first=first->next;
        tmp_second=second;
    }
    return final;
}

PO *insert_po(PO *in,PO *head)
{
    if (head==NULL) return in;
    PO *front=NULL,*next=NULL;
    if (in->n > head->n)
    {
        in->next=head;
        return in;
    }
    if (in->n==head->n) head->a+=in->a;
    front=head;
    next=front->next;
    while(next!=NULL)
    {
        if (in->n < next->n)
        {
            front=next;
            next=front->next;
        }
        else if (in->n == next->n)
        {
            next->a+=in->a;
            return head;
        }
        else
        {
            front->next=in;
            in->next=next;
            return head;
        }
    }
    if (next==NULL)
    {
        front->next=in;
        return head;
    }
}

void print_poly(PO *head)
{
    while(head!=NULL)
    {
        printf("%d %d ",head->a,head->n);
        head=head->next;
    }
}