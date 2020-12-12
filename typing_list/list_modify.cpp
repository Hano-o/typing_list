#include "head.h"

void list_modify() {

	node *head = (node*)calloc(1, sizeof(node));
	node *tail = (node*)calloc(1, sizeof(node));
	node *p = (node*)calloc(1, sizeof(node));
	head = NULL;

	fp = fopen("user.txt", "rt");
	while (1) {
		if (feof(fp)) {
			break;
		}
		node *p = (node*)calloc(1, sizeof(node));
		fscanf(fp, "%s %d %d %d\n", p->date, &p->time, &p->ox, p->addr, &p->num);
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

	}
