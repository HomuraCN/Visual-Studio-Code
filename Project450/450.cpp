#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode* next;
}LNode;

typedef struct LinkQueue
{
    LNode* rear;
}LQueue;

void InitQueue(LQueue* LQ);
void EnQueue(LQueue* LQ, int x);
void Dequeue(LQueue* LQ, int* x);

int main()
{
    LQueue LQ;
    InitQueue(&LQ);
    for (int i = 1; i <= 10; i++) {
        EnQueue(&LQ, i * 3);
    }
    for (int i = 1; i <= 10; i++) {
        int test;
        Dequeue(&LQ, &test);
        printf("%d\n", test);
    }

    return 0;
}
void Dequeue(LQueue* LQ, int* x) {
    LNode* p, * h;
    if (LQ->rear == LQ->rear->next) {
        printf("Пе\n");
    }
    else {
        h = LQ->rear->next;
        p = h->next;
        *x = p->data;
        h->next = p->next;
        if (p == LQ->rear) {
            LQ->rear = h;
        }
        free(p);
    }
}
void EnQueue(LQueue* LQ, int x) {
    LNode* p;
    p = (LNode*)malloc(sizeof(LNode));
    p->data = x;
    p->next = LQ->rear->next;
    LQ->rear->next = p;
    LQ->rear = p;
}
void InitQueue(LQueue* LQ) {
    LNode* p;
    p = (LNode*)malloc(sizeof(LNode));
    LQ->rear = p;
    p->next = LQ->rear;
}