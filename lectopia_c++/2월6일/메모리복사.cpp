#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
#pragma warning (disable : 4996)
typedef struct _person
{
	char *name;         // 성명 저장 멤버
	int age;             // 나이 저장 멤버
	char address[20];   // 주소 저장 멤버
}Person;
void myFlush();
void personInput(Person *sp);
void personOutput(Person sVal);
void personClear(Person *sp);
void stringInput(char *message, char *tp, size_t length);
void presonMemCpy(Person *var1, Person *var2);
int main()
{
	Person  var1 = { NULL,0, "" }, var2 = { NULL,0, "" };

	personInput(&var1);  // 구조체 각 멤버에 값을 입력 받아옴
	personOutput(var1);

	personInput(&var2);
	personOutput(var2);

	presonMemCpy(&var1, &var2);
	//var1 = var2;    // 얕은 복사로 이후 personClear()함수 수행 시 런타임에러 발생

	personOutput(var1); // 구조체 내의 데이터  출력
	personOutput(var2);

	personClear(&var1);  // 구조체 멤버의 메모리를 해제하고 데이터 모두 삭제
	personClear(&var2);
	getchar();
	return 0;
}
//--------------------------------------------------------------------------
void presonMemCpy(Person *var1, Person *var2)
{
	size_t length;

	if (var1->name != NULL && var2->name != NULL)  // *1번
	{
		free(var1->name); //1. 기존 M 해제
		length = strlen(var2->name); //2. 복사할 영역 문자열 길이 구하기
		var1->name = (char *)malloc(sizeof(char) * (length + 1)); //3. 그 길이만큼 새 M 할당
		strcpy(var1->name, var2->name); //4. 이름 복사
	}

	else if (var1->name == NULL && var2->name != NULL) // *2번
	{
		length = strlen(var2->name); //1. 복사할 영역 문자열 길이 구하기
		var1->name = (char *)malloc(sizeof(char) * (length + 1)); //2. 그 길이만큼 새 M 할당
		strcpy(var1->name, var2->name); //3. 이름 복사
	}
	else if (var1->name != NULL && var2->name == NULL)// *3번
	{
		free(var1->name); //1. 기존 M 해제
		var1->name = NULL; //2. NULL
	}

	var1->age = var2->age; //나이 복사
	strcpy(var1->address, var2->address); // 사는곳 복사

	return;
}
void personInput(Person *sp)
{
	char temp[101];
	size_t length;
	stringInput("성명 입력(100byte 이내) : ", temp, sizeof(temp));
	length = strlen(temp);
	sp->name = (char *)malloc(sizeof(char) * (length + 1)); //null문자 위해 +1
	assert(sp->name != NULL);
	strcpy(sp->name, temp);
	printf("나이 입력 : ");
	scanf("%d", &sp->age);
	myFlush();
	stringInput("주소 입력(19byte 이내) : ", temp, sizeof(sp->address));
	strcpy(sp->address, temp);
	return;
}
//---------------------------------------------------------------------------
void stringInput(char *message, char *tp, size_t length)
{
	printf(message);
	fgets(tp, length, stdin);

	if (tp[strlen(tp) - 1] == '\n') // 문자열이 정상적으로 입력되었으면
	{
		tp[strlen(tp) - 1] = '\0'; // 문자열뒤의 개행문자 삭제
	}
	else  // 입력된 문자열이 배열의 크기를 초과하게 입력되었다면
	{
		printf("입력된 문자열이 너무 길어서 일부 문자열이 잘리게 됩니다.\n");
		myFlush();  // stdin 버퍼에 남아있는 데이너 모두 지우기
	}
	return;
}
//---------------------------------------------------------------------------
void personOutput(Person sVal)
{
	printf("성명 : %s(%d세), 주소 : %s\n", sVal.name, sVal.age, sVal.address);
	return;
}
//---------------------------------------------------------------------------
void personClear(Person *sp)
{
	if (sp->name != NULL) {
		memset(sp->name, 0, strlen(sp->name));
		free(sp->name);
		sp->name = NULL;
	}
	sp->age = 0;
	memset(sp->address, 0, sizeof(sp->address));

	return;
}
//--------------------------------------------------------------------------
void myFlush()
{
	while (getchar() != '\n');
}
