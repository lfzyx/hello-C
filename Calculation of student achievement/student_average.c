//
//  ava.c
//  hello-c
//
//  Created by lfzyx on 15/3/25.
//  Copyright (c) 2015年 lfzyx. All rights reserved.
//

#include "Header.h"
double student_average(const Student *pStudent)     //      计算一个学生的平均成绩
{
    int index;
    double max=0;
    
    for (index = 0; index<3; index++)
    {
        max=max+pStudent->score[index];
    }
    max = max/3;
    return max;
}