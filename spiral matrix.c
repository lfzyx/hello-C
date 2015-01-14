//
//  spiral matrix.c
//  hello c
//
//  Created by lfzyx on 15/1/14.
//  Copyright (c) 2014年 lfzyx. All rights reserved.
//
#include <stdio.h>
#define N 9
void pri(int Array[][N], int a, int b);
void spiral(int spiral[][N], int x);
int main()
{
    int shuzu[N][N];//矩阵数组
    int a, b;//边长
    do
    {
        printf("求边长不大于9的螺旋矩阵\n");
        scanf("%d",&a);
    } while (a > 9 || a < 1);
    spiral(shuzu, a);//赋数组初值
    b = a;
    pri(shuzu, a, b);//打印数组
    return 0;
}

/**
 螺旋矩阵数组，要传入变长x
 **/
void spiral(int spiral[N][N], int x)
{
    int level = (x+1)/2;//算矩阵圈数公式
    int m=0;
    int len=1;//数组初值
    while (m < level)
    {
        int top;
        int right;
        int under;
        int left;
        x--;
        
        if (m==x)//计算矩形终点，最后一个值
        {
            spiral[m][x]=len;
            
        }
        else//计算各边
        {
            for(top = m;top < x;top++)
            {
                spiral[m][top]=len;
                //printf("上%d ",shuzu[m][top]);
                len++;
            }
            
            for(right = m; right < x; right++)
            {
                spiral[right][top]=len;
                // printf("右%d ",shuzu[right][top]);
                len++;
            }
            
            for(under = right;under > m;under--)
            {
                spiral[right][under]=len;
                // printf("下%d ",shuzu[right][under]);
                len++;
            }
            
            for(left = right;left > m;left--)
            {
                spiral[left][under]=len;
                //printf("左%d ",shuzu[left][under]);
                len++;
            }
        }
        m++;
    }
}

void pri(int Array[N][N], int a, int b)
{
    int x, y;
    for (x=0; x<a; x++)
    {
        for (y=0; y<b; y++)
        {
            printf("%d\t",Array[x][y]);
        }
        printf("\n");
    }
}