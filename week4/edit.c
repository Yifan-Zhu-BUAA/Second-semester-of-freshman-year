#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 513
//编辑文本的操作，感觉很逆天作业量有点大,好像代码行并不多，合理分配函数后。
//要求有操作，撤销操作，可以用栈储存操作，1和2 的插入和删除也应该很简单反过来就行了

typedef struct op
{
    int op;
    int pos;
    char op_str[101];
} Opdate;

void insert(char in[],int pos_n,char str[]);//将pos插入到str中
void delete(char str[],int pos_n,int n_len);//将str的第pos_n位置删除n_len个
Opdate *creat_op(int op,int pos,char op_str[]);
void op_undo(void);//撤销操作



Opdate *stack[100];
int stack_top=-1;
char str[MAX];

int main(void)
{
    int n,op,pos,n_len;//n用来计数的
    char op_str[101];
    Opdate *fop;
    gets(str);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %s",&op,&pos,op_str);
        // printf("%d %d %s\n",op,pos,op_str);
        fop=creat_op(op,pos,op_str);
        stack[++stack_top]=fop;
    }
    while (1)
    {
        scanf("%d",&op);
        if (op==-1) break;
        if (op==3) op_undo();
        else if(op==1)//为1时
        {
            scanf("%d %s",&pos,op_str);
            fop=creat_op(op,pos,op_str);
            insert(op_str,pos,str);
            stack[++stack_top]=fop;
        }
        else//操作数为2时
        {
            scanf("%d %d",&pos,&n_len);

            int i;
            for (i=0;i<n_len;i++)
            {
                op_str[i]=str[i+pos];
            }
            op_str[i]='\0';

            delete(str,pos,n_len);
            fop=creat_op(op,pos,op_str);
            stack[++stack_top]=fop;
        }
    }
    // for (int i=0;i<stack_top+1;i++)
    // {
    //     printf("%d %d %s\n",stack[i]->op,stack[i]->pos,stack[i]->op_str);
    // }
    printf("%s",str);
}

Opdate *creat_op(int op,int pos,char op_str[])
{
    Opdate *fop;
    fop=(Opdate *)malloc(sizeof(Opdate));
    fop->op=op;
    fop->pos=pos;
    strcpy(fop->op_str,op_str);
    return fop;
}

void insert(char in[],int pos_n,char str[])
{
    int in_n=strlen(in),str_n=strlen(str);
    for (int i=in_n+str_n;i>pos_n;i--)
    {
        str[i]=str[i-in_n];
    }
    for (int i=0;i<in_n;i++)
    {
        str[pos_n+i]=in[i];
    }
}

void delete(char str[],int pos_n,int n_len)
{
    int n_str=strlen(str),i;
    for (i=pos_n;i<n_str-n_len;i++)
    {
        str[i]=str[i+n_len];
    }
    str[i]='\0';
}

void op_undo(void)
{
    if (stack_top==-1) return;
    Opdate *fop;
    int n_len=0;
    fop=stack[stack_top--];
    if (fop->op==1)
    {
        n_len=strlen(fop->op_str);
        delete(str,fop->pos,n_len);
    }
    else
    {
        insert(fop->op_str,fop->pos,str);
    }
}