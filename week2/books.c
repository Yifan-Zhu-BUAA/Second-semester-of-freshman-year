#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//创建BOOK,整理(第一次把所有书录入)，录入，查找，删除，打印，判断关键字（应该在替换关键字那有函数可以抄）

typedef struct book
{
    char name[51];
    char author[21];
    char pu_house[31];
    char pu_date[11];
    struct book *next;
} BOOK;

BOOK* book_creat(char name[],char author[],char pu_house[],char pu_date[]);
BOOK* book_insert(BOOK *head,BOOK *insert_one);//返回表头，发现这样就不用老是更换表头了
BOOK* book_delect_key(BOOK *head,char key_word[]);
void book_print(BOOK* book);
void book_print_file(FILE *fp,BOOK* book);
int check(char str[],char key_word[]);//判断str中有没有key_word
void book_show_key(BOOK *head,char key_word[]);//打印head这个书架的有关键字的出来
void book_destory(BOOK *head);//free掉所有内存

int main()
{
    FILE *fp=fopen("books.txt","r");
    char name[51],author[21],pu_house[31],pu_date[11],key_word[51];
    int n;
    BOOK *head=NULL,*now=NULL;
    // if (NULL==fp)
    // {
    //     perror("perror");
    //     return 1;
    // }
    if (fscanf(fp,"%s %s %s %s",name,author,pu_house,pu_date)!=EOF)
    {
        head=book_creat(name,author,pu_house,pu_date);
    }
    while(fscanf(fp,"%s %s %s %s",name,author,pu_house,pu_date)!=EOF)
    {
        now=book_creat(name,author,pu_house,pu_date);
        head=book_insert(head,now);
    }
    while(1)
    {
        scanf("%d",&n);
        if (n==0) break;
        else if(n==1)
        {
            scanf("%s %s %s %s",name,author,pu_house,pu_date);
            now=book_creat(name,author,pu_house,pu_date);
            head=book_insert(head,now);
        }
        else if(n==2)
        {
            scanf("%s",key_word);
            book_show_key(head,key_word);
        }
        else if(n==3)
        {
            scanf("%s",key_word);
            head=book_delect_key(head,key_word);
        }
    }
    FILE *fp_out=fopen("ordered.txt","w");
    now=head;
    while(now!=NULL)
    {
        book_print_file(fp_out,now);
        now=now->next;
    }
    book_destory(head);
}

BOOK* book_creat(char name[],char author[],char pu_house[],char pu_date[])
{
    BOOK *fp= (BOOK *)malloc(sizeof(BOOK));
    strcpy(fp->name,name);
    strcpy(fp->author,author);
    strcpy(fp->pu_house,pu_house);
    strcpy(fp->pu_date,pu_date);
    fp->next=NULL;
    return fp;
}

void book_print(BOOK* book)
{
    printf("%-50s%-20s%-30s%-10s\n",
    book->name,book->author,book->pu_house,book->pu_date);
}

BOOK* book_insert(BOOK* head,BOOK* insert_one)
{
    if (head==NULL)
    {
        return insert_one;
    }
    BOOK *be=head,*af=head->next;//这里的be表示前一个,af是后面的
    if (strcmp(insert_one->name,head->name)<0)
    {
        insert_one->next=head;
        return insert_one;
    }
    while( (af!=NULL ) && strcmp(insert_one->name,af->name)>=0 )
    {   /*找到insert_one该插入的位置*/
        be=be->next;
        af=af->next;
    }
    insert_one->next=be->next;
    be->next=insert_one;
    return head;
}

void book_print_file(FILE *fp,BOOK* book)
{
    fprintf(fp,"%-50s%-20s%-30s%-10s\n",
    book->name,book->author,book->pu_house,book->pu_date);
}

void book_show_key(BOOK *head,char key_word[])
{
    while(head!=NULL)
    {
        if(check(head->name,key_word)) book_print(head);
        head=head->next;
    }
}

int check(char str[],char key_word[])
{
    int i=0,j=0,str_n=strlen(str),ke_n=strlen(key_word);//i为str里面检测的开头
    if (str_n<ke_n) return 0;
    for (i=0;i<(str_n-ke_n+1);i++)
    {
        if (str[i]!=key_word[0]);
        else
        {
            for (j=0;j<ke_n;j++)
            {
                if(str[i+j]!=key_word[j]) break;
            }
            if (j==ke_n) return 1;
        }
    }
    return 0;
}

BOOK* book_delect_key(BOOK *head,char key_word[])
{
    BOOK *front=NULL,*now=NULL;
    if (head==NULL) return NULL;
    while(check(head->name,key_word))
    {
        front=head;
        head=head->next;
        free(front);
        if (head==NULL) return NULL;
    }

    front=head,now=head->next;
    while(now!=NULL)
    {
        if (check(now->name,key_word))
        {
            front->next=now->next;
            free(now);
            now=front->next;
        }
        else
        {
            front=now;
            now=now->next;
        }
    }
    return head;
}

void book_destory(BOOK *head)
{
    BOOK *tmp=NULL;
    while(head!=NULL)
    {
        tmp=head;
        head=head->next;
        free(tmp);
    }
}