#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#define MAX_NAME_LEN 10      //최대 이름 크기 정의
#define MAX_ID_LEN 20       //최대 계좌 길이 정의

typedef struct _Bank Bank;   //Bank 타입명 정의
struct _Bank {        //구조체 _Bank
	char name[MAX_NAME_LEN];//성명
	char id[MAX_ID_LEN]; //계좌번호
	int balance;    //잔액
};

Bank banks[1000] = { 0 };    //계좌를 기억할 배열 선언

void input();    //계좌 정보 입력 함수
void run();   //메뉴 선택에 따라 상호 작용
void show();//잔액 조회
void save();//입금
void draw();//출금
void Exchange();
int a;   // 인원수
char yes;   // 시작

char* timeToString(struct tm *t);    //시간 계산
void t();  //시간 프린트

int main()
{
	system("cls");
	input();      //n명의 계좌 정보를 입력받음
	printf("안녕하세요 ATM서비스 입니다. 환영합니다\n");
	printf("ATM서비를 시작하시겠습니까? ");
	scanf("%s", &yes);
	system("cls");
	run();        //메뉴 선택
	return 0;
}

void input()
{
	int i = 0;

	printf("계좌번호를 저장할 인원 수 ");
	scanf("%d", &a);
	system("cls");

	for (i = 0; i < a; i++) {      //n명의 계좌 정보를 입력받음
		printf("사용자%d의 이름:", i + 1);
		scanf("%s", banks[i].name);
		printf("사용자%d의 계좌:", i + 1);
		scanf("%s", banks[i].id);
		printf("사용자%d의 잔액:", i + 1);
		scanf("%d", &(banks[i].balance));
		printf("저장이 완료되었습니다.");
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
		printf("   NH상현 은행\n");
		printf("                     meun\n");
		printf("     =============================================\n");
		printf("     |               1. 잔액조회                 |\n");
		printf("     |               2. 저축                     |\n");
		printf("     |               3. 인출                     |\n");
		printf("     |               4. 시간                     |\n");
		printf("     |               5. 환율                     |\n");
		printf("     |               6. 종료                     |\n");
		printf("     =============================================\n");
		printf("번호를 눌러주세요 : ");
		scanf("%d", &key);

		switch (key)
		{
		case 1: show(); break;           //조회
		case 2: save(); break;           //입금
		case 3: draw(); break;           //출금
		case 4: t(); break;              //시간
		case 5: Exchange();              //환율
		case 6: exit(6);                 //종료
		default: printf("잘못된 숫자를 입력하셨습니다.\n"); break;       //잘못 선택
		}
	}
}
void show()
{
	system("cls");
	int num = 0;

	printf("사용자 번호를 선택하세요 (입력한 수 만큼) : ");
	scanf("%d", &num);

	if ((num < 1) || (num > a))   //번호가 맞지 않을 때
	{
		printf("잘못 선택하였습니다.\n");
		Sleep(1000);
		system("cls");
		show();
		return;
	}
	system("cls");
	//계좌 정보 출력
	printf("\n");
	printf("                          계좌정보\n");
	printf("         |===========================================|\n");
	printf("            %s님의 계좌번호 : %s\n", banks[num - 1].name, banks[num - 1].id);
	printf("            %s님의 현재 잔액 : %d원\n", banks[num - 1].name, banks[num - 1].balance);
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

	printf("사용자 번호를 선택하세요 (입력한 수 만큼) : ");
	scanf("%d", &num);

	if ((num < 1) || (num > a)) {          //유효하지 않은 번호일 때
		printf("잘못 선택하였습니다.\n");
		Sleep(1000);
		system("cls");
		save();
		return;
	}
	system("cls");
	printf("%s님의 저축 금액 입력:", banks[num - 1].name);
	scanf("%d", &value);
	banks[num - 1].balance += value;//저축 금액을 잔고에 더함
	printf("저축이 완료되었습니다.\n\n");
	Sleep(1000);
	printf("%s님의 현재 잔액 : %d원\n", banks[num - 1].name, banks[num - 1].balance);
	Sleep(1500);
	system("cls");
}
void draw() {
	system("cls");
	int num = 0;
	int mo = 0;

	printf("사용자 번호를 선택하세요 (입력한 수 만큼) : ");
	scanf("%d", &num);

	if ((num < 1) || (num > a)) {               //번호가 맞지 않을 때
		printf("잘못 선택하였습니다.\n");
		Sleep(1000);
		system("cls");
		draw();
		return;
	}
	system("cls");

	printf("%s님의 인출 금액 입력:", banks[num - 1].name);
	scanf("%d", &mo);

	if (mo > banks[num - 1].balance) {        //잔액보다 인출 금액이 클 때
		printf("잔액이 부족합니다.\n");
		Sleep(1500);
		system("cls");
	}
	else {
		banks[num - 1].balance -= mo;         //잔액에서 인출 금액을 뺌
		printf("인출이 완료 되었습니다.\n\n");
		Sleep(1000);
		printf("%s님의 현재 잔액 : %d원\n", banks[num - 1].name, banks[num - 1].balance);
		Sleep(1500);
	}
	system("cls");
}

//구글 참고
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

	timer = time(NULL);    // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

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
	printf("       |        1. 미국         |\n");
	printf("       |        2. 중국         |\n");
	printf("       |        3. 일본         |\n");
	printf("       |        4. 영국         |\n");
	printf("       |        5. 싱가포르     |\n");
	printf("       |        6. 메인메뉴     |\n");
	printf("       |------------------------|\n");
	printf("\n");
	printf(" 번호를 선택하세요 : ");
	scanf("%d", &a);
	switch (a)
	{
	case 1: USA(); break;
	case 2: China(); break;
	case 3: Japan(); break;
	case 4: England(); break;
	case 5: Singapore(); break;
	case 6: run();  break;
	default: printf("잘못 입력하셨습니다.");
		Sleep(800);
		Exchange();
	}
}

// 우리나라 돈 => 다른나라 돈
void USA()
{
	system("cls");
	float rate;   //환율
	float u;   // 달러
	int krw;   // 원화
	rate = 1158.03;
	printf("원화 금액을 입력하시오: ");
	scanf("%d", &krw);
	u = krw / rate;      // 달러로 환산
	printf("원화 %d원은 %.3f달러입니다.\n", krw, u);
	Sleep(5000);
	run();
}
void China() {
	system("cls");
	float rate;   // 환율
	float c;   // 위안화
	int krw;   // 원화
	rate = 168.38;
	printf("원화 금액을 입력하시오: ");
	scanf("%d", &krw);
	c = krw / rate;    // 위안화로 환산
	printf("원화 %d원은 %.3f위완화입니다.\n", krw, c);
	Sleep(5000);
	run();
}
void Japan() {
	system("cls");
	float rate;   //환율
	float j;   // 엔
	int krw;   // 원화
	rate = 10.76;
	printf("원화 금액을 입력하시오: ");
	scanf("%d", &krw);
	j = krw / rate;      // 엔으로 환산
	printf("원화 %d원은 %.3f엔입니다.\n", krw, j);
	Sleep(5000);
	run();
}
void England() {
	system("cls");
	float rate;   //환율
	float e;   // 파운드
	int krw;   // 원화
	rate = 1466.80;
	printf("원화 금액을 입력하시오: ");
	scanf("%d", &krw);
	e = krw / rate;      // 파운드로 환산
	printf("원화 %d원은 %.3f달러입니다.\n", krw, e);
	Sleep(5000);
	run();
}
void Singapore() {
	system("cls");
	float rate;   // 환율
	float s;   // 싱가포르 달러
	int krw;   // 원화
	rate = 855.28;
	printf("원화 금액을 입력하시오: ");
	scanf("%d", &krw);
	s = krw / rate;      // 싱가포르 달러로 환산
	printf("원화 %d원은 %.3f싱달러입니다.\n", krw, s);
	Sleep(5000);
	run();
}