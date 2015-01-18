//
//  matrix saddle point.c
//  hello c
//
//  Created by lfzyx on 15/1/118.
//  Copyright (c) 2014年 lfzyx. All rights reserved.
//
// 由用户确定矩阵边长，然后输入矩阵数据，程序会找到该矩阵中的鞍点（鞍点是一个位置，在该位置上的元素是所在行上的最大数，同时是所在列上的最小数。一个矩阵也可能没有鞍点。）
#include <stdio.h>
int main()
{
    int n;//边长
    do
    {   printf("求边长不大于100的矩阵鞍点\n请输入边长\n");
        scanf("%d",&n);
    }while(n < 1 && n > 100);
    
    int shuzu[n][n];//矩阵数组
    int x,y;//x为行，y为列
    //**数组赋0值**//
    for (x=0; x<n; x++)
    {
        for (y=0; y<n; y++)
        {
            shuzu[x][y]=0;
        }
    }
    
    //**读取数组**//
    printf("请输入矩阵数据\n");
    for (x=0; x<n; x++)
    {
        for (y=0; y<n; y++)
        {
            scanf("%d",&shuzu[x][y]);
        }
    }
    
    //**输出数组**//
    for (x=0; x<n; x++)
    {
        for (y=0; y<n; y++)
        {
            printf("%d\t",shuzu[x][y]);
        }
        printf("\n");
    }
    
//*开始干活*//

    
    int all=0;//如果没有发现靶点，那就是0，需要根据此标记输出"NO"
    int MAXx = 0;//最大值的行下标
    int MAXy = 0;//最大值的列下标
    //遍历数组，将最大的赋值给MAX
    
    for (x=0; x<n&&all==0; x++)
    {
        int MAX=0;//假设最大值
        for(y=0; y<n; y++)
        {
            if (MAX<shuzu[x][y])
            {
                MAX=shuzu[x][y];
                MAXx=x;
                MAXy=y;
            }
        }
        //printf("%d",shuzu[MAXx][MAXy]);
        
        //发现了该行的最大值，赶紧看看该值是不是该列最小的
        
            int flat=1;
            int z;
            for (z=0; z<n&&flat==1; z++)
            {
                if (shuzu[MAXx][MAXy]>shuzu[z][MAXy])//用该行的最大值和所在列的数值依次对比
                {
                    flat=0;//如果不是最小的，就置为0，不再循环
                }
            }

            if (flat==1)//flat为1说明是该列最小的
            {
                printf("鞍点行标%d 列标%d",MAXx,MAXy);//这个数是行中最大列中最小
                all=1;//发现鞍点，停止所有循环
            }
    }

    if (all==0)
    {
        printf("没有发现鞍点");
    }
    
    return 0;
}

