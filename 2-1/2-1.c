#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)

 {
    int allnum, nownum, nowposi, nowtime; //呼叫总人数，电梯内人数，电梯目前位置,电梯运行时间
    int psta[10];//各人起点
    int pdes[10];//各人终点
    int ptime[10];//各人间隔时间

    printf("请输入电梯的初始位置\n");
    scanf("%d", &nowposi);
    
    printf("请提前输入同时召唤电梯的人数 \n");
    printf("请注意电梯限乘四人\n");
    printf("按q以退出\n");
    scanf("%d", &allnum);

    if (allnum != 0)
        printf("请输入同时按下电梯的每个人的 起点 、目的地、情景开始后呼叫电梯的间隔时间，用空格隔开\n");
    nownum = 0;
    nowtime = 0;

    //存入乘客的起止
    int i;
    for (i = 0; i < allnum; i++)
    {
        printf("第%d位:\n", i + 1);
        scanf("%d %d %d", &psta[i], &pdes[i], &ptime[i]);
    }

    
    printf("目前楼层  电梯内人数  电梯运行时间\n");
    printf("%4d       %4d       %4d\n", nowposi, nownum, nowtime);

     
        int p = 0;
        
    //电梯上升至每一层时进行以下检验
    while (nowposi < 11 && nowposi>0)
    {
       int m;
       int n = 0;
        //出人

        for (i = 0; i < allnum; i++)//对某一楼层进行终点检验
        {
            if (nowposi == pdes[i] && psta[i] == -1)//对该终点进行起点检验
            {
                nownum = nownum - 1;
                pdes[i] = -1;
                psta[i] = -2;
                printf("%4d       %4d       %4d\n", nowposi, nownum, nowtime);
            }
        }

        //进人     

        if (nownum < 4)//对某一楼层进行超载检验
        {
            for (i = 0; i < allnum; i++)//对某一楼层进行起点检验
            {
                if (nowposi == psta[i]&&(ptime[i]<=nowtime))//对该起点进行时间检验
                {
                    nownum = nownum + 1;
                    psta[i] = -1;
                    printf("%4d       %4d       %4d\n", nowposi, nownum, nowtime);
                }
            }
        }
        //电梯上升或下降一层       
         //检验上行或下行 

        

        if (p == 0)
        {
            for (m = nowposi; m < 11; m++)//对当前位置及以上楼层逐一进行起点和终点检测
            {
                for (i = 0; i < allnum; i++)
                {
                    if (nownum == 4 && m == pdes[i] && psta[i] == -1)
                        n++;

                    if (nownum < 4 && ((m == pdes[i] && psta[i] == -1) || ((m == psta[i]) && (ptime[i] <= nowtime + m - nowposi))))
                        n++;
                }
            }
            if (n != 0)//即有目的地
                p = 0;
            else
                p = 1;
        }

        if (p == 1)
        {
            for (m = nowposi; m > 0; m--)//对当前位置及以下楼层逐一进行起点和终点检测
            {
                for (i = 0; i < allnum; i++)
                {
                    if (nownum == 4 && m == pdes[i] && psta[i] == -1)
                        n++;
                    if (nownum < 4 && ((m == pdes[i] && psta[i] == -1) ||( (m == psta[i]) && (ptime[i] <= nowtime + nowposi-m))))
                        n++;
                }
            }
            if (n != 0)//即有目的地
                p = 1;
            else
                p = 0;
        }

        if (nowposi == 10)
            p = 1;
        if (nowposi == 1)
            p = 0;

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
