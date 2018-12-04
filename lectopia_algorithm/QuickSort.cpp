#include <stdio.h>
void quickSort(int *ary, int size);
void output(int *ary, int size);
int main()
{
	int dataList[] = { 76, 12, 29, 3, 15, 6, 34, 29, 25 };
	int size = sizeof(dataList) / sizeof(dataList[0]);
	quickSort(dataList, size); 	/* �� ���� �Լ� ȣ�� */
	printf("\n\n[ �� ����  �� ��� ]\n");
	output(dataList, size);

	getchar();
	return 0;
}
/*----------------------------------------------------------------------
�Լ��� �� ��� : quickSort() - �� ���� �Լ�
��������: ary - ������ ������ �迭�� �����ּ�
size - ��Ʈ�� �������� ����
���ϰ�: ����
--------------------------------------------------------------------*/
void quickSort(int *ary, int size)
{
	int pivot, temp;
	int i, j; //i�� pivot���� ū ��, j�� pivot���� ���� ��

	if (size <= 1) return; // �������� 1�����̸� sort�� �Ϸ�� �� �̹Ƿ� return
	pivot = ary[size - 1];// ������ ���� �������� pivot���� ����

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

	quickSort(ary, i); // ���� �ұ����� ���� �� ���� ��� ȣ��
	quickSort(ary + i + 1, size - i-1); // ���� �ұ����� ���� �� ���� ��� ȣ��
}
/*------------------------------------------------------------------------
�Լ��� �� ��� : output() - �迭�� ��� ���� ����ϱ�
��������: ary - ������ ������ �迭�� �����ּ�
size - �������� ����
���ϰ�: ����
------------------------------------------------------------------------*/
void output(int *ary, int size)
{
	for (int i = 0; i<size; i++) {
		printf(" %d ", ary[i]);
	}
	printf("\n");
}
