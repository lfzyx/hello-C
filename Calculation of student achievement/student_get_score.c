//
//  student_get_score.c
//  hello-c
//
//  Created by lfzyx on 15/3/25.
//  Copyright (c) 2015年 lfzyx. All rights reserved.
//

#include <stdio.h>
#include "Header.h"
int student_get_score(const Student *pStudent, int index)  //    获得学生的一个成绩
{
    int score = 0;
    double average[3][3] = {0};
    
    while (score<3)
    {
        int n=0;
        double minmax = 0;
        double min = pStudent[n].score[score];
        double max = pStudent[n].score[score];
        while (n<index)
        {
            minmax=minmax+pStudent[n].score[score];
            if (min>pStudent[n].score[score])
            {
                min=pStudent[n].score[score];
            }
            if (max<pStudent[n].score[score])
            {
                max=pStudent[n].score[score];
            }
            n++;
        }
        average[0][score] = minmax/index;
        average[1][score] = min;
        average[2][score] = max;
        
        score++;
    }
    char *line[] = {"average","min","max"};
    for (score=0; score<3; score++)
    {
        printf("\t%s",line[score]);
        int n=0;
        for (n=0; n<3; n++)
        {
            printf("\t\t%g",average[score][n]);
        }
        printf("\n");
    }
    return 0;
}