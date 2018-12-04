#include<stdio.h>

int main()
{
	int time, our, min, sec = 54321;

		time = sec;
		our = sec / (60 * 60);  //시간 계산식
		sec -= our * 60 * 60;  //sec에서 시간만큼 뺌
		min = sec / 60;  //분 계산식
		sec -= min * 60;  // sec에서 분만큼 뺌 -> 초


	printf("%d초는 %d시간 %d분 %d초 입니다.\n", time, our, min, sec);
	return 0;
}