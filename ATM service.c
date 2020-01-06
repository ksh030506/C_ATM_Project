#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
#define MAX_NAME_LEN 10      //�ִ� �̸� ũ�� ����
#define MAX_ID_LEN 20       //�ִ� ���� ���� ����

typedef struct _Bank Bank;   //Bank Ÿ�Ը� ����
struct _Bank {        //����ü _Bank
	char name[MAX_NAME_LEN];//����
	char id[MAX_ID_LEN]; //���¹�ȣ
	int balance;    //�ܾ�
};

Bank banks[1000] = { 0 };    //���¸� ����� �迭 ����

void input();    //���� ���� �Է� �Լ�
void run();   //�޴� ���ÿ� ���� ��ȣ �ۿ�
void show();//�ܾ� ��ȸ
void save();//�Ա�
void draw();//���
void Exchange();
int a;   // �ο���
char yes;   // ����

char* timeToString(struct tm *t);    //�ð� ���
void t();  //�ð� ����Ʈ

int main()
{
	system("cls");
	input();      //n���� ���� ������ �Է¹���
	printf("�ȳ��ϼ��� ATM���� �Դϴ�. ȯ���մϴ�\n");
	printf("ATM���� �����Ͻðڽ��ϱ�? ");
	scanf("%s", &yes);
	system("cls");
	run();        //�޴� ����
	return 0;
}

void input()
{
	int i = 0;

	printf("���¹�ȣ�� ������ �ο� �� ");
	scanf("%d", &a);
	system("cls");

	for (i = 0; i < a; i++) {      //n���� ���� ������ �Է¹���
		printf("�����%d�� �̸�:", i + 1);
		scanf("%s", banks[i].name);
		printf("�����%d�� ����:", i + 1);
		scanf("%s", banks[i].id);
		printf("�����%d�� �ܾ�:", i + 1);
		scanf("%d", &(banks[i].balance));
		printf("������ �Ϸ�Ǿ����ϴ�.");
		Sleep(1000);
		system("cls");
	}
}
void run()
{
	system("cls");
	int key = 0;

	while (yes == 'Y' || yes == 'y')
	{
		printf("   NH���� ����\n");
		printf("                     meun\n");
		printf("     =============================================\n");
		printf("     |               1. �ܾ���ȸ                 |\n");
		printf("     |               2. ����                     |\n");
		printf("     |               3. ����                     |\n");
		printf("     |               4. �ð�                     |\n");
		printf("     |               5. ȯ��                     |\n");
		printf("     |               6. ����                     |\n");
		printf("     =============================================\n");
		printf("��ȣ�� �����ּ��� : ");
		scanf("%d", &key);

		switch (key)
		{
		case 1: show(); break;           //��ȸ
		case 2: save(); break;           //�Ա�
		case 3: draw(); break;           //���
		case 4: t(); break;              //�ð�
		case 5: Exchange();              //ȯ��
		case 6: exit(6);                 //����
		default: printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�.\n"); break;       //�߸� ����
		}
	}
}
void show()
{
	system("cls");
	int num = 0;

	printf("����� ��ȣ�� �����ϼ��� (�Է��� �� ��ŭ) : ");
	scanf("%d", &num);

	if ((num < 1) || (num > a))   //��ȣ�� ���� ���� ��
	{
		printf("�߸� �����Ͽ����ϴ�.\n");
		Sleep(1000);
		system("cls");
		show();
		return;
	}
	system("cls");
	//���� ���� ���
	printf("\n");
	printf("                          ��������\n");
	printf("         |===========================================|\n");
	printf("            %s���� ���¹�ȣ : %s\n", banks[num - 1].name, banks[num - 1].id);
	printf("            %s���� ���� �ܾ� : %d��\n", banks[num - 1].name, banks[num - 1].balance);
	printf("         |===========================================|\n");
	printf("\n");
	Sleep(5000);
	system("cls");
}
void save()
{
	system("cls");
	int num = 0;
	int value = 0;

	printf("����� ��ȣ�� �����ϼ��� (�Է��� �� ��ŭ) : ");
	scanf("%d", &num);

	if ((num < 1) || (num > a)) {          //��ȿ���� ���� ��ȣ�� ��
		printf("�߸� �����Ͽ����ϴ�.\n");
		Sleep(1000);
		system("cls");
		save();
		return;
	}
	system("cls");
	printf("%s���� ���� �ݾ� �Է�:", banks[num - 1].name);
	scanf("%d", &value);
	banks[num - 1].balance += value;//���� �ݾ��� �ܰ� ����
	printf("������ �Ϸ�Ǿ����ϴ�.\n\n");
	Sleep(1000);
	printf("%s���� ���� �ܾ� : %d��\n", banks[num - 1].name, banks[num - 1].balance);
	Sleep(1500);
	system("cls");
}
void draw() {
	system("cls");
	int num = 0;
	int mo = 0;

	printf("����� ��ȣ�� �����ϼ��� (�Է��� �� ��ŭ) : ");
	scanf("%d", &num);

	if ((num < 1) || (num > a)) {               //��ȣ�� ���� ���� ��
		printf("�߸� �����Ͽ����ϴ�.\n");
		Sleep(1000);
		system("cls");
		draw();
		return;
	}
	system("cls");

	printf("%s���� ���� �ݾ� �Է�:", banks[num - 1].name);
	scanf("%d", &mo);

	if (mo > banks[num - 1].balance) {        //�ܾ׺��� ���� �ݾ��� Ŭ ��
		printf("�ܾ��� �����մϴ�.\n");
		Sleep(1500);
		system("cls");
	}
	else {
		banks[num - 1].balance -= mo;         //�ܾ׿��� ���� �ݾ��� ��
		printf("������ �Ϸ� �Ǿ����ϴ�.\n\n");
		Sleep(1000);
		printf("%s���� ���� �ܾ� : %d��\n", banks[num - 1].name, banks[num - 1].balance);
		Sleep(1500);
	}
	system("cls");
}

//���� ����
char* timeToString(struct tm *t) {
	static char s[20];
	sprintf(s, "%04d-%02d-%02d %02d:%02d:%02d",
		t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
		t->tm_hour, t->tm_min, t->tm_sec);
	return s;
}
void t() {
	system("cls");
	struct tm *t;
	time_t timer;

	timer = time(NULL);    // ���� �ð��� �� ������ ���
	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�

	printf("\n");
	printf("\n");
	printf("\n");
	printf("       %s\n", timeToString(t));
	Sleep(3000);
	system("cls");
}
//

void USA();
void China();
void Japan();
void England();
void Singapore();

void Exchange()
{
	int a;
	system("cls");
	printf("       |------------------------|\n");
	printf("       |        1. �̱�         |\n");
	printf("       |        2. �߱�         |\n");
	printf("       |        3. �Ϻ�         |\n");
	printf("       |        4. ����         |\n");
	printf("       |        5. �̰�����     |\n");
	printf("       |        6. ���θ޴�     |\n");
	printf("       |------------------------|\n");
	printf("\n");
	printf(" ��ȣ�� �����ϼ��� : ");
	scanf("%d", &a);
	switch (a)
	{
	case 1: USA(); break;
	case 2: China(); break;
	case 3: Japan(); break;
	case 4: England(); break;
	case 5: Singapore(); break;
	case 6: run();  break;
	default: printf("�߸� �Է��ϼ̽��ϴ�.");
		Sleep(800);
		Exchange();
	}
}

// �츮���� �� => �ٸ����� ��
void USA()
{
	system("cls");
	float rate;   //ȯ��
	float u;   // �޷�
	int krw;   // ��ȭ
	rate = 1158.03;
	printf("��ȭ �ݾ��� �Է��Ͻÿ�: ");
	scanf("%d", &krw);
	u = krw / rate;      // �޷��� ȯ��
	printf("��ȭ %d���� %.3f�޷��Դϴ�.\n", krw, u);
	Sleep(5000);
	run();
}
void China() {
	system("cls");
	float rate;   // ȯ��
	float c;   // ����ȭ
	int krw;   // ��ȭ
	rate = 168.38;
	printf("��ȭ �ݾ��� �Է��Ͻÿ�: ");
	scanf("%d", &krw);
	c = krw / rate;    // ����ȭ�� ȯ��
	printf("��ȭ %d���� %.3f����ȭ�Դϴ�.\n", krw, c);
	Sleep(5000);
	run();
}
void Japan() {
	system("cls");
	float rate;   //ȯ��
	float j;   // ��
	int krw;   // ��ȭ
	rate = 10.76;
	printf("��ȭ �ݾ��� �Է��Ͻÿ�: ");
	scanf("%d", &krw);
	j = krw / rate;      // ������ ȯ��
	printf("��ȭ %d���� %.3f���Դϴ�.\n", krw, j);
	Sleep(5000);
	run();
}
void England() {
	system("cls");
	float rate;   //ȯ��
	float e;   // �Ŀ��
	int krw;   // ��ȭ
	rate = 1466.80;
	printf("��ȭ �ݾ��� �Է��Ͻÿ�: ");
	scanf("%d", &krw);
	e = krw / rate;      // �Ŀ��� ȯ��
	printf("��ȭ %d���� %.3f�޷��Դϴ�.\n", krw, e);
	Sleep(5000);
	run();
}
void Singapore() {
	system("cls");
	float rate;   // ȯ��
	float s;   // �̰����� �޷�
	int krw;   // ��ȭ
	rate = 855.28;
	printf("��ȭ �ݾ��� �Է��Ͻÿ�: ");
	scanf("%d", &krw);
	s = krw / rate;      // �̰����� �޷��� ȯ��
	printf("��ȭ %d���� %.3f�̴޷��Դϴ�.\n", krw, s);
	Sleep(5000);
	run();
}