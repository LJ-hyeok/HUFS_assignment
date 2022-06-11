#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "COVID19_func.h"
 
struct guest {	//[���׸� 5] :  ����ü ���
	char restaurant[100];
	char name[100];
	char date[10];
};

struct guest sfind(const char *arr) {	//[���׸� 6] :  ������ Ȱ��
	FILE* fp;
	fp = fopen("COVID19 DATA.txt", "r");
	
	struct guest tmp;
	char line[600];
	char seps[] = ",";
	char* token;	//[���׸� 4] :  ������ ���
	while (fgets(line, sizeof(line), fp) != NULL) {
		token = strtok(line, seps);
		strcpy(tmp.restaurant, token);
		strcpy(tmp.name, strtok(NULL, seps)); 
		strcpy(tmp.date, strtok(NULL, seps));
		if (strcmp(tmp.name, arr) == 0) {
			fclose(fp);
			return tmp;
		}
	}
	fclose(fp);
	return tmp;
}

void print_confirmed_cases(struct guest covid) {
	FILE* fp;
	fp = fopen("COVID19 DATA.txt", "r");

	struct guest tmp;
	char line[600];
	char seps[] = ",";
	int flag = 0;
	while (fgets(line, sizeof(line), fp) != NULL) {
		strcpy(tmp.restaurant, strtok(line, seps));
		strcpy(tmp.name, strtok(NULL, seps));
		strcpy(tmp.date, strtok(NULL, seps));
		if (strcmp(covid.restaurant, tmp.restaurant) == 0 && strcmp(covid.date, tmp.date) == 0 && strcmp(covid.name, tmp.name) != 0) {
			printf("\n\t%s ", tmp.name);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("\n�����ڰ� �����ϴ�.");
	printf("\n\n");
	fclose(fp);
	return;
}

void search_covid() {
	system("cls");
	struct guest note[10]; //[���׸� 3] :  �迭 ���
	char buf;
	int idx, n;

	printf("Ȯ���� ������ �߰��� �����ϼ̽��ϴ�.");
	printf("\n����� �Է��Ͻðڽ��ϱ�?");
	scanf_s("%d", &n);
	buf = getchar();

	for(idx=0;idx<n;idx++) {
		char covid_name[100];
		printf("\n\n\tȮ���� �̸�: ");
		gets_s(covid_name, sizeof(covid_name));
		note[idx] = sfind(covid_name);

		if (strcmp(note[idx].name,covid_name) == 0) {
			printf("\n���� ��ο��� %s(��)�� �߰��߽��ϴ�.", note[idx].name);
			printf("\nȮ���� %s��(��) ������ ��ġ�� �����ڸ� ����մϴ�.", note[idx].name);
			printf("\n�ڷγ� �˻縦 �ǽ��� �ּ���.\n");
			print_confirmed_cases(note[idx]);
		}

		else
			printf("\n���� ��ο��� %s�� �߰����� �� �߽��ϴ�.\n", covid_name);

	}

	printf("\n\t");
	for (idx = 0; idx<n; idx++)
		printf("%s ",note[idx].name);
	printf("�� 2�ְ� �ݸ����ּ���.\n\n");

	for (idx = 0; idx < n; idx++) {
		note[idx].restaurant[idx] = "";
		note[idx].name[idx] = "";
		note[idx].date[idx] = "";
	}

	return;
}