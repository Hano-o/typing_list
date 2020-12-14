#include "head.h"

void list_delete() {

	node *head = (node*)calloc(1, sizeof(node));
	node *tail = (node*)calloc(1, sizeof(node));
	node *p = (node*)calloc(1, sizeof(node));
	head = NULL;

	fp = fopen("list.txt", "rt");
	while (1) {
		if (feof(fp)) {
			break;
		}
		node *p = (node*)calloc(1, sizeof(node));
		fscanf(fp,"%d %s %d %s %d\n", &p->date, p->time, &p->ox, p->addr, &p->num);
		if (head == NULL) {
			head = p;
			tail = p;
		}
		else {
			tail->link = p;
			tail = p;
		}
	}
	fclose(fp);

	system("cls");
	UI();
	gotoxy(2, 1);
	printf("                                                   명부 삭제                                                      \n");
	gotoxy(2, 2);
	printf("─────────────────────────────────────────────────────────\n");

	int ans1 = 0;
	
	gotoxy(2, 5);
	printf("연락처로 검색 후 삭제 - 1,  ");
	gotoxy(2, 6);
	printf("목록에서 삭제 - 2,  ");
	gotoxy(2, 7);
	printf("전부 삭제 - 3,  ");
	gotoxy(2, 8);
	printf("뒤로가기 - 4,  ");
	char c;
		int key;
		int ch = 0;
		int ans2 = 0;
		char s1[30] = "\0";
		char s2[10] = "\0";
		char s3 = '\0';
		while (1)
		{
			key = _getch(); // 입력값을 읽을때 까지 대기했다가 읽으면 다음 문장 실행
			switch (key) {
			case 49: //연락처로 검색 후 삭제
				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   명부 삭제                                                      \n");
				gotoxy(2, 2);
				printf("─────────────────────────────────────────────────────────\n");

				gotoxy(2, 4);
				printf("[번호]");
				gotoxy(9, 4);
				printf("[방문일자]");
				gotoxy(22, 4);
				printf("[방문시각]");
				gotoxy(35, 4);
				printf("[거주지]");
				gotoxy(46, 4);
				printf(" [연락처]");
				gotoxy(65, 4);
				printf("[개인정보 수집 동의 여부]");

				for (p = head; p != NULL; p = p->link) {
					ch++;

					gotoxy(2, 4 + ch);
					printf("%d번", ch);
					sprintf(s1, "%d", p->date);
					gotoxy(9, 4 + ch);
					printf("%c%c%c%c.%c%c.%c%c", s1[0], s1[1], s1[2], s1[3], s1[4], s1[5], s1[6], s1[7]);
					gotoxy(22, 4 + ch);
					printf("%c%c:%c%c", p->time[0], p->time[1], p->time[2], p->time[3]);
					gotoxy(35, 4 + ch);
					printf("%s", p->addr);
					strcpy(s1, "\0");
					sprintf(s1, "%d", p->num);
					gotoxy(47, 4 + ch);
					printf("010-%c%c%c%c-%c%c%c%c", s1[0], s1[1], s1[2], s1[3], s1[4], s1[5], s1[6], s1[7]);
					if (p->ox == 1)
						s3 = 'O';
					else
						s3 = 'X';
					gotoxy(65, 4 + ch);
					printf("%c", s3);

				}
				gotoxy(2, 7+ch);
				printf("삭제하실 연락처를 입력하세요. : ");
				scanf("%d", &ans2);

				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   명부 삭제                                                      \n");
				gotoxy(2, 2);
				printf("─────────────────────────────────────────────────────────\n");

				gotoxy(2, 4);
				printf("[번호]");
				gotoxy(9, 4);
				printf("[방문일자]");
				gotoxy(22, 4);
				printf("[방문시각]");
				gotoxy(35, 4);
				printf("[거주지]");
				gotoxy(46, 4);
				printf(" [연락처]");
				gotoxy(65, 4);
				printf("[개인정보 수집 동의 여부]");

				ch = 0;

				for (p = head; p != NULL; p = p->link) {
					if (ans2 == p->num) {
						ch++;

						gotoxy(2, 4 + ch);
						printf("%d번", ch);
						sprintf(s1, "%d", p->date);
						gotoxy(9, 4 + ch);
						printf("%c%c%c%c.%c%c.%c%c", s1[0], s1[1], s1[2], s1[3], s1[4], s1[5], s1[6], s1[7]);
						gotoxy(22, 4 + ch);
						printf("%c%c:%c%c", p->time[0], p->time[1], p->time[2], p->time[3]);
						gotoxy(35, 4 + ch);
						printf("%s", p->addr);
						strcpy(s1, "\0");
						sprintf(s1, "%d", p->num);
						gotoxy(47, 4 + ch);
						printf("010-%c%c%c%c-%c%c%c%c", s1[0], s1[1], s1[2], s1[3], s1[4], s1[5], s1[6], s1[7]);
						if (p->ox == 1)
							s3 = 'O';
						else
							s3 = 'X';
						gotoxy(65, 4 + ch);
						printf("%c", s3);

					}
				}

				gotoxy(2, 6 + ch);
				printf("삭제하실 항목의 번호를 입력해주세요 : ");
				scanf("%d", &ans2);
				ch = 0;

				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   명부 삭제                                                      \n");
				gotoxy(2, 2);
				printf("─────────────────────────────────────────────────────────\n");

				for (p = head; p != NULL; p = p->link) {
					ch++;
					if (ch == ans2) {
						p->num = 0;
						fp = fopen("list.txt", "wt");
						for (p = head; p != NULL; p = p->link) {
							if (p->num != 0)
								fprintf(fp, "%d %s %d %s %d\n", p->date, p->time, p->ox, p->addr, p->num);
						}
						fclose(fp);
						break;
					}
				}

				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   명부 삭제                                                      \n");
				gotoxy(2, 2);
				printf("─────────────────────────────────────────────────────────\n");
				gotoxy(2, 4);
				printf("아무키나 입력하면 이전화면으로 돌아갑니다.");

				while (1) {
					if (_kbhit()) {
						MUI();
					}
				}
			case 50: //목록에서 삭제
				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   명부 삭제                                                      \n");
				gotoxy(2, 2);
				printf("─────────────────────────────────────────────────────────\n");

				gotoxy(2, 4);
				printf("[번호]");
				gotoxy(9, 4);
				printf("[방문일자]");
				gotoxy(22, 4);
				printf("[방문시각]");
				gotoxy(35, 4);
				printf("[거주지]");
				gotoxy(46, 4);
				printf(" [연락처]");
				gotoxy(65, 4);
				printf("[개인정보 수집 동의 여부]");

				for (p = head; p != NULL; p = p->link) {
					ch++;

					gotoxy(2, 4 + ch);
					printf("%d번", ch);
					sprintf(s1, "%d", p->date);
					gotoxy(9, 4 + ch);
					printf("%c%c%c%c.%c%c.%c%c", s1[0], s1[1], s1[2], s1[3], s1[4], s1[5], s1[6], s1[7]);
					gotoxy(22, 4 + ch);
					printf("%c%c:%c%c", p->time[0], p->time[1], p->time[2], p->time[3]);
					gotoxy(35, 4 + ch);
					printf("%s", p->addr);
					strcpy(s1, "\0");
					sprintf(s1, "%d", p->num);
					gotoxy(47, 4 + ch);
					printf("010-%c%c%c%c-%c%c%c%c", s1[0], s1[1], s1[2], s1[3], s1[4], s1[5], s1[6], s1[7]);
					if (p->ox == 1)
						s3 = 'O';
					else
						s3 = 'X';
					gotoxy(65, 4 + ch);
					printf("%c", s3);
										
				}
				gotoxy(2, 6 + ch);
				printf("삭제하실 항목의 번호를 입력해주세요 : ");
				scanf("%d", &ans2);
				ch = 0;

				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   명부 삭제                                                      \n");
				gotoxy(2, 2);
				printf("─────────────────────────────────────────────────────────\n");

				for (p = head; p != NULL; p = p->link) {
					ch++;
					if (ch == ans2) {
						p->num = 0;
						fp = fopen("list.txt", "wt");
						for (p = head; p != NULL; p = p->link) {
							if (p->num != 0)
								fprintf(fp, "%d %s %d %s %d\n", p->date, p->time, p->ox, p->addr, p->num);
						}
						fclose(fp);
						break;
					}
				}

				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   명부 삭제                                                      \n");
				gotoxy(2, 2);
				printf("─────────────────────────────────────────────────────────\n");
				gotoxy(2, 4);
				printf("아무키나 입력하면 이전화면으로 돌아갑니다.");

				while (1) {
					if (_kbhit()) {
						MUI();
					}
				}

			case 51: //전부 삭제
				system("cls");
				printf("3번 눌림");
				Sleep(5000);
			case 52:
				MUI();
			default:
				UI();
				gotoxy(2, 1);
				printf("                                                   명부 삭제                                                      \n");
				gotoxy(2, 2);
				printf("─────────────────────────────────────────────────────────\n");
				gotoxy(2, 5);
				printf("잘못된 입력입니다. 잠시 후 메뉴로 이동합니다.");
				Sleep(1000);
				MUI();
				}
			}

		
}