#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int stman, des, stele;
int time, manum;
int control;
int main(void)
{
	printf("��ֱ�����������ڵ�¥�㡢\n���˵�Ŀ�ĵء�\n");
	printf("�Լ�Ŀǰ�������ڵء�\n");
	printf("���ÿո�������֣��벻Ҫʹ�ñ�㡣");
	printf("����q���˳���\n");
	control = scanf("%3d %3d %3d\n", &stman, &des, &stele);
	time = 0;
	manum = 0;
	while (control == 3)
	{
		printf("¥��    ��������ʱ��    �����е�����\n");
	    printf("%3d    %3d             %3d\n", stele, time, manum);
		time = ((stele > stman) ? (stele - stman): (stman - stele));
		manum++;
		printf("%3d    %3d             %3d\n", stman, time, manum);
		time += ((des > stman) ?( des - stman ):( stman - des));
		manum--;
		printf("%3d    %3d             %3d\n", des, time, manum);
		printf("��һ�ֽ����ˣ�����q�˳������������������Կ�ʼ��һ��\n");
		control = scanf("%3d %3d %3d\n", &stman, &des, &stele);
	}
	printf("�����˳�");
		return 0;
}