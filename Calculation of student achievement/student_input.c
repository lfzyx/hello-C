//
//  student_print.c
//  hello-c
//
//  Created by lfzyx on 15/3/25.
//  Copyright (c) 2015年 lfzyx. All rights reserved.
//

#include <stdio.h>
#include "Header.h"
Student* student_input(Student *pStudent)   //    输入一个学生的数据
{
    int count = 0;
    printf("你需要输入%d位学生的成绩\n",MAXSTUDENTS);
    while (count<MAXSTUDENTS)
    {
        
        printf("录入No.%d号学生成绩\n",count+1);
        printf("姓名:\n");
        scanf("%s",pStudent[count].name);
        int score = 0;
        while (score<3)
        {
            printf("score%d:\n",score+1);
            scanf("%d",&pStudent[count].score[score]);
            score++;
        }
        
        count++;
    }
    return pStudent;
}