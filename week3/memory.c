#include <stdio.h>
#include <stdlib.h>

typedef struct space
{
    int add;
    int size;
    struct space * next;
} SP;

SP * creat_spacelink(int n);//创建链表
SP * get_space(SP *head,int size);//得到空间，就是给了size去链表里找
SP *creat_space(int add,int size);//创建一个space
SP *cut_space(SP *front,SP *cut,int min);//给定了min后去修改链表
int print_spacelink(SP *head);

int main(void)
{
    int n,size;
    SP *head=NULL;
    scanf("%d",&n);
    head=creat_spacelink(n);
    if (head==NULL)
    {
        printf("can't get the space\n");
        return 1;
    }
    while (1)
    {

        scanf("%d",&size);
        if (size==-1) break;
        head=get_space(head,size);
        // print_spacelink(head);
        // printf("\n");
    }
    print_spacelink(head);
}

SP * creat_spacelink(int n)
{
    int add,size;
    SP *head=NULL,*front=NULL,*temp=NULL;
    scanf("%d %d",&add,&size);
    head=creat_space(add,size);
    front=head;
    for (int i=1;i<n;i++)
    {
        scanf("%d %d",&add,&size);
        temp=creat_space(add,size);
        front->next=temp;
        front=temp;
    }
    front->next=head;
    return head;
}

SP *creat_space(int add,int size)
{
    SP *space=NULL;
    space=(SP *)malloc(sizeof(SP));
    space->add=add;
    space->size=size;
    return space;
}

SP * get_space(SP *head,int size)
{
    int sub,min=-1;
    SP *cut=NULL,*now=head,*front=head,*cut_front=NULL;
    if(now==NULL) return NULL;
    sub=now->size-size;
    if (sub>=0)
    {
        min=sub;
        cut=now;
    }
    now=now->next;
    while(now!=head)
    {
        sub=now->size-size;
        if ( (sub>=0) )
        {
            if ( (min==-1) || (sub<min))
            {
                min=sub;
                cut=now;
                cut_front=front;
            }
        }
        // {
        //     min=sub;
        //     cut=now;
        // }
        front=now;
        now=now->next;
    }
    if (cut==head)
    {
        head=cut_space(front,cut,size);
    }
    else if (cut!=NULL)
    {
        head=cut_space(cut_front,cut,size);
    }
    return head;
}

SP *cut_space(SP *front,SP *cut,int size)
{
    SP *now=cut;
    cut->size-=size;
    if (cut->size==0)
    {
        if (front==cut) return NULL;
        front->next=cut->next;
        free(cut);
        cut=front->next;
    }
    return cut;
}

int print_spacelink(SP *head)
{
    if (NULL==head) return 1;
    SP *now=head;
    printf("%d %d\n",now->add,now->size);
    now=now->next;
    while(now!=head)
    {
        printf("%d %d\n",now->add,now->size);
        now=now->next;
    }
}