#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

static FILE *fp;

typedef struct m_data {

	int date; //��¥
	char time[10]; //�湮�ð�
	int ox; //�������� ���� ���� 1 = ����, 2 = �ź�
	char addr[20]; //������
	int num; //����ó

	struct m_data *link;

}node;

void UI();
void MUI();

void list_import();
void list_search();
void list_delete();
void list_modify();
void gotoxy(int x, int y);
