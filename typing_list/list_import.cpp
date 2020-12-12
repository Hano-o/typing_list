#include "head.h"

void m_import() {

	m_node *m_head = (m_node*)calloc(1, sizeof(m_node));
	m_node *m_tail = (m_node*)calloc(1, sizeof(m_node));
	m_node *m_p = (m_node*)calloc(1, sizeof(m_node));
	m_head = NULL;

	fp = fopen("user.txt", "rt");
	while(1){
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

	char ans = 0;

	char ans1[20];
	int ans2, ans3, ans4 = 0;
	int count = 0;
	int i = 0;

	for (;;) {
		system("cls");
		UI();
		gotoxy(2, 1);
		printf("                                                   회원 등록                                                      \n");
		gotoxy(2, 2);
		printf("─────────────────────────────────────────────────────────\n");

		gotoxy(2, 5);
		printf("이름을 입력하세요 : ");
		scanf("%s", ans1);

		gotoxy(2, 6);
		printf("생년월일을 입력하세요 : ");
		scanf("%d", &ans2);

		while (1) {
			gotoxy(2, 7);
			printf("학번를 입력하세요 : ");
			scanf("%d", &ans3);
			for (m_p = m_head; m_p != NULL; m_p = m_p->link) {
				if (ans3 == m_p->id){
					system("cls");
					UI();
					gotoxy(2, 1);
					printf("                                                   회원 추가                                                      \n");
					gotoxy(2, 2);
					printf("─────────────────────────────────────────────────────────\n");
					gotoxy(2, 7);
					printf("이미 가입된 회원입니다.");
					Sleep(1500);
					printmenu_a();
				}
			}
			break;
		}

		gotoxy(2, 8);
		printf("학년을 입력하세요 : ");
		scanf("%d", &ans4);

		count++;
		gotoxy(2, 9);
		printf("저장하겠습니까? Y = 계속, N = 메뉴화면으로 : ");

		gotoxy(2, 10);
		ans = _getch();

		if (ans == 'Y' || ans == 'y' || ans == 'ㅛ') {
			i++;
			fp = fopen("user.txt", "at");
			fprintf(fp, "%s %d %d %d\n", ans1,ans2,ans3,ans4);
			fclose(fp);
			gotoxy(2, 11);
			printf("저장이 완료되었습니다.");
			Sleep(1000);
			printmenu_a();
		}
		if (ans == 'N' || ans == 'n' || ans == 'ㅜ') {
			gotoxy(2, 11);
			printf("이전화면으로 이동합니다.");
			Sleep(1000);
			printmenu_a();
		}
		else {
			system("cls");
			UI();
			gotoxy(2, 1);
			printf("잘못된 입력입니다.\n");
			Sleep(1000);
			printmenu_a();
		}
	}

	printmenu_a();

}