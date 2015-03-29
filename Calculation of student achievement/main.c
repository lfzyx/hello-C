//
//  main.c
//  hello-c
//
//  Created by lfzyx on 15/3/25.
//  Copyright (c) 2015年 lfzyx. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Header.h"
#include "student_average.h"
#include "student_get_score.h"
#include "student_input.h"
#include "student_print.h"

int main(int argv,char* argc[])
{
    printf("请输入要统计的学生数\n");
    scanf("%d",&MAXSTUDENTS);
    Student achievement[MAXSTUDENTS];
    student_print(student_input(achievement));
    student_get_score(achievement,MAXSTUDENTS);
    return 0;
}
