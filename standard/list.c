//本文件夹用于标准化我的所有数据结构函数等编写方式
//此文件为数组列表
#include<stdio.h>
#define MaxSize 100
int A[MaxSize];
int n;//表长

int searchElem(int list[ ], int n, int item)
{ //查找元素
    int i;
    for(i=0;i<n;i++)
        if(list[i]==item) 
            return  i ; /* 查找成功, 返回在表中位置 */
    return -1;             /*  查找失败, 返回信息-1 */
}

int insertElem(int list[],int i ,int item)
{//把item加入到第i位
    int k;
    if(n==MaxSize || i<0 || i>n)
        return -1;
    for (k=n-1;k>=i; k--)
        list[k+1]=list[k];
    list[i]=item;
    n++;
    return 1;
}

int deleteElem(int list[],int i)
{ //删除第i位
    int k;
    if(n==0 || i<0 || i>n-1)
    {
        return -1;
    }
    for (k=i+1;k<n;k++)
    {
        list[k-1]=list[k];
    }
    n--;
    return 1;
}

int main(void)
{
    int i;
    int list[MaxSize];
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    insertElem(list,2,3);
    deleteElem(list,0);
    for(i=0;i<n;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n%d",searchElem(list,n,3));
    return 0;
}
