#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRMAX 21

typedef struct fun
{
    char fun_name[STRMAX];
    char invoke_name[10][STRMAX];
    int invoke_num;
} Fun;


Fun *stack[100];
int stack_num=-1;
Fun *list_fun[100];
int list_num=0;

int invoke_check(Fun *fp,char fun_name[STRMAX]);//检查是否已经调用过,是就输出1
int in_list(char fun_name[STRMAX]);//检查是否在list中，是返回位置否则返回-1

int main(void)
{
    int op,invoke_num,i;//op表示输入
    char fun_name[STRMAX];
    Fun *funp=NULL;
    do
    {
        /* code */
        scanf("%d",&op);
        if (op==8)
        {
            scanf("%s",fun_name);
            if (stack_num==-1)
            {
                funp=malloc(sizeof(Fun));
                strcpy(funp->fun_name,fun_name);
                funp->invoke_num=0;
                list_fun[list_num++]=funp;
                stack[++stack_num]=funp;
            }
            else
            {
                if( (i=in_list(fun_name)) ==-1)
                {//当不在list里时创建函数并加入进list中
                    funp=malloc(sizeof(Fun));
                    strcpy(funp->fun_name,fun_name);
                    funp->invoke_num=0;
                    list_fun[list_num++]=funp;
                }
                else funp=list_fun[i];//不在时也要把他找出来

                if( ! invoke_check(stack[stack_num],fun_name))
                {//没被调用过时
                    invoke_num=stack[stack_num]->invoke_num;
                    strcpy(stack[stack_num]->invoke_name[invoke_num],fun_name);
                    stack[stack_num]->invoke_num++;
                }

                stack[++stack_num]=funp; //放入栈中

            } 
        }
        else if(op==0)
        {
            stack_num--;
        }
    } while (stack_num!=-1);//当栈不为空时继续检测

    for (int i=0;i<list_num;i++)
    {
        int n=list_fun[i]->invoke_num;
        if (n>0)
        {
            printf("%s:",list_fun[i]->fun_name);
            int j;
            for (j=0;j<n-1;j++)
            {
                printf("%s,",list_fun[i]->invoke_name[j]);
            }
            printf("%s\n",list_fun[i]->invoke_name[j]);
        }
    }
}

int invoke_check(Fun *fp,char fun_name[STRMAX])
{
    int n=fp->invoke_num;
    for (int i=0;i<n;i++)
    {
        if(strcmp(fp->invoke_name[i],fun_name)==0)//检查函数名是不是一样
        {
            return 1;
        }
    }
    return 0;
}

int in_list(char fun_name[STRMAX])
{
    if (list_num==0) return 0;
    for (int i=0;i<list_num;i++)
    {
        if (strcmp(list_fun[i]->fun_name,fun_name)==0) return i;
    }
    return -1;
}