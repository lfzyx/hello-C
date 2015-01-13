//
//  main.c
//  hello c
//
//  Created by lfzyx on 14/12/1.
//  Copyright (c) 2014年 lfzyx. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 9
void pri(int shuzu[][N], int a, int b);//打印数组
void around(int shuzu[][N], int x);//螺旋矩阵数组
int main()
{

    int shuzu[N][N];
    int a, b;//边长
    do
    {
    printf("求边长不大于9的螺旋矩阵\n");
    scanf("%d",&a);
    }while (a>9||a<1);
    around(shuzu, a);//赋数组初值
    b=a;
    pri(shuzu,a,b);//打印数组
    return 0;
}

void around(int shuzu[][N], int x)
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
        
        top = m;
        do
        {
            shuzu[m][top]=len;
            //printf("上%d ",shuzu[m][top]);
            len++;
            top++;
        }while (top < x);
        
        right = m;
        do
        {
            shuzu[right][top]=len;
           // printf("右%d ",shuzu[right][top]);
            len++;
            right++;
        }while (right < x);
        
        under = right;
        do
        {
            shuzu[right][under]=len;
           // printf("下%d ",shuzu[right][under]);
            len++;
            under--;
        }while (under > m);
            
        left = right;
        do
        {
            shuzu[left][under]=len;
            //printf("左%d ",shuzu[left][under]);
            len++;
            left--;
        }while(left > m);
        
        m++;
    }
}

void pri(int shuzu[][N], int a, int b)
{
    int x, y;
    for (x=0; x<a; x++)
    {
        for (y=0; y<b; y++)
        {
            printf("%d\t",shuzu[x][y]);
        }
        printf("\n");
    }
}