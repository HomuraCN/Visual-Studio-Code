#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct CSNode {
	char data;
	struct CSNode* firstchild;
	struct CSNode* nextsibling;
}CSNODE;

void CreateCSTree(CSNODE*& T);
void PreorderCSTreeWalk(CSNODE* T);

queue<CSNODE*> Q;

int main() {
	CSNODE* T = (CSNODE*)malloc(sizeof(CSNODE));
	CreateCSTree(T);
	PreorderCSTreeWalk(T);

	return 0;
}
void CreateCSTree(CSNODE*& T) {
	char ch;
	string str;
	CSNODE* p;
	CSNODE* temp;
	ch = getchar();
	T->data = ch;
	T->nextsibling = NULL;
	Q.push(T);
	while (!Q.empty()) {
		temp = Q.front();
		Q.pop();
		cin >> str;
		if (str.size() > 0 && str[0] != '#') {
			p = (CSNODE*)malloc(sizeof(CSNODE));
			temp->firstchild = p;
			p->data = str[0];
			for (int i = 1; i < str.size(); i++) {
				p->nextsibling = (CSNODE*)malloc(sizeof(CSNODE));
				Q.push(p);
				p = p->nextsibling;
				p->data = str[i];
			}
			p->nextsibling = NULL;
			Q.push(p);
		}
		else {
			temp->firstchild = NULL;
		}
	}
}
void PreorderCSTreeWalk(CSNODE* T) {
	if (T != NULL) {
		printf("%c", T->data);
		PreorderCSTreeWalk(T->firstchild);
		PreorderCSTreeWalk(T->nextsibling);
	}
}