//[���׸� 8] : ���� �ҽ� ���� ���
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
	fp = fopen("COVID19 DATA.txt", "a+"); //[���׸� 7] :  ���� �����
	struct node guest;
	char ch,buf;
	ch = '1';
	while (ch != '0') {
		printf("�մ� ������ �߰��� �����ϼ̽��ϴ�.");
		printf("\n\n\t������ �̸�: ");
		gets_s(guest.restaurant, sizeof(guest.restaurant));
		printf("\t�մ� �̸�: ");
		gets_s(guest.name, sizeof(guest.name));
		printf("\t�湮 ��¥: ");
		gets_s(guest.date, sizeof(guest.date));
		fprintf(fp, "%s,%s,%s\n", guest.restaurant, guest.name, &guest.date);
		printf("����(0) ���(1)");
		ch = getchar();
		buf = getchar();
	}
	printf("������ �Ϸ��߽��ϴ�.\n");
	fclose(fp);
	return;
}