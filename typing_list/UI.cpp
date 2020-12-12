#include "head.h"
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void UI() {

	int i, j = 1;

	gotoxy(0, 0);
	printf("┌─────────────────────────────────────────────────────────┐\n");
	for (i = 0; i<35; i++)
	{
		gotoxy(0, j);
		printf("│                                                                                                                  │\n");
		j++;
	}
	gotoxy(0, 35);
	printf("└─────────────────────────────────────────────────────────┘\n");
	gotoxy(2, 2);
	printf("─────────────────────────────────────────────────────────\n");
}
void MUI() {

	int num = 0;

	system("cls");
	UI();
	gotoxy(2, 1);
	printf("                                                 타이핑 명부                                                    \n");
	gotoxy(2, 2);
	printf("─────────────────────────────────────────────────────────\n");

	gotoxy(45, 4);
	printf("┌───────────┐\n");
	gotoxy(45, 5);
	printf("│1. 명부 작성          │\n");
	gotoxy(45, 6);
	printf("└───────────┘\n");
	gotoxy(45, 7);
	printf("┌───────────┐\n");
	gotoxy(45, 8);
	printf("│2. 명부 수정          │\n");
	gotoxy(45, 9);
	printf("└───────────┘\n");
	gotoxy(45, 10);
	printf("┌───────────┐\n");
	gotoxy(45, 11);
	printf("│3. 명부 검색          │\n");
	gotoxy(45, 12);
	printf("└───────────┘\n");
	gotoxy(45, 13);
	printf("┌───────────┐\n");
	gotoxy(45, 14);
	printf("│4. 명부 삭제          │\n");
	gotoxy(45, 15);
	printf("└───────────┘\n");

	gotoxy(45, 17);
	printf("┌───────────┐\n");
	gotoxy(45, 18);
	printf("│0. 종료               │\n");
	gotoxy(45, 19);
	printf("└───────────┘\n");

	gotoxy(45, 26);
	printf(" 메뉴 선택 : ");
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
		printf("잘못된 입력입니다. 1초뒤 초기화면으로 이동합니다.\n");
		Sleep(1000);
		system("cls");
		MUI();

}