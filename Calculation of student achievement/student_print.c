//
//  student_print.c
//  hello-c
//
//  Created by lfzyx on 15/3/25.
//  Copyright (c) 2015年 lfzyx. All rights reserved.
//

#include <stdio.h>
#include "Header.h"
#include "student_average.h"

void student_print(const Student *pStudent)     //    输出一个学生的数据，包括平均成绩
{
    int index;
    printf("no\tname\tscore1\tscore2\tscore2\taverage\n");
    for (index = 0; index < MAXSTUDENTS; index++)
    {
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%g\t\t\n",index+1,pStudent[index].name,pStudent[index].score[0],pStudent[index].score[1],pStudent[index].score[2],student_average(&pStudent[index]));
    }
}