#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    int allnum, nownum1, nownum2,nowposi1,nowposi2 ,nowtime; //呼叫总人数，电梯内人数，1号电梯目前位置, 2号电梯目前位置，电梯运行时间
    int psta[10];//各人起点
    int pdes[10];//各人终点
    int ptime[10];//各人间隔时间

    printf("请分别输入两个电梯的初始位置\n");
    scanf("%d  %d", &nowposi1, &nowposi2);

    printf("请提前输入同时召唤电梯的人数 \n");
    printf("请注意一台电梯限乘四人\n");
    printf("按q以退出\n");
    scanf("%d", &allnum);

    if (allnum != 0)
        printf("请输入同时按下电梯的每个人的 起点 、目的地、情景开始后呼叫电梯的间隔时间，用空格隔开\n");
    nownum1= 0;
    nownum2 = 0;

    nowtime = 0;

    //存入乘客的起止
    int i;
    for (i = 0; i < allnum; i++)
    {
        printf("第%d位:\n", i + 1);
        scanf("%d %d %d", &psta[i], &pdes[i], &ptime[i]);
    }


    printf("一号电梯目前楼层  一号电梯内人数  电梯运行时间\n");
    printf("%4d               %4d             %4d\n", nowposi1, nownum1, nowtime);

    printf("二号电梯目前楼层  二号电梯内人数  电梯运行时间\n");
    printf("%4d               %4d             %4d\n", nowposi2, nownum2, nowtime);

    int m;
    int p1 = 0;
    int p2 = 0;
    int n = 0;


    
    //电梯上升至每一层时进行以下检验
    while (nowposi1 < 11 && nowposi1>0)
    {

        //出人
        
        for (i = 0; i < allnum; i++)//对某一楼层进行终点检验
        {
            if (nowposi1 == pdes[i] && psta[i] == -1)//对该终点进行起点检验(1)
            {
                nownum1 = nownum1 - 1;
                pdes[i] = -1;
                psta[i] = -2;
                printf("1号电梯的目前楼层  电梯内人数  电梯运行时间\n");
                printf("%4d                %4d         %4d\n", nowposi1, nownum1, nowtime);
            }
            else if (nowposi2 == pdes[i] && psta[i] == -1)//对该终点进行起点检验(2)
            {
                nownum2 = nownum2 - 1;
                pdes[i] = -1;
                psta[i] = -2;
                printf("2号电梯的目前楼层  电梯内人数  电梯运行时间\n");
                printf("%4d                %4d         %4d\n", nowposi2, nownum2, nowtime);
            }
        }


        //进人      

        if (nownum1 < 4)//对某一楼层进行超载检验(1)
        {
            for (m = 0; m < allnum; m++)//对某一楼层进行起点检验
            {
                if (nowposi1 == psta[i] && ptime[i] <= nowtime)//对该起点进行时间检验
                {
                    nownum1 = nownum1 + 1;
                    psta[i] = -1;
                    printf("1号电梯目前楼层  电梯内人数  电梯运行时间\n");
                    printf("%4d       %4d       %4d\n", nowposi1, nownum1, nowtime);
                }
            }
        }
        else if(nownum2 < 4)//对某一楼层进行超载检验(1)
        {
            for (m = 0; m < allnum; m++)//对某一楼层进行起点检验
            {
                if (nowposi2 == psta[i] && ptime[i] <= nowtime)//对该起点进行时间检验
                {
                    nownum2 = nownum2 + 1;
                    psta[i] = -1;
                    printf("2号电梯目前楼层  电梯内人数  电梯运行时间\n");
                    printf("%4d       %4d       %4d\n", nowposi2, nownum2, nowtime);
                }
            }
        }
        //电梯上升或下降一层       
         //检验上行或下行 

        if (nowposi1 == 10)
            p1 = 1;
        if (nowposi1 == 1)
            p2= 0;

        if (p1 == 0)
        {
            for (m = nowposi1; m < 11; m++)//对当前位置及以上楼层逐一进行起点和终点检测
            {
                for (i = 0; i < allnum; i++)
                {
                    if (nownum == 4 && nowposi == pdes[i] && psta[i] == -1)
                        n++;

                    else if (nownum < 4 && ((nowposi == pdes[i] && psta[i] == -1) || (nowposi == psta[i]) || (ptime > nowtime + m - nowposi)))
                        n++;
                }
            }
            if (n != 0)//即有目的地
                p1 = 0;
            else
                p1 = 1;
        }

        if (p == 1)
        {
            for (m = nowposi; m > 0; m--)//对当前位置及以下楼层逐一进行起点和终点检测
            {
                for (i = 0; i < allnum; i++)
                {
                    if (nownum == 4 && nowposi == pdes[i] && psta[i] == -1)
                        n++;
                    else if (nownum < 4 && ((nowposi == pdes[i] && psta[i] == -1) || (nowposi == psta[i])))
                        n++;
                }
            }
            if (n != 0)//即有目的地
                p = 1;
            else
                p = 0;
        }


        if (p == 0)
        {
            nowposi++;
            nowtime++;
        }
        if (p == 1)
        {
            nowposi--;
            nowtime++;
        }


        //检验运送任务完成
        int done = 0;
        for (i = 0; i < allnum; i++)
        {
            if (pdes[i] == -1)
                done++;
        }
        if (done == allnum)
            break;

    }
    return 0;
}
