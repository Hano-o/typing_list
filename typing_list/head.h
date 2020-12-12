#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

static FILE *fp;

typedef struct m_data {

	int date; //날짜
	char time[10]; //방문시각
	int ox; //개인정보 수집 동의 1 = 동의, 2 = 거부
	char addr[20]; //거주지
	int num; //연락처

	struct m_data *link;

}node;

void UI();
void MUI();

void list_import();
void list_search();
void list_delete();
void list_modify();
void gotoxy(int x, int y);
