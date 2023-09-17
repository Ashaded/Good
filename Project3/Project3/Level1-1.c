#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int stman, des, stele;
int time, manum;
int control;
int main(void)
{
	printf("请分别输入客人所在的楼层、\n客人的目的地、\n");
	printf("以及目前电梯所在地。\n");
	printf("请用空格隔开数字，请不要使用标点。");
	printf("输入q以退出。\n");
	control = scanf("%3d %3d %3d\n", &stman, &des, &stele);
	time = 0;
	manum = 0;
	while (control == 3)
	{
		printf("楼层    电梯运行时间    电梯中的人数\n");
	    printf("%3d    %3d             %3d\n", stele, time, manum);
		time = ((stele > stman) ? (stele - stman): (stman - stele));
		manum++;
		printf("%3d    %3d             %3d\n", stman, time, manum);
		time += ((des > stman) ?( des - stman ):( stman - des));
		manum--;
		printf("%3d    %3d             %3d\n", des, time, manum);
		printf("这一轮结束了，输入q退出，或输入三个数字以开始下一轮\n");
		control = scanf("%3d %3d %3d\n", &stman, &des, &stele);
	}
	printf("您已退出");
		return 0;
}