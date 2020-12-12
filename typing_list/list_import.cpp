#include "head.h"

void list_import() {

	char ans2[20];
	int ans1, ans3 = 0;

	system("cls");
	UI();
	gotoxy(2, 1);
	printf("                                                   명부 작성                                                      \n");
	gotoxy(2, 2);
	printf("─────────────────────────────────────────────────────────\n");

	gotoxy(2, 5);
	printf("개인정보 수집 동의 여부를 입력해주세요.(1 = 동의, 2 = 거부) : ");
	scanf("%d", &ans1);

	gotoxy(2, 6);
	printf("거주지를 입력해주세요 : ");
	scanf("%s", ans2);

	gotoxy(2, 7);
	printf("연락처를 입력해주세요 : (010을 제외한 8자리 입력) : ");
	scanf("%d", &ans3);

	int temp_date = 0;
	char temp_time[20] = "\0";

	time_t timer;
	struct tm *t;

	timer = time(NULL); // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	char s1[50] = "\0";
	char s2[10] = "\0";
	char s3[10] = "0";
	//현재 년 t->tm_year + 1900
	sprintf(s1, "%d", t->tm_year+1900);
	//현재 월 t->tm_mon + 1
	sprintf(s2, "%d", t->tm_mon+1);
	strcat(s1, s2);
	//현재 일 t->tm_mday
	sprintf(s2, "%d", t->tm_mday);
	strcat(s1, s2);

	temp_date = atoi(s1);

	strcpy(s1, "\0");
	strcpy(s2, "\0");
	strcpy(s3, "0");

	//현재 시 t->tm_hour
	int temp = 0;
	temp = t->tm_hour;
	if (temp < 10) {
		sprintf(s1, "%d", temp);
		strcat(s3, s1);
		strcpy(temp_time, s3);
	}
	else {
		sprintf(s1, "%d", temp);
		strcpy(temp_time, s1);
	}
		//현재 분 t->tm_min
	strcpy(s1, "\0");
	strcpy(s2, "\0");
	strcpy(s3, "0");
		temp = t->tm_min;
		if (temp < 10) {
			sprintf(s2, "%d", t->tm_min);
			strcat(s3, s2);
			strcat(temp_time, s3);
		}
		else {
			sprintf(s2, "%d", t->tm_min);
			strcat(temp_time, s2);
		}

		fp = fopen("list.txt", "at");
		fprintf(fp, "%d %s %d %s %d\n", temp_date, temp_time, ans1, ans2, ans3);
		fclose(fp);

		gotoxy(2, 11);
		printf("저장이 완료되었습니다.");
		Sleep(1000);

		MUI();

	}
