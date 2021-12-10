#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
	int* data;
	int length;
	int listsize;
}SqList;

int main() {
	SqList L;
	InitList_Sq(L);

	return 0;
}
void InitList_Sq(SqList &L) {
	L.data = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}
void Insert(SqList &L, int i, int e) {
	if (L.length >= L.listsize) {
		L.data = (int*)realloc(L.data, (L.listsize + LISTINCREMENT) * sizeof(int));
		L.listsize += LISTINCREMENT;
	}
	int* q = &L.data[i - 1];
	for (int* p = &L.data[L.length - 1]; p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = e;
	L.length++;
}