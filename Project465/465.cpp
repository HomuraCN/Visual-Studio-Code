#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct BiTree {
	char data;
	struct BiTree* left;
	struct BiTree* right;
}BITREE;

void CreateBiTree(BITREE*& root);
void PreorderTreeWalk(BITREE* node);
void InorderTreeWalk(BITREE* node);
void PostorderTreeWalk(BITREE* node);
void BFS(BITREE* root);
int LeafCount(BITREE* root);

int main() {
	BITREE* root;
	CreateBiTree(root);
	PreorderTreeWalk(root);
	printf("\n");
	InorderTreeWalk(root);
	printf("\n");
	PostorderTreeWalk(root);
	printf("\n");
	BFS(root);
	printf("\n");
	printf("%d\n", LeafCount(root));

	return 0;
}
void CreateBiTree(BITREE* &root) {
	char ch = getchar();
	if (ch == ' ') {
		root = NULL;
	}
	else {
		root = (BITREE*)malloc(sizeof(BITREE));
		root->data = ch;
		CreateBiTree(root->left);
		CreateBiTree(root->right);
	}
}
void PreorderTreeWalk(BITREE* node) {
	if (node != NULL) {
		printf("%c", node->data);
		PreorderTreeWalk(node->left);
		PreorderTreeWalk(node->right);
	}
}
void InorderTreeWalk(BITREE* node) {
	if (node != NULL) {
		InorderTreeWalk(node->left);
		printf("%c", node->data);
		InorderTreeWalk(node->right);
	}
}
void PostorderTreeWalk(BITREE* node) {
	if (node != NULL) {
		PostorderTreeWalk(node->left);
		PostorderTreeWalk(node->right);
		printf("%c", node->data);
	}
}
void BFS(BITREE* root) {
	queue<BITREE*> Q;
	Q.push(root);
	while (!Q.empty()) {
		BITREE* temp = Q.front();
		Q.pop();
		printf("%c", temp->data);
		if (temp->left != NULL) {
			Q.push(temp->left);
		}
		if (temp->right != NULL) {
			Q.push(temp->right);
		}
	}
}
int LeafCount(BITREE* root) {
	if (root == NULL) {
		return 0;
	}
	else if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	else {
		return LeafCount(root->left) + LeafCount(root->right);
	}
}