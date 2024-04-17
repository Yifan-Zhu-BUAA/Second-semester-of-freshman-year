#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ph
{
    char name[21];
    char num[12];
    struct ph* next;
} PH;

void insert(PH **head,PH **insert_one);
PH* creat(char name[21],char num[12],PH *next);

int main()
{
    int n;
    char name[21],num[12];
    PH *head,*next;
    scanf("%d",&n);
    scanf("%s %s",name,num);
    head=creat(name,num,NULL);
    for (int i=1;i<n;i++)
    {
        /*一个个插进来*/
        scanf("%s %s",name,num);
        next=creat(name,num,NULL);
        insert(&head,&next);
    }
    next=head;
    while(next!=NULL)
    {
        /*一个个打印出来*/
        printf("%s %s\n",next->name,next->num);
        next=next->next;
    }

}

void insert(PH **head,PH **insert_one)
{
    /*插入下电话*/
    if(strcmp((*insert_one)->name,(*head)->name)<0)
    {
        /*如果小于表头就把插入的变成表头*/
        PH *tmp;
        tmp=*head;
        *head=*insert_one;
        *insert_one=tmp;
        (*head)->next=*insert_one;
        return;
    }
    PH *be=*head,*af=(*head)->next;//这里的be表示前一个,af是后面的
    here:
    while( (af!=NULL ) && strcmp((*insert_one)->name,af->name)>=0 )
    {   /*找到insert_one该插入的位置*/
        be=be->next;
        af=af->next;
    }
    if(strcmp((*insert_one)->name,be->name)==0)
    {   //看看是不是完全相同,相同则不操作
        if (strcmp((*insert_one)->num,be->num)==0) return;
        //如果名字相同就处理下名字
        char name_be[21];
        int n=0;
        strcpy(name_be,be->name);
        while(name_be[n++]!='\0');
        n-=3;//定位到可能出现_的位置
        if(n>0 && name_be[n]=='_')
        {   //如果已经是_1的形式就把数字加一
            name_be[n+1]=name_be[n+1]+1;
        }
        else 
        {   //不然就在后面加_1
            n+=2;
            name_be[n++]='_';
            name_be[n++]='1';
            name_be[n]='\0';
        }
        strcpy((*insert_one)->name,name_be);
        if((af!=NULL ) && strcmp((*insert_one)->name,af->name)==0) goto here;
    }
    (*insert_one)->next=be->next;
    be->next=(*insert_one);
}

PH* creat(char name[21],char num[12],PH *next)
{
    PH* thisone=(PH *)malloc(sizeof(PH));
    if(NULL==thisone)
    {
        printf("error");
        return NULL;
    }
    strcpy(thisone->name,name);
    strcpy(thisone->num,num);
    thisone->next=next;
    return thisone;
}