//[평가항목 8] : 다중 소스 파일 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include "COVID19_func.h"

struct node {
	char restaurant[100];
	char name[100];
	char date[10];
};

void input_guest() {
	system("cls");
	FILE* fp;
	fp = fopen("COVID19 DATA.txt", "a+"); //[평가항목 7] :  파일 입출력
	struct node guest;
	char ch,buf;
	ch = '1';
	while (ch != '0') {
		printf("손님 데이터 추가를 선택하셨습니다.");
		printf("\n\n\t음식점 이름: ");
		gets_s(guest.restaurant, sizeof(guest.restaurant));
		printf("\t손님 이름: ");
		gets_s(guest.name, sizeof(guest.name));
		printf("\t방문 날짜: ");
		gets_s(guest.date, sizeof(guest.date));
		fprintf(fp, "%s,%s,%s\n", guest.restaurant, guest.name, &guest.date);
		printf("종료(0) 계속(1)");
		ch = getchar();
		buf = getchar();
	}
	printf("저장을 완료했습니다.\n");
	fclose(fp);
	return;
}