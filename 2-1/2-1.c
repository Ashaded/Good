#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)

 {
    int allnum, nownum, nowposi, nowtime; //����������������������������Ŀǰλ��,��������ʱ��
    int psta[10];//�������
    int pdes[10];//�����յ�
    int ptime[10];//���˼��ʱ��

    printf("��������ݵĳ�ʼλ��\n");
    scanf("%d", &nowposi);
    
    printf("����ǰ����ͬʱ�ٻ����ݵ����� \n");
    printf("��ע������޳�����\n");
    printf("��q���˳�\n");
    scanf("%d", &allnum);

    if (allnum != 0)
        printf("������ͬʱ���µ��ݵ�ÿ���˵� ��� ��Ŀ�ĵء��龰��ʼ����е��ݵļ��ʱ�䣬�ÿո����\n");
    nownum = 0;
    nowtime = 0;

    //����˿͵���ֹ
    int i;
    for (i = 0; i < allnum; i++)
    {
        printf("��%dλ:\n", i + 1);
        scanf("%d %d %d", &psta[i], &pdes[i], &ptime[i]);
    }

    
    printf("Ŀǰ¥��  ����������  ��������ʱ��\n");
    printf("%4d       %4d       %4d\n", nowposi, nownum, nowtime);

     
        int p = 0;
        
    //����������ÿһ��ʱ�������¼���
    while (nowposi < 11 && nowposi>0)
    {
       int m;
       int n = 0;
        //����

        for (i = 0; i < allnum; i++)//��ĳһ¥������յ����
        {
            if (nowposi == pdes[i] && psta[i] == -1)//�Ը��յ����������
            {
                nownum = nownum - 1;
                pdes[i] = -1;
                psta[i] = -2;
                printf("%4d       %4d       %4d\n", nowposi, nownum, nowtime);
            }
        }

        //����     

        if (nownum < 4)//��ĳһ¥����г��ؼ���
        {
            for (i = 0; i < allnum; i++)//��ĳһ¥�����������
            {
                if (nowposi == psta[i]&&(ptime[i]<=nowtime))//�Ը�������ʱ�����
                {
                    nownum = nownum + 1;
                    psta[i] = -1;
                    printf("%4d       %4d       %4d\n", nowposi, nownum, nowtime);
                }
            }
        }
        //�����������½�һ��       
         //�������л����� 

        

        if (p == 0)
        {
            for (m = nowposi; m < 11; m++)//�Ե�ǰλ�ü�����¥����һ���������յ���
            {
                for (i = 0; i < allnum; i++)
                {
                    if (nownum == 4 && m == pdes[i] && psta[i] == -1)
                        n++;

                    if (nownum < 4 && ((m == pdes[i] && psta[i] == -1) || ((m == psta[i]) && (ptime[i] <= nowtime + m - nowposi))))
                        n++;
                }
            }
            if (n != 0)//����Ŀ�ĵ�
                p = 0;
            else
                p = 1;
        }

        if (p == 1)
        {
            for (m = nowposi; m > 0; m--)//�Ե�ǰλ�ü�����¥����һ���������յ���
            {
                for (i = 0; i < allnum; i++)
                {
                    if (nownum == 4 && m == pdes[i] && psta[i] == -1)
                        n++;
                    if (nownum < 4 && ((m == pdes[i] && psta[i] == -1) ||( (m == psta[i]) && (ptime[i] <= nowtime + nowposi-m))))
                        n++;
                }
            }
            if (n != 0)//����Ŀ�ĵ�
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
