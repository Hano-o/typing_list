#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

FILE *fp;

typedef struct m_data {
	int date; //��¥
	int time; //�湮�ð�
	int ox; //�������� ���� ���� 1 = ����, 2 = �ź�
	char addr[20]; //������
	int num; //����ó
	struct m_data *link;
}node;

void UI();
void MUI();

