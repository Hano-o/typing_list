#include "head.h"

void m_search() {

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
	printf("                                                   ȸ�� �˻�                                                      \n");
	gotoxy(2, 2);
	printf("������������������������������������������������������������������������������������������������������������������\n");

	gotoxy(2, 5);
	printf("�˻��� �̸��� �Է��ϼ���. 0�� �Է��ϸ� �������� ���ư��ϴ�. : ");
	scanf("%s", ans1);

	if (strcmp(ans1, "0") == 0)
		printmenu_a();

	for (m_p = m_head; m_p != NULL; m_p = m_p->link) {
		if (strcmp(ans1, m_p->name) == 0) {
			ch++;
			gotoxy(2, 5 + ch);
			printf("%d�� - %s ��, ������� : %d, �й� : %d, %d�г�\n", ch, m_p->name, m_p->date, m_p->id, m_p->grade);
		}
	}

	if (ch == 0) {
		gotoxy(2, 6 + ch);
		printf("��ġ�ϴ� ����� �����ϴ�.");
	}

	gotoxy(2, 8 + ch);
	printf("�ƹ�Ű�� �Է��ϸ� ����ȭ������ ���ư��ϴ�.");

	while (1) {
		if (_kbhit()) {
			printmenu_a();
		}
	}
}