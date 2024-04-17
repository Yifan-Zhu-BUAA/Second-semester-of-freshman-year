#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//重新写一份吧，真的太蠢了，重新做的这份就通过结构、枚举和联合来搞吧

typedef enum{num,oper} TYPE;
typedef union 
{
    /* 是字符或者是数字 */
    int num;
    char oper;
} data ;

typedef struct gpl
{
    //type是num就是储存的数字，是oper就是储存的运算符号
    TYPE utype;
    data da;
} GP;

int top=-1,n=0;
GP list_final[100];
char stack2[100];//这个才是栈


void creat_stack();//创建那个栈
float cal_stack();
int is_lower_or_equ(char now);//返回1表示栈顶优先级低


int main(void)
{
    creat_stack();
    // for (int i=0;i<n;i++)
    // {
    //     if (list_final[i].utype==num)
    //     {
    //         printf("%d ",list_final[i].da.num);
    //     }
    //     else
    //     {
    //         printf("%c ",list_final[i].da.oper);
    //     }
    // }
    printf("\n%.2f",cal_stack());
}

void creat_stack()
{
    char total[200];
    int i=0,j=0;//i是total下标，j是temp下标
    char temp[10],c;
    GP gp;
    gets(total);
    while(total[i]!='=')
    {
        c=total[i];
        if (c==' ')
        {
            i++;
            continue;
        }
        if (isdigit(c))
        {
            j=0;
            while(isdigit(total[i]))
            {
                temp[j++]=total[i++];
            }
            temp[j]='\0';
            gp.utype=num;
            gp.da.num=atoi(temp);
            list_final[n++]=gp;
        }
        else if (c=='(')
        {
            stack2[++top]=c;
            i++;
        }
        else if (c==')')
        {
            while(stack2[top]!='(')
            {
                gp.utype=oper;
                gp.da.oper=stack2[top--];
                list_final[n++]=gp;
            }
            top--;
            i++;
        }
        else//当是运算符时
        {
            while (is_lower_or_equ(c))
            {
                gp.utype=oper;
                gp.da.oper=stack2[top--];
                list_final[n++]=gp;
            }
            stack2[++top]=c;
            i++;
        }
    }
    while(top!=-1)//最后把栈里的所有元素丢出去
    {
        gp.utype=oper;
        gp.da.oper=stack2[top--];
        list_final[n++]=gp;
    }
}

int is_lower_or_equ(char now)
{
    if (top==-1) return 0;
    if (now=='(' || stack2[top]=='(') return 0;
    char operators[] = {'+', '-', '*', '/'},top_c=stack2[top];
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
        return (precedence[index_a] >= precedence[index_b]) ? 1 : 0;
    }
}

float cal_stack()
{
    float stack1[100];//后缀表达式计算结果
    int top1=-1;
    for(int i=0;i<n;i++)
    {
        if (i==0)
        {
            stack1[++top1]=list_final[i].da.num;
        }
        else
        {
            if (list_final[i].utype==num)//是数字就放进栈里
            {
                stack1[++top1]=list_final[i].da.num; 
            }
            else//计算
            {
                switch(list_final[i].da.oper)
                {
                    case '+':
                    stack1[top1-1]+=stack1[top1];
                    top1--;
                    break;
                    case '-':
                    stack1[top1-1]-=stack1[top1];
                    top1--;
                    break;
                    case '*':
                    stack1[top1-1]*=stack1[top1];
                    top1--;
                    break;
                    case '/':
                    stack1[top1-1]/=stack1[top1];
                    top1--;
                    break;
                }
            }
        }
    }
    return stack1[0];
}