#include <stdio.h>
#include <stdlib.h>

int GetElem_DuL(LNode* L, int i);
struct DuLNode* GetElemP_DuL(LNode* L, int i);
int ListInsert_DuL(LNode* L, int i, int e);
int ListDelete_DuL(LNode* L, int i);

typedef struct DuLNode {
	int data;
	struct DuLNode* pre;
	struct DuLNode* next;
}LNode;

int main() {
	LNode* L = (LNode*)malloc(sizeof(LNode));
	L->pre = NULL;
	L->next = NULL;
	for (int i = 1; i <= 10; i++) {
		ListInsert_DuL(L, i, i * 2);
	}
	printf("%d", GetElem_DuL(L, 4));

	return 0;
}
int GetElem_DuL(LNode* L, int i) {
	LNode* p = L -> next;
	int j = 1;
	while (p != NULL && j < i) {
		p = p -> next;
		j++;
	}
	if (p == NULL || i < 1) {
		return 0;
	}
	return p -> data;
}
struct DuLNode* GetElemP_DuL(LNode* L, int i) {
	LNode* p = L -> next;
	int j = 1;
	while (p != NULL && j < i) {
		p = p -> next;
		j++;
	}
	if (p == NULL || i < 1) {
		return NULL;
	}
	return p;
}
int ListInsert_DuL(LNode* L, int i, int e) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (!(p = GetElemP_DuL(L, i))) {
		return 0;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s -> data = e;
	s -> pre = p -> pre, p -> pre -> next = s;
	s -> next = p, p -> pre = s;
	return 1;
}
int ListDelete_DuL(LNode* L, int i) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (!(p = GetElemP_DuL(L, i))) {
		return 0;
	}
	p -> pre -> next = p -> next;
	p -> next -> pre = p -> pre;
	free(p);
	return 1;
}