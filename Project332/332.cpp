#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct Stack {
	char* base;
	char* top;
	int stacksize;
}STACK;

int InitStack(STACK& S);
int GetTop(STACK S, char& e);
int Push(STACK& S, char e);
int Pop(STACK& S, char& e);
int DestroyStack(STACK& S);
int StackEmpty(STACK S);
int StackSize(STACK S);

int main() {
	STACK S;
	int i = 0, len;
	char e;
	char str[100];
	scanf("%s", str);
	InitStack(S);
	len = strlen(str);
	for (i = 0; i < len; i++) {
		Push(S, str[i]);
	}
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%c", e);
	}

	return 0;
}
int InitStack(STACK &S) {
	S.base = (char*)malloc(sizeof(char));
	if (S.base == NULL) {
		return 0;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
int GetTop(STACK S, char &e) {
	if (S.top == S.base) {
		return 0;
	}
	else {
		e = *(S.top - 1);
	}
}
int Push(STACK &S, char e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (char*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(char));
		if (S.base == NULL) {
			return 0;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 1;
}
int Pop(STACK &S, char &e) {
	if (S.top == S.base) {
		return 0;
	}
	else {
		e = *(--S.top);
		return 1;
	}
}
int DestroyStack(STACK &S) {
	free(S.base);
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
	return 1;
}
int StackEmpty(STACK S) {
	if (S.base == S.top) {
		return 1;
	}
	else {
		return 0;
	}
}
int StackSize(STACK S) {
	return S.top - S.base;
}