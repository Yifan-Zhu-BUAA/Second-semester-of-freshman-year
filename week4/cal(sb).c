#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//运算符判断，如果符号优先级低于当前运算符则依次出栈，然后
//将当前的入栈,如果栈顶高于等于当前则入栈
char stack_cal[100],stack_c[100];//第一个是最终结果，第二个只是临时的
int cal_num[100];
char cal[100][10];
int n=0,n_num=0,top=-1;


int is_lower(char now)//返回1表示栈顶优先级低
{
    if (top==-1) return 0;
    if (now=='(' || stack_c[top]=='(') return 0;
    // 定义运算符优先级的字典
    char operators[] = {'+', '-', '*', '/'},top_c=stack_c[top];
    int precedence[] = {1, 1, 2, 2};
    int i, index_a = -1, index_b = -1;
    // 查找a和b在运算符数组中的索引
    for (i = 0; i < 4; i++) {
        if (top_c == operators[i]) {
            index_a = i;
        }
        if (now == operators[i]) {
            index_b = i;
        }
    }
    // 如果a和b都是有效的运算符
    if (index_a != -1 && index_b != -1) 
    {
        return (precedence[index_a] < precedence[index_b]) ? 1 : 0;
    }
}

void get_stack()
{
    char c,ch[200],temp[10];
    int i=0,j=0;
    gets(ch);
    while ( (c=ch[i]) != '=')
    {
        if (c==' ')
        {
            i++;
            continue;
        }
        if (isdigit(c))
        {
            j=0;
            while(isdigit(ch[i]))
            {
                temp[j++]=ch[i++];
            }
            temp[j]='\0';
            strcpy(cal[n_num],temp);
            n_num++;
        }
        // else if(c=='(')
        // {
        //     stack_c[++top]='(';
        // }
        else if(c==')')
        {
            while(stack_c[top]!='(')
            {
               temp[0]=stack_c[top--];
               temp[1]='\n';
               strcpy(cal[n_num],temp);
               n_num++;
            }
            top--;
            i++;
        }
        else
        {
            if (top==-1)//栈顶为空直接加
            {
                stack_c[++top]=c;
                i++;
            }
            else
            {
                while (is_lower(c) && top!=-1)//直到栈顶的优先级大于等于c,或者栈顶没有元素了
                {
                    temp[0]=stack_c[top--];
                    temp[1]='\n';
                    strcpy(cal[n_num],temp);
                    n_num++;
                }
                stack_c[++top]=c;
                i++;
            }
        }
    }
}

void calcu()
{
    printf("1");
}

int main(void)
{
    get_stack();
    calcu();
    // for (int i=0;i<n;i++)
    // {
    //     printf("%c ",stack_cal[i]);
    // }
    for (int i=0;i<n_num;i++)
    {
        printf("%s ",cal[i]);
    }
}