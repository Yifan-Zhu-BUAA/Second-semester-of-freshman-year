#include <stdio.h>

int board[19][19];

void init(int board[][19]);
int check(int row,int col);

int main()
{
    init(board);
    for (int row=0;row<19;row++)
    {
        for (int col=0;col<19;col++)
        {
            if (check(row,col)==1)
            {
                printf("%d:%d,%d\n",board[row][col],row+1,col+1);
                goto here;
            }
        }
    }
    printf("NO\n");return 0;
    here:return 0;
}

void init(int board[][19])
{
    for (int row=0;row<19;row++)
    {
        for (int col=0;col<19;col++)
        {
            scanf("%d",&board[row][col]);
        }
    }
}

int check(int row,int col)
{
    int type=board[row][col];
    if (type==0) return 0;
    int i,j,che=1;
    for (i=1,j=0;i<=3;i++)//检查横的
    {
        if ((row+i)>18) {che=0;break;}
        if (board[row+i][col]!=type) {che=0;break;}
    }
    if(che==1)
    {
        if ((row+i)<19 && board[row+i][col]==0) return 1;
        else if ((row-1)>=0 && board[row-1][col]==0) return 1;
    }

    che=1;
    for (i=0,j=1;j<=3;j++)//检查竖的
    {
        if ((col+j)>18) {che=0;break;}
        if (board[row][col+j]!=type) {che=0;break;}
    }
    if(che==1)
    {
        if ((col+j)<19 && board[row][col+j]==0) return 1;
        else if ((col-1)>=0 && board[row][col-1]==0) return 1;
    }

    che=1;
    for (i=1,j=1;j<=3;i++,j++)//检查右下对角线
    {
        if ((col+j)>18 || (row+i)>18) {che=0;break;}
        if (board[row+i][col+j]!=type) {che=0;break;}
    }
    if(che==1)
    {
        if (((row+i)<19 && (col+j)<19) && board[row+i][col+j]==0) return 1;
        else if ((row-1)>=0 && (col-1)>=0)
        {
            if (board[row-1][col-1]==0) return 1;
        }
    }

    che=1;
    for (i=1,j=1;j<=3;i++,j++)//检查左下对角线
    {
        if ((col-j)<0 || (row+i)>18) {che=0;break;}
        if (board[row+i][col-j]!=type) {che=0;break;}
    }
    if(che==1)
    {
        if (((row+i)<19 && (col-j)>=0) && board[row+i][col-j]==0) return 1;
        else if ((row-1)>=0 && (col+1)<19)
        {
            if (board[row-1][col+1]==0) return 1;
        }
    }
    
    return 0;
}