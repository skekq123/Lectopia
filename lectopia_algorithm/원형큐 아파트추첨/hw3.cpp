#include "queue.h" 
#include <stdio.h> 
#include<assert.h>
#include<cstring>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#define Size 20
void myFlush();
int input();
int DatanumCheck(int gradenum);
void dataFileSave(int num, int gradenum);
void LotteryPerson(Queue *qPtr, int num, int win, int gradenum);
void printWinnerList(int win, int all);
int main()
{
	int win, num, winner, all;
	Queue que;
	FILE *fp;

	fp = fopen("C:\\data\\win.txt", "wt");  //txt청소 (입력할때 at로 하기 때문에 지워줘야함)
	fputs("", fp);
	fclose(fp);

	srand((unsigned int)time(NULL));
	initQueue(&que, 100); // 크기가 100인 큐 생성 및 초기화(99개 사용가능)
	win = input();
	winner = win;
	all = DatanumCheck(1) + DatanumCheck(2) + DatanumCheck(3);
	num = DatanumCheck(1);
	
	if (win > num)  //당첨자 > grade1  
	{
		dataFileSave(num, 1);
		win -= num; //당첨자 수를 grade1수만큼 빼서 나머지를 grade2에서 뽑기 
		num = DatanumCheck(2);
		if (win > num) //당첨자 > grade2
		{
			dataFileSave(num, 2);
			win -= num;
			num = DatanumCheck(3);
			if (win > num) // 당첨자 > grade3 
			{
				dataFileSave(num, 3);
			}
			else if (win < num) // 당첨자 < grade3 추첨시작
			{
				LotteryPerson(&que, num, win, 3);
			}
			else dataFileSave(num, 3);
		}
		else if (win < num)// 당첨자 < grade2 추첨시작
		{
			LotteryPerson(&que, num, win, 2);
		}
		else dataFileSave(num, 2);
	
	}
	else if(win < num) //당첨자 < grade1 추첨 시작
	{
		LotteryPerson(&que, num, win, 1); // grade1을 하나씩 q에 넣고 그 갯수를 srand로 랜덤수를 뽑아(enq,deq과정), 뽑힌사람은 바로 win에 들어가게 

	}
	else dataFileSave(num, 1);
	printWinnerList(winner, all);
	destroyQueue(&que); //끝낼때 queue 해제
	return 0;
}
void printWinnerList(int win, int all)
{
	FILE *fp;
	char temp1[20], temp2[20], temp3[20];
	fp = fopen("C:\\data\\win.txt", "rt");
	assert(fp != NULL);
	int i, j;
	printf("[   No.	 당첨자명		                   주민번호		                    연락처		]\n\n");
	for (i = 1; i <= win && i <= all; i++)
	{
		fgets(temp1, Size, fp);
		fgets(temp2, Size, fp);
		fgets(temp3, Size, fp);
		
		for (j = 0; j < Size; j++) if (temp1[j] == '\n') temp1[j] = NULL;
		for (j = 0; j < Size; j++) if (temp2[j] == '\n') temp2[j] = NULL;
		for (j = 0; j < Size; j++)
		{
			if (temp3[j] == '\n') {
				temp3[j - 1] = '*';
				temp3[j - 2] = '*';
				temp3[j - 3] = '*';
				temp3[j - 4] = '*';
			}
		}
		
	printf("    %d	%-15s %30s-*******				%s", i, temp1, temp2, temp3);
	}
		fclose(fp);
		
	return ;
}
/*1. num 갯수만큼 for문으로 queue에 txt에있는 값들을 넣고
2. srand로 값을 찾아 (enq, deq과정 win갯수만큼) 바로 win.txt에 집어 넣어버리기*/
void LotteryPerson(Queue *qPtr, int num, int win, int gradenum)
{
	FILE *fp;
	DataType temp;
	int i, j, randomNum;
	DataType getdata;

	if (gradenum == 1) {
		fp = fopen("C:\\data\\grade1.txt", "rt");
		assert(fp != NULL);
	}
	else if (gradenum == 2)
	{
		fp = fopen("C:\\data\\grade2.txt", "rt");
		assert(fp != NULL);
	}
	else {
		fp = fopen("C:\\data\\grade3.txt", "rt");
		assert(fp != NULL);
	}

	for (i = 0; i < num; i++)
	{
		fgets(temp.name, Size, fp);
		fgets(temp.num, Size, fp);
		fgets(temp.pnum, Size, fp);
		enqueue(qPtr, &temp);
	}
	fclose(fp);

		fp = fopen("C:\\data\\win.txt", "at");
		assert(fp != NULL);
		
	for (i = 0; i < win; i++)//추첨자 수 만큼 돌림
	{
		randomNum = rand() % num + 1; //  1~num까지 나옴 win횟수만큼
		for (j = 0; j < randomNum-1; j++) {   //랜덤숫자가 만약 20이 나오면 19번 dequeq, enqueue를 반복하고, 그다음번꺼는 파일에 입력
			dequeue(qPtr, &getdata);
			enqueue(qPtr, &getdata);
		}
		dequeue(qPtr, &getdata);
		fputs(getdata.name, fp);
		fputs(getdata.num, fp);
		fputs(getdata.pnum, fp);
	}
	
	fclose(fp);
}
void dataFileSave(int num, int gradenum) // 입력한갯수, 파일번호 (입력한 갯수만큼 해당 파일방에서 빼오기)
{
	FILE *fp;
	int i;
	num *= 3;  //한 데이터당 3개이므로 *3
	char **temp; //2차원 배열 동적할당

	temp = (char**)malloc(sizeof(char*) * num);
	assert(temp != NULL);
	for (i = 0; i<num; i++) {
		temp[i] = (char*)malloc(sizeof(char) * Size);
		assert(temp[i] != NULL);
	}

	if (gradenum == 1) {
		fp = fopen("C:\\data\\grade1.txt", "rt");
		assert(fp != NULL);
	}
	else if (gradenum == 2)
	{
		fp = fopen("C:\\data\\grade2.txt", "rt");
		assert(fp != NULL);
	}
	else {
		fp = fopen("C:\\data\\grade3.txt", "rt");
		assert(fp != NULL);
	}
	
	for (i = 0; i < num; i++) {
		fgets(&temp[i][0], Size, fp);	
	}
	fclose(fp);
	fp = fopen("C:\\data\\win.txt", "at");
	assert(fp != NULL);
	for (i = 0; i < num; i++) {
		fputs(&temp[i][0], fp);
	}
	fclose(fp);
}
int DatanumCheck(int gradenum)
{
	FILE *fp;
	int num = 0;
	char temp[20];
	if (gradenum == 1) {
		fp = fopen("C:\\data\\grade1.txt", "rt");
		assert(fp != NULL);
	}
	else if (gradenum == 2)
	{
		fp = fopen("C:\\data\\grade2.txt", "rt");
		assert(fp != NULL);
	}
	else {
		fp = fopen("C:\\data\\grade3.txt", "rt");
		assert(fp != NULL);
	}

	while (fgets(temp,sizeof(temp)/ sizeof(temp[0]), fp) != NULL) // 파일의 끝이 아닐동안 돌아라
	{
		num++;
	}
	fclose(fp); //중요
	return num/3;
}
int input()
{
	int data;
	while (1) {
		printf("추첨자 명수를 입력하시오 : ");
		if (scanf("%d", &data) != 1) {
			printf("잘못 입력하였습니다. 다시 입력하세요. \n");
			myFlush();
		}
		else break;
	}
		return data;
}
void myFlush()
{
	while (getchar() != '\n')
	{
		;
	}
}

