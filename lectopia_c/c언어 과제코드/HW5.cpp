#include<stdio.h>
double Input();  // �Է��Լ� �����
double Calculus(double kw);  // ����Լ� �����
void Output(double fee);  // ����Լ� �����
int main()
{
	double kw, fee;

	kw = Input();  // �Է��Լ� ȣ���
	fee = Calculus(kw);  // ����Լ� ȣ���
	Output(fee);  // ����Լ� ȣ���
	return 0;
}
double Input()  // �Է��Լ� ���Ǻ�
{
	double mykw;

	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf_s("%lf",&mykw);

	return mykw;
}
double Calculus(double kw)  // ����Լ� ���Ǻ�
{
	double fee, text, total;

	fee = 660 + (kw * 88.5);
	text = fee * 0.09;
	total = fee + text;

	return total;
}
void Output(double fee)  // ����Լ� ���Ǻ�
{
	printf("���� ������� %lf �� �Դϴ�.\n", fee);
}