#include <stdio.h>
#pragma warning (disable : 4996)
void quickSort(int *ary, int size);
int binarySearch(int *ary, int leftIndex, int rightIndex, int key);
void output(int *ary, int size);
int main()
{
	int ary[10] = { 11,3,25,7,19,10,13,35,8,19 };
	int size;        // �迭��Ұ��� ����
	int key;         // ã�� ���� ����
	int index;      // �˻��� �������� �ε���
	int res;        // scanf()�Լ��� ���ϰ� ����
	size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, size);
	output(ary, size);

	while (1)
	{
		printf("�˻��� ���� �Է�(�����Է� �� ����) : ");
		res = scanf("%d", &key);
		if (res != 1) { break; }   // �����Է� �� ����
		if ((index = binarySearch(ary, 0, size - 1, key)) != -1)
		{
			printf("%d�� %d���� �������Դϴ�.\n", key, index);
		}
		else
		{
			printf("%d�� �������� �ʽ��ϴ�.\n", key);
		}
	}

	getchar(); getchar();
	return 0;
}
/*---------------------------------------------------------------------
�Լ��� �� ��� : binarySearch() - �̺� �˻� �Լ�
��������: ary - �˻��� ������ �迭�� �����ּ�
leftIndex - �˻� ������ ���� �ε���
rightIndex - �˻� ������ ���� �ε���
key - �˻��� ������
���ϰ�: �˻� ���� �� - ã�� ������ index / �˻� ���� �� - -1 ����
--------------------------------------------------------------------*/
int binarySearch(int *ary, int leftIndex, int rightIndex, int key)
{
	int size = sizeof(ary) / sizeof(ary[0]), mid;
	
	while (leftIndex <= rightIndex)
	{
		mid = (rightIndex + leftIndex) / 2;
		if (ary[mid] == key) return mid;

		if (key > ary[mid]) leftIndex = mid+1;
			
		if (key < ary[mid]) rightIndex = mid-1;
	}
	return -1;  // ��ã������ -1 ����
}
/*--------------------------------------------------------------------
�Լ��� �� ��� : quickSort() - �� ���� �Լ�
��������: ary - ������ ������ �迭�� �����ּ�
size - ��Ʈ�� �������� ����
���ϰ�: ����
--------------------------------------------------------------------*/
void quickSort(int *ary, int size)
{
	int pivot, temp;
	int i, j;

	if (size <= 1) return;// �������� 1�����̸� sort�� �Ϸ�� �� �̹Ƿ� return

	pivot = ary[size - 1];         // ������ ���� �������� pivot���� ����
	i = -1;        // i�� �������� ���� �˻��� ��ġ ����
	j = size - 1;    // j�� �������� ���� �˻��� ��ġ ����

	while (1)       // ���� �۾�
	{
		while (ary[++i] < pivot);  // �������κ��� pivot���� ū �� ��ġ ã��
		while (j>0 && ary[--j]>pivot); // �������� pivot���� ���� �� ��ġ ã��
		if (i >= j) break; //i�� j���� ũ�ų� �������� ������ ���̹Ƿ� while�� Ż��
						   // �ƴϸ� i�� j�� ���� �� swap
		temp = ary[i];
		ary[i] = ary[j];
		ary[j] = temp;
	}
	// ������ �������� i�� ���� ���� pivot��ġ�� �� swap
	temp = ary[i];
	ary[i] = ary[size - 1];    // ���⼭ pivot������ ���� �ٲ��� �ʵ��� ����
	ary[size - 1] = temp;

	quickSort(ary, i);            // ���� �ұ����� ���� �� ���� ��� ȣ��
	quickSort(ary + i + 1, size - i - 1);  // ���� �ұ����� ���� �� ���� ��� ȣ��
}

/*-----------------------------------------------------------------------
�Լ��� �� ��� : output() - �迭�� ��� ���� ����ϱ�
��������: ary - ������ ������ �迭�� �����ּ�
size - �������� ����
���ϰ�: ����
-----------------------------------------------------------------------*/
void output(int *ary, int size)
{
	for (int i = 0; i<size; i++)
	{
		printf(" %d ", ary[i]);
	}
	printf("\n");
}
