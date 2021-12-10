#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNODE;

int ListInsert_L(LNODE* L, int i, int e);
int ListDelete_L(LNODE* L, int i);
int GetElem_L(LNODE* L, int i);

int main() {
	LNODE* L = (LNODE*)malloc(sizeof(LNODE));
	L->next = NULL;
	for (int i = 1; i <= 10; i++) {
		ListInsert_L(L, i, i * 3);
	}
	printf("%d\n", GetElem_L(L, 4));
	ListInsert_L(L, 4, 0x7fffffff);
	printf("%d\n", GetElem_L(L, 4));
	ListDelete_L(L, 4);
	printf("%d\n", GetElem_L(L, 4));

	return 0;
}
int ListInsert_L(LNODE *L, int i, int e) {
	LNODE* p = L;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || j > i - 1) {
		return 0;
	}
	LNODE* s = (LNODE*)malloc(sizeof(LNODE));
	s->next = p->next, s->data = e;
	p->next = s;
	return 1;
}
int ListDelete_L(LNODE *L, int i) {
	LNODE* p = L;
	int j = 0;
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p->next == NULL || j > i - 1) {
		return 0;
	}
	LNODE* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}
int GetElem_L(LNODE *L, int i) {
	LNODE* p = L->next;
	int j = 1;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (p == NULL || i < 1) {
		return 0;
	}
	return p->data;
}