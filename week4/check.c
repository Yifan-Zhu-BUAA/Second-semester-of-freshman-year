//检查括号是否匹配，我打算先把括号都放到一个队列中再进行检查，括号用一个结构体来顺带上行号吧
#include <stdio.h>
#include <stdlib.h>
typedef struct bracket
{
    char bra;
    int row;
} Bracket;

Bracket *example[200]={NULL};

Bracket *creat(int row,char bra)
{
    Bracket *br;
    br=(Bracket *)malloc(sizeof(Bracket));
    br->row=row;
    br->bra=bra;
    return br;
}
void print_example(void)
{
    int n=0;
    while(example[n]!=NULL)
    {
        printf("%c",example[n]->bra);
        n++;
    }
}

void print_not(char bra,int row)
{
    printf("without maching '%c' at line %d",bra,row);
}

void push(FILE *fp)//用来把括号都塞进去
{
    int row=1,n=0;
    char bra,front;
    while(1)
    {
        bra=fgetc(fp);
        if (bra==EOF) break;
        if (bra=='{' || bra=='}' || bra=='(' || bra==')' )
        {
            example[n++]=creat(row,bra);
        }
        else if (bra=='\n') row++;
        else if (bra=='/')
        {
            bra=fgetc(fp);
            if (bra=='/')
            {
                while((bra=fgetc(fp))!='\n' && bra!=EOF);
                if (bra=='\n') row++;
            }
            else if (bra=='*')
            {
                bra=fgetc(fp);
                while(1)//第五个测试点解决啦、解决了/***/
                {
                    front=bra;
                    bra=fgetc(fp);
                    if (bra=='\n') row++;
                    else if(front=='*')
                    {
                        if (bra=='/') break;
                    }
                    if (bra==EOF) break;
                }
            }
            if (bra==EOF) break;
        }
        else if (bra=='"')
        {
            while(1)
            {
                bra=fgetc(fp);
                if (bra==EOF) break;
                if (bra=='\n') row++;
                else if(bra=='"') break;
            }
        }
        else if (bra=='\'')
        {
            while(1)
            {
                bra=fgetc(fp);
                if (bra==EOF) break;
                if (bra=='\n') row++;
                else if(bra=='\'') break;
            }
        }
        // else if(bra=='/')
        // {
        //     bra=fgetc(fp);
        //     if (bra==EOF) break;
        //     if (bra=='/')
        //     {
        //         while (1)
        //         {
        //             bra=fgetc(fp);
        //             if (bra==EOF) break;
        //             if (bra=='\n')
        //             {
        //                 row++;
        //                 break;
        //             }
        //         }
        //     }
        //     else if (bra=='*')
        //     {
        //         while (1)
        //         {
        //             bra=fgetc(fp);
        //             if (bra=='\n') row++;
        //             else if (bra=='*')
        //             {
        //                 if (( bra=fgetc(fp) )=='/') break;
        //                 else if (bra=='\n') row++;
        //             }   
        //         }
        //     }
        //     else if (bra=='\n') row++;
        // }
        // else if(bra=='"')
        // {
        //     while (1)
        //     {
        //         bra=fgetc(fp);
        //         if (bra==EOF) break;
        //         if (bra=='\n') row++;
        //         else if (bra=='"') break;
        //     }
        // }
        // else if (bra=='\n') row++;
        // if (bra==EOF) break;
    }
}

void check_check(void)//用来检查括号匹配情况
{
   Bracket *stack[200]={NULL};
   int n=0,top=-1,flag=0;
   while(example[n]!=NULL)
    {
        if (example[n]->bra=='{')
        {
            if (top==-1) stack[++top]=example[n++];
            else if (stack[top]->bra=='(')
            {
                print_not(stack[top]->bra,stack[top]->row);
                flag=1;
                break;                
            }
            else stack[++top]=example[n++]; 
        } 
        else if (example[n]->bra=='(') stack[++top]=example[n++];
        else if (example[n]->bra=='}')
        {
            if (top==-1) 
            {
                print_not(example[n]->bra,example[n]->row);
                flag=1;
                break;
            }
            else if (stack[top]->bra=='{')
            {
                top--;
                n++;
            }
            else 
            {
                print_not(example[n]->bra,example[n]->row);
                flag=1;
                break;
            }
        }
        else if (example[n]->bra==')')
        {
            if (top==-1)
            {
                print_not(example[n]->bra,example[n]->row);
                flag=1;
                break;
            }
            else if (stack[top]->bra=='(')
            {
                top--;
                n++;
            }
            else 
            {
                print_not(example[n]->bra,example[n]->row);
                flag=1;
                break;
            }
        }
    }
    if (flag==0)
    {
        if (top==-1) print_example();
        else print_not(stack[0]->bra,stack[0]->row);
    }
}

int main(void)
{
    FILE *fp=NULL;
    fp=fopen("example.c","r");
    push(fp);
    check_check();
    fclose(fp);
}