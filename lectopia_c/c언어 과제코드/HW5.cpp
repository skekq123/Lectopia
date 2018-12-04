#include<stdio.h>
double Input();  // 입력함수 선언부
double Calculus(double kw);  // 계산함수 선언부
void Output(double fee);  // 출력함수 선언부
int main()
{
	double kw, fee;

	kw = Input();  // 입력함수 호출부
	fee = Calculus(kw);  // 계산함수 호출부
	Output(fee);  // 출력함수 호출부
	return 0;
}
double Input()  // 입력함수 정의부
{
	double mykw;

	printf("전기 사용량을 입력하세요(kw) : ");
	scanf_s("%lf",&mykw);

	return mykw;
}
double Calculus(double kw)  // 계산함수 정의부
{
	double fee, text, total;

	fee = 660 + (kw * 88.5);
	text = fee * 0.09;
	total = fee + text;

	return total;
}
void Output(double fee)  // 출력함수 정의부
{
	printf("전기 사용요금은 %lf 원 입니다.\n", fee);
}