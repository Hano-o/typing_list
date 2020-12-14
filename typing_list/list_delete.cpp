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
	printf("                                                   ��� ����                                                      \n");
	gotoxy(2, 2);
	printf("������������������������������������������������������������������������������������������������������������������\n");

	int ans1 = 0;
	
	gotoxy(2, 5);
	printf("����ó�� �˻� �� ���� - 1,  ");
	gotoxy(2, 6);
	printf("��Ͽ��� ���� - 2,  ");
	gotoxy(2, 7);
	printf("���� ���� - 3,  ");
	gotoxy(2, 8);
	printf("�ڷΰ��� - 4,  ");
	char c;
		int key;
		int ch = 0;
		int ans2 = 0;
		char s1[30] = "\0";
		char s2[10] = "\0";
		char s3 = '\0';
		while (1)
		{
			key = _getch(); // �Է°��� ������ ���� ����ߴٰ� ������ ���� ���� ����
			switch (key) {
			case 49: //����ó�� �˻� �� ����
				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   ��� ����                                                      \n");
				gotoxy(2, 2);
				printf("������������������������������������������������������������������������������������������������������������������\n");

				gotoxy(2, 4);
				printf("[��ȣ]");
				gotoxy(9, 4);
				printf("[�湮����]");
				gotoxy(22, 4);
				printf("[�湮�ð�]");
				gotoxy(35, 4);
				printf("[������]");
				gotoxy(46, 4);
				printf(" [����ó]");
				gotoxy(65, 4);
				printf("[�������� ���� ���� ����]");

				for (p = head; p != NULL; p = p->link) {
					ch++;

					gotoxy(2, 4 + ch);
					printf("%d��", ch);
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
				printf("�����Ͻ� ����ó�� �Է��ϼ���. : ");
				scanf("%d", &ans2);

				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   ��� ����                                                      \n");
				gotoxy(2, 2);
				printf("������������������������������������������������������������������������������������������������������������������\n");

				gotoxy(2, 4);
				printf("[��ȣ]");
				gotoxy(9, 4);
				printf("[�湮����]");
				gotoxy(22, 4);
				printf("[�湮�ð�]");
				gotoxy(35, 4);
				printf("[������]");
				gotoxy(46, 4);
				printf(" [����ó]");
				gotoxy(65, 4);
				printf("[�������� ���� ���� ����]");

				ch = 0;

				for (p = head; p != NULL; p = p->link) {
					if (ans2 == p->num) {
						ch++;

						gotoxy(2, 4 + ch);
						printf("%d��", ch);
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
				printf("�����Ͻ� �׸��� ��ȣ�� �Է����ּ��� : ");
				scanf("%d", &ans2);
				ch = 0;

				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   ��� ����                                                      \n");
				gotoxy(2, 2);
				printf("������������������������������������������������������������������������������������������������������������������\n");

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
				printf("                                                   ��� ����                                                      \n");
				gotoxy(2, 2);
				printf("������������������������������������������������������������������������������������������������������������������\n");
				gotoxy(2, 4);
				printf("�ƹ�Ű�� �Է��ϸ� ����ȭ������ ���ư��ϴ�.");

				while (1) {
					if (_kbhit()) {
						MUI();
					}
				}
			case 50: //��Ͽ��� ����
				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   ��� ����                                                      \n");
				gotoxy(2, 2);
				printf("������������������������������������������������������������������������������������������������������������������\n");

				gotoxy(2, 4);
				printf("[��ȣ]");
				gotoxy(9, 4);
				printf("[�湮����]");
				gotoxy(22, 4);
				printf("[�湮�ð�]");
				gotoxy(35, 4);
				printf("[������]");
				gotoxy(46, 4);
				printf(" [����ó]");
				gotoxy(65, 4);
				printf("[�������� ���� ���� ����]");

				for (p = head; p != NULL; p = p->link) {
					ch++;

					gotoxy(2, 4 + ch);
					printf("%d��", ch);
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
				printf("�����Ͻ� �׸��� ��ȣ�� �Է����ּ��� : ");
				scanf("%d", &ans2);
				ch = 0;

				system("cls");
				UI();
				gotoxy(2, 1);
				printf("                                                   ��� ����                                                      \n");
				gotoxy(2, 2);
				printf("������������������������������������������������������������������������������������������������������������������\n");

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
				printf("                                                   ��� ����                                                      \n");
				gotoxy(2, 2);
				printf("������������������������������������������������������������������������������������������������������������������\n");
				gotoxy(2, 4);
				printf("�ƹ�Ű�� �Է��ϸ� ����ȭ������ ���ư��ϴ�.");

				while (1) {
					if (_kbhit()) {
						MUI();
					}
				}

			case 51: //���� ����
				system("cls");
				printf("3�� ����");
				Sleep(5000);
			case 52:
				MUI();
			default:
				UI();
				gotoxy(2, 1);
				printf("                                                   ��� ����                                                      \n");
				gotoxy(2, 2);
				printf("������������������������������������������������������������������������������������������������������������������\n");
				gotoxy(2, 5);
				printf("�߸��� �Է��Դϴ�. ��� �� �޴��� �̵��մϴ�.");
				Sleep(1000);
				MUI();
				}
			}

		
}