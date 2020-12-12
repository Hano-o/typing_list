#include "head.h"

void m_modify() {

	m_node *m_head = (m_node*)calloc(1, sizeof(m_node));
	m_node *m_tail = (m_node*)calloc(1, sizeof(m_node));
	m_node *m_p = (m_node*)calloc(1, sizeof(m_node));

	m_head = NULL;

	fp = fopen("user.txt", "rt");
	while (1) {
		if (feof(fp)) {
			break;
		}
		m_node *m_p = (m_node*)calloc(1, sizeof(m_node));
		fscanf(fp, "%s %d %d %d\n", m_p->name, &m_p->date, &m_p->id, &m_p->grade);
		if (m_head == NULL) {
			m_head = m_p;
			m_tail = m_p;
		}
		else {
			m_tail->link = m_p;
			m_tail = m_p;
		}
	}
	fclose(fp);

	char ans[20];
	int i = 0;
	int ch = 0;
	char ans1[20];
	int ans2, ans3, ans4 = 0;

	system("cls");
	UI();
	gotoxy(2, 1);
	printf("                                                   회원 수정                                                      \n");
	gotoxy(2, 2);
	printf("─────────────────────────────────────────────────────────\n");

	gotoxy(2, 5);
	printf("수정할 이름을 입력하세요. 0을 입력하면 이전으로 돌아갑니다. : ");
	scanf("%s", ans1);

	if (strcmp(ans1, "0") == 0)
		printmenu_a();

	for (m_p = m_head; m_p != NULL; m_p = m_p->link) {
		if (strcmp(ans1, m_p->name) == 0) {
			ch++;
			gotoxy(2, 5 + ch);
			printf("%d번 - %s 님, 생년월일 : %d, 학번 : %d, %d학년\n", ch, m_p->name, m_p->date, m_p->id, m_p->grade);
		}
	}
		if (ch == 0) {
			gotoxy(2, 6 + ch);
			printf("일치하는 결과가 없습니다.");
			gotoxy(2, 8 + ch);
			printf("아무키나 입력하면 이전화면으로 돌아갑니다.");
			while (1) {
				if (_kbhit()) {
					printmenu_a();
				}
			}
		}

		gotoxy(2, 7 + ch);
		printf("항목을 선택하세요 : ");
		scanf("%d", &ans2);

		ch = 0;

		for (m_p = m_head; m_p != NULL; m_p = m_p->link) {
			if (strcmp(ans1, m_p->name) == 0) {
				ch++;
				if (ch == ans2) {
					system("cls");
					UI();
					gotoxy(2, 1);
					printf("                                                   회원 수정                                                      \n");
					gotoxy(2, 2);
					printf("─────────────────────────────────────────────────────────\n");
					while (1) {
						gotoxy(2, 4 + ch);
						printf("수정할 키워드를 입력하세요. : ");
						gotoxy(2, 5 + ch);
						printf("1. 이름  / 2. 생년월일 / 3. 학번 / 4. 학년 : ");
						scanf("%d", &ans2);
						if (ans2 == 1) {
							gotoxy(2, 6 + ch);
							printf("이름을 입력하세요 : ");
							scanf("%s", ans1);
							strcpy(m_p->name, ans1);
						}
						else if (ans2 == 2) {
							gotoxy(2, 6 + ch);
							printf("생년월일을 입력하세요 : ");
							scanf("%d", &ans2);
							m_p->date = ans2;
						}
						else if (ans2 == 3) {
							gotoxy(2, 6 + ch);
							printf("학번을 입력하세요 : ");
							scanf("%d", &ans2);
							m_p->id = ans2;
						}
						else if (ans2 == 4) {
							gotoxy(2, 6 + ch);
							printf("학년을 입력하세요 : ");
							scanf("%d", &ans2);
							m_p->grade = ans2;
						}
						else {
							gotoxy(2, 6 + ch);
							printf("잘못된 입력입니다.");
							Sleep(1500);
							continue;
						}
						fp = fopen("user.txt", "wt");
						for (m_p = m_head; m_p != NULL; m_p = m_p->link) {
							fprintf(fp, "%s %d %d %d\n", m_p->name, m_p->date, m_p->id, m_p->grade);
						}
						fclose(fp);

						gotoxy(2, 8 + ch);
						printf("아무키나 입력하면 이전화면으로 돌아갑니다.");

						while (1) {
							if (_kbhit()) {
								printmenu_a();
							}
						}
					}

				}
			
			}
			
		}
		if (ch < ans) {
			gotoxy(2, 6 + ch);
			printf("잘못된 입력입니다.");
			Sleep(1500);
			printmenu_a();
		}





	}
