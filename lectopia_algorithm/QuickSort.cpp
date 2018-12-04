#include <stdio.h>
void quickSort(int *ary, int size);
void output(int *ary, int size);
int main()
{
	int dataList[] = { 76, 12, 29, 3, 15, 6, 34, 29, 25 };
	int size = sizeof(dataList) / sizeof(dataList[0]);
	quickSort(dataList, size); 	/* 퀵 정렬 함수 호출 */
	printf("\n\n[ 퀵 정렬  후 출력 ]\n");
	output(dataList, size);

	getchar();
	return 0;
}
/*----------------------------------------------------------------------
함수명 및 기능 : quickSort() - 퀵 정렬 함수
전달인자: ary - 정렬할 데이터 배열의 시작주소
size - 소트할 데이터의 개수
리턴값: 없음
--------------------------------------------------------------------*/
void quickSort(int *ary, int size)
{
	int pivot, temp;
	int i, j; //i는 pivot보다 큰 값, j는 pivot보다 작은 값

	if (size <= 1) return; // 구간값이 1이하이면 sort가 완료된 것 이므로 return
	pivot = ary[size - 1];// 구간의 가장 우측값을 pivot으로 정함

	/*while (1) {
		for (i = 0; ary[i] > pivot; i++);// 2-1

		for (j = size - 1; ary[j] < pivot; j--); // 2-2

		if (i >= j) break;
		else
		{
			temp = ary[i];
			ary[i] = ary[j];
			ary[j] = temp;
		}
	}*/
		temp = ary[i];
		ary[i] = ary[size-1];
		ary[size-1] = temp;

	quickSort(ary, i); // 좌측 소구간에 대한 퀵 정렬 재귀 호출
	quickSort(ary + i + 1, size - i-1); // 우측 소구간에 대한 퀵 정렬 재귀 호출
}
/*------------------------------------------------------------------------
함수명 및 기능 : output() - 배열의 모든 원소 출력하기
전달인자: ary - 정렬할 데이터 배열의 시작주소
size - 데이터의 개수
리턴값: 없음
------------------------------------------------------------------------*/
void output(int *ary, int size)
{
	for (int i = 0; i<size; i++) {
		printf(" %d ", ary[i]);
	}
	printf("\n");
}
