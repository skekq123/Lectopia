#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
#pragma warning (disable : 4996)
typedef struct _person
{
	char *name;         // ���� ���� ���
	int age;             // ���� ���� ���
	char address[20];   // �ּ� ���� ���
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

	personInput(&var1);  // ����ü �� ����� ���� �Է� �޾ƿ�
	personOutput(var1);

	personInput(&var2);
	personOutput(var2);

	presonMemCpy(&var1, &var2);
	//var1 = var2;    // ���� ����� ���� personClear()�Լ� ���� �� ��Ÿ�ӿ��� �߻�

	personOutput(var1); // ����ü ���� ������  ���
	personOutput(var2);

	personClear(&var1);  // ����ü ����� �޸𸮸� �����ϰ� ������ ��� ����
	personClear(&var2);
	getchar();
	return 0;
}
//--------------------------------------------------------------------------
void presonMemCpy(Person *var1, Person *var2)
{
	size_t length;

	if (var1->name != NULL && var2->name != NULL)  // *1��
	{
		free(var1->name); //1. ���� M ����
		length = strlen(var2->name); //2. ������ ���� ���ڿ� ���� ���ϱ�
		var1->name = (char *)malloc(sizeof(char) * (length + 1)); //3. �� ���̸�ŭ �� M �Ҵ�
		strcpy(var1->name, var2->name); //4. �̸� ����
	}

	else if (var1->name == NULL && var2->name != NULL) // *2��
	{
		length = strlen(var2->name); //1. ������ ���� ���ڿ� ���� ���ϱ�
		var1->name = (char *)malloc(sizeof(char) * (length + 1)); //2. �� ���̸�ŭ �� M �Ҵ�
		strcpy(var1->name, var2->name); //3. �̸� ����
	}
	else if (var1->name != NULL && var2->name == NULL)// *3��
	{
		free(var1->name); //1. ���� M ����
		var1->name = NULL; //2. NULL
	}

	var1->age = var2->age; //���� ����
	strcpy(var1->address, var2->address); // ��°� ����

	return;
}
void personInput(Person *sp)
{
	char temp[101];
	size_t length;
	stringInput("���� �Է�(100byte �̳�) : ", temp, sizeof(temp));
	length = strlen(temp);
	sp->name = (char *)malloc(sizeof(char) * (length + 1)); //null���� ���� +1
	assert(sp->name != NULL);
	strcpy(sp->name, temp);
	printf("���� �Է� : ");
	scanf("%d", &sp->age);
	myFlush();
	stringInput("�ּ� �Է�(19byte �̳�) : ", temp, sizeof(sp->address));
	strcpy(sp->address, temp);
	return;
}
//---------------------------------------------------------------------------
void stringInput(char *message, char *tp, size_t length)
{
	printf(message);
	fgets(tp, length, stdin);

	if (tp[strlen(tp) - 1] == '\n') // ���ڿ��� ���������� �ԷµǾ�����
	{
		tp[strlen(tp) - 1] = '\0'; // ���ڿ����� ���๮�� ����
	}
	else  // �Էµ� ���ڿ��� �迭�� ũ�⸦ �ʰ��ϰ� �ԷµǾ��ٸ�
	{
		printf("�Էµ� ���ڿ��� �ʹ� �� �Ϻ� ���ڿ��� �߸��� �˴ϴ�.\n");
		myFlush();  // stdin ���ۿ� �����ִ� ���̳� ��� �����
	}
	return;
}
//---------------------------------------------------------------------------
void personOutput(Person sVal)
{
	printf("���� : %s(%d��), �ּ� : %s\n", sVal.name, sVal.age, sVal.address);
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
