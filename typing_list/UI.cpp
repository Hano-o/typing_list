#include "head.h"
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void UI() {

	int i, j = 1;

	gotoxy(0, 0);
	printf("����������������������������������������������������������������������������������������������������������������������\n");
	for (i = 0; i<35; i++)
	{
		gotoxy(0, j);
		printf("��                                                                                                                  ��\n");
		j++;
	}
	gotoxy(0, 35);
	printf("����������������������������������������������������������������������������������������������������������������������\n");
	gotoxy(2, 2);
	printf("������������������������������������������������������������������������������������������������������������������\n");
}
void MUI() {

	int num = 0;

	system("cls");
	UI();
	gotoxy(2, 1);
	printf("                                                 Ÿ���� ���                                                    \n");
	gotoxy(2, 2);
	printf("������������������������������������������������������������������������������������������������������������������\n");

	gotoxy(45, 4);
	printf("��������������������������\n");
	gotoxy(45, 5);
	printf("��1. ��� �ۼ�          ��\n");
	gotoxy(45, 6);
	printf("��������������������������\n");
	gotoxy(45, 7);
	printf("��������������������������\n");
	gotoxy(45, 8);
	printf("��2. ��� ����          ��\n");
	gotoxy(45, 9);
	printf("��������������������������\n");
	gotoxy(45, 10);
	printf("��������������������������\n");
	gotoxy(45, 11);
	printf("��3. ��� �˻�          ��\n");
	gotoxy(45, 12);
	printf("��������������������������\n");
	gotoxy(45, 13);
	printf("��������������������������\n");
	gotoxy(45, 14);
	printf("��4. ��� ����          ��\n");
	gotoxy(45, 15);
	printf("��������������������������\n");

	gotoxy(45, 17);
	printf("��������������������������\n");
	gotoxy(45, 18);
	printf("��0. ����               ��\n");
	gotoxy(45, 19);
	printf("��������������������������\n");

	gotoxy(45, 26);
	printf(" �޴� ���� : ");
	scanf("%d", &num);

	if (num == 1)
		list_insert();
	else if (num == 2)
		list_modify();
	else if (num == 3)
		list_search();
	else if (num == 4)
		list_delete();
	else if (num == 0)
		exit(0);
	else {
		gotoxy(35, 29);
		printf("�߸��� �Է��Դϴ�. 1�ʵ� �ʱ�ȭ������ �̵��մϴ�.\n");
		Sleep(1000);
		system("cls");
		MUI();

}