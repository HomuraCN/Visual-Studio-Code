#include <stdio.h>
#include <stdlib.h>

typedef enum PointerTag {
	Link, Thread
};

typedef struct BiThrNode {
	char data;
	struct BiThrNode* left;
	struct BiThrNode* right;
	PointerTag LTag, RTag;
}BITHRNODE;

void CreateBiTree(BITHRNODE*& root);
void InorderTreeWalk(BITHRNODE* node);
void InorderThreading(BITHRNODE*& Thrt, BITHRNODE* root);
void InThreating(BITHRNODE* p);
void InorderWalk_Thr(BITHRNODE* Thrt);

BITHRNODE* pre = NULL;

int main() {
	BITHRNODE* Thrt;
	BITHRNODE* root;
	CreateBiTree(root);
	InorderTreeWalk(root);
	printf("\n");
	InorderThreading(Thrt, root);
	InorderWalk_Thr(Thrt);
	printf("\n");

	return 0;
}
void CreateBiTree(BITHRNODE*& root) {
	char ch = getchar();
	if (ch == ' ') {
		root = NULL;
	}
	else {
		root = (BITHRNODE*)malloc(sizeof(BITHRNODE));
		root->data = ch;
		root->LTag = Link;
		root->RTag = Link;
		CreateBiTree(root->left);
		CreateBiTree(root->right);
	}
}
void InorderTreeWalk(BITHRNODE* node) {
	if (node != NULL) {
		InorderTreeWalk(node->left);
		printf("%c", node->data);
		InorderTreeWalk(node->right);
	}
}
void InorderThreading(BITHRNODE*& Thrt, BITHRNODE* root) {
	Thrt = (BITHRNODE*)malloc(sizeof(BITHRNODE));
	Thrt->LTag = Link;
	Thrt->RTag = Thread;
	Thrt->right = Thrt;
	if (root == NULL) {
		Thrt->left = Thrt;
	}
	else {
		Thrt->left = root;
		pre = Thrt;
		InThreating(root);
		pre->right = Thrt;
		pre->RTag = Thread;
		Thrt->right = pre;
	}
}
void InThreating(BITHRNODE* p) {
	if (p != NULL) {
		InThreating(p->left);
		if (p->left == NULL) {
			p->LTag = Thread;
			p->left = pre;
		}
		if (pre->right == NULL) {
			pre->RTag = Thread;
			pre->right = p;
		}
		pre = p;
		InThreating(p->right);
	}
}
void InorderWalk_Thr(BITHRNODE* Thrt) {
	BITHRNODE* p = Thrt->left;
	while (p != Thrt) {
		while (p->LTag == Link) {
			p = p->left;
		}
		printf("%c", p->data);
		while (p->RTag == Thread && p->right != Thrt) {
			p = p->right;
			printf("%c", p->data);
		}
		p = p->right;
	}
}
