#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include "COVID19_func.h"

void display_information() {
	system("cls");
	FILE* fp = fopen("COVID19 DATA.txt", "r");
	char line[600];
	printf("명부에 존재하는 데이터를 모두 출력합니다.\n\n");
	while (fgets(line, sizeof(line), fp) != NULL)
		printf("\t%s",line);
	fclose(fp);
	return;
}