/*队列的循环表示*/
#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100

typedef struct SqQueue {
	int* base;
	int head;
	int tail;
}SQQUEUE;

void InitialQueue(SQQUEUE& Q);
int InsertQueue(SQQUEUE& Q, int e);
int DeleteQueue(SQQUEUE& Q, int& e);
int QueueLength(SQQUEUE Q);

int main() {
	SQQUEUE Q;
	InitialQueue(Q);
	for (int i = 1; i <= MAXQSIZE - 10; i++) {
		InsertQueue(Q, i);
	}
	printf("%d\n", QueueLength(Q));
	int e;
	for (int i = 1; i <= MAXQSIZE - 10; i++) {
		DeleteQueue(Q, e);
		printf("%d ", e);
	}

	return 0;
}
void InitialQueue(SQQUEUE& Q) {
	Q.base = (int*)malloc(MAXQSIZE * sizeof(int));
	Q.head = Q.tail = 0;
}
int InsertQueue(SQQUEUE& Q, int e) {
	if ((Q.tail + 1) % MAXQSIZE == Q.head) {
		return 0;
	}
	else {
		Q.base[Q.tail] = e;
		Q.tail = (Q.tail + 1) % MAXQSIZE;
		return 1;
	}
}
int DeleteQueue(SQQUEUE& Q, int& e) {
	if (Q.head == Q.tail) {
		return 0;
	}
	else {
		e = Q.base[Q.head];
		Q.head = (Q.head + 1) % MAXQSIZE;
		return 1;
	}
}
int QueueLength(SQQUEUE Q) {
	return (Q.tail - Q.head + MAXQSIZE) % MAXQSIZE;
}
