#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

FILE *fp;

typedef struct m_data {
	int date; //날짜
	int time; //방문시각
	int ox; //개인정보 수집 동의 1 = 동의, 2 = 거부
	char addr[20]; //거주지
	int num; //연락처
	struct m_data *link;
}node;

void UI();
void MUI();

