#include<stdio.h>

int main()
{
	int time, our, min, sec = 54321;

		time = sec;
		our = sec / (60 * 60);  //�ð� ����
		sec -= our * 60 * 60;  //sec���� �ð���ŭ ��
		min = sec / 60;  //�� ����
		sec -= min * 60;  // sec���� �и�ŭ �� -> ��


	printf("%d�ʴ� %d�ð� %d�� %d�� �Դϴ�.\n", time, our, min, sec);
	return 0;
}