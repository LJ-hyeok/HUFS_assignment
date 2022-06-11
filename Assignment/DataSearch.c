#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "COVID19_func.h"
 
struct guest {	//[평가항목 5] :  구조체 사용
	char restaurant[100];
	char name[100];
	char date[10];
};

struct guest sfind(const char *arr) {	//[평가항목 6] :  포인터 활용
	FILE* fp;
	fp = fopen("COVID19 DATA.txt", "r");
	
	struct guest tmp;
	char line[600];
	char seps[] = ",";
	char* token;	//[평가항목 4] :  포인터 사용
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
		printf("\n접촉자가 없습니다.");
	printf("\n\n");
	fclose(fp);
	return;
}

void search_covid() {
	system("cls");
	struct guest note[10]; //[평가항목 3] :  배열 사용
	char buf;
	int idx, n;

	printf("확진자 데이터 추가를 선택하셨습니다.");
	printf("\n몇명을 입력하시겠습니까?");
	scanf_s("%d", &n);
	buf = getchar();

	for(idx=0;idx<n;idx++) {
		char covid_name[100];
		printf("\n\n\t확진자 이름: ");
		gets_s(covid_name, sizeof(covid_name));
		note[idx] = sfind(covid_name);

		if (strcmp(note[idx].name,covid_name) == 0) {
			printf("\n출입 명부에서 %s(을)를 발견했습니다.", note[idx].name);
			printf("\n확진자 %s와(과) 동선이 겹치는 접촉자를 출력합니다.", note[idx].name);
			printf("\n코로나 검사를 실시해 주세요.\n");
			print_confirmed_cases(note[idx]);
		}

		else
			printf("\n출입 명부에서 %s를 발견하지 못 했습니다.\n", covid_name);

	}

	printf("\n\t");
	for (idx = 0; idx<n; idx++)
		printf("%s ",note[idx].name);
	printf("는 2주간 격리해주세요.\n\n");

	for (idx = 0; idx < n; idx++) {
		note[idx].restaurant[idx] = "";
		note[idx].name[idx] = "";
		note[idx].date[idx] = "";
	}

	return;
}