#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    int allnum, nownum1, nownum2,nowposi1,nowposi2 ,nowtime; //������������������������1�ŵ���Ŀǰλ��, 2�ŵ���Ŀǰλ�ã���������ʱ��
    int psta[10];//�������
    int pdes[10];//�����յ�
    int ptime[10];//���˼��ʱ��

    printf("��ֱ������������ݵĳ�ʼλ��\n");
    scanf("%d  %d", &nowposi1, &nowposi2);

    printf("����ǰ����ͬʱ�ٻ����ݵ����� \n");
    printf("��ע��һ̨�����޳�����\n");
    printf("��q���˳�\n");
    scanf("%d", &allnum);

    if (allnum != 0)
        printf("������ͬʱ���µ��ݵ�ÿ���˵� ��� ��Ŀ�ĵء��龰��ʼ����е��ݵļ��ʱ�䣬�ÿո����\n");
    nownum1= 0;
    nownum2 = 0;

    nowtime = 0;

    //����˿͵���ֹ
    int i;
    for (i = 0; i < allnum; i++)
    {
        printf("��%dλ:\n", i + 1);
        scanf("%d %d %d", &psta[i], &pdes[i], &ptime[i]);
    }


    printf("һ�ŵ���Ŀǰ¥��  һ�ŵ���������  ��������ʱ��\n");
    printf("%4d               %4d             %4d\n", nowposi1, nownum1, nowtime);

    printf("���ŵ���Ŀǰ¥��  ���ŵ���������  ��������ʱ��\n");
    printf("%4d               %4d             %4d\n", nowposi2, nownum2, nowtime);

    int m;
    int p1 = 0;
    int p2 = 0;
    int n = 0;


    
    //����������ÿһ��ʱ�������¼���
    while (nowposi1 < 11 && nowposi1>0)
    {

        //����
        
        for (i = 0; i < allnum; i++)//��ĳһ¥������յ����
        {
            if (nowposi1 == pdes[i] && psta[i] == -1)//�Ը��յ����������(1)
            {
                nownum1 = nownum1 - 1;
                pdes[i] = -1;
                psta[i] = -2;
                printf("1�ŵ��ݵ�Ŀǰ¥��  ����������  ��������ʱ��\n");
                printf("%4d                %4d         %4d\n", nowposi1, nownum1, nowtime);
            }
            else if (nowposi2 == pdes[i] && psta[i] == -1)//�Ը��յ����������(2)
            {
                nownum2 = nownum2 - 1;
                pdes[i] = -1;
                psta[i] = -2;
                printf("2�ŵ��ݵ�Ŀǰ¥��  ����������  ��������ʱ��\n");
                printf("%4d                %4d         %4d\n", nowposi2, nownum2, nowtime);
            }
        }


        //����      

        if (nownum1 < 4)//��ĳһ¥����г��ؼ���(1)
        {
            for (m = 0; m < allnum; m++)//��ĳһ¥�����������
            {
                if (nowposi1 == psta[i] && ptime[i] <= nowtime)//�Ը�������ʱ�����
                {
                    nownum1 = nownum1 + 1;
                    psta[i] = -1;
                    printf("1�ŵ���Ŀǰ¥��  ����������  ��������ʱ��\n");
                    printf("%4d       %4d       %4d\n", nowposi1, nownum1, nowtime);
                }
            }
        }
        else if(nownum2 < 4)//��ĳһ¥����г��ؼ���(1)
        {
            for (m = 0; m < allnum; m++)//��ĳһ¥�����������
            {
                if (nowposi2 == psta[i] && ptime[i] <= nowtime)//�Ը�������ʱ�����
                {
                    nownum2 = nownum2 + 1;
                    psta[i] = -1;
                    printf("2�ŵ���Ŀǰ¥��  ����������  ��������ʱ��\n");
                    printf("%4d       %4d       %4d\n", nowposi2, nownum2, nowtime);
                }
            }
        }
        //�����������½�һ��       
         //�������л����� 

        if (nowposi1 == 10)
            p1 = 1;
        if (nowposi1 == 1)
            p2= 0;

        if (p1 == 0)
        {
            for (m = nowposi1; m < 11; m++)//�Ե�ǰλ�ü�����¥����һ���������յ���
            {
                for (i = 0; i < allnum; i++)
                {
                    if (nownum == 4 && nowposi == pdes[i] && psta[i] == -1)
                        n++;

                    else if (nownum < 4 && ((nowposi == pdes[i] && psta[i] == -1) || (nowposi == psta[i]) || (ptime > nowtime + m - nowposi)))
                        n++;
                }
            }
            if (n != 0)//����Ŀ�ĵ�
                p1 = 0;
            else
                p1 = 1;
        }

        if (p == 1)
        {
            for (m = nowposi; m > 0; m--)//�Ե�ǰλ�ü�����¥����һ���������յ���
            {
                for (i = 0; i < allnum; i++)
                {
                    if (nownum == 4 && nowposi == pdes[i] && psta[i] == -1)
                        n++;
                    else if (nownum < 4 && ((nowposi == pdes[i] && psta[i] == -1) || (nowposi == psta[i])))
                        n++;
                }
            }
            if (n != 0)//����Ŀ�ĵ�
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


        //���������������
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
