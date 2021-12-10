#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct Node
{
	int key;
	int lsum, rsum;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
}NODE;

void TreeInsert();
void Transplant(NODE* u, NODE* v);
void TreeDelete(NODE* z);
NODE* IterativeTreeSearch(NODE* x, int k);
NODE* TreeMinimum(NODE* x);
NODE* TreeMaximun(NODE* x);
NODE* Successor(NODE* x);
NODE* Predecessor(NODE* x);
int kth(Node* now, int K);
int xth(Node* now, int x, int K);
void InorderTreeWalk(NODE* x);
void DestroyBiTree(NODE* x);

int q, operate, KEY;
NODE *root;

int main() {
	NODE* ans;
	root = NULL;

	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		scanf("%d %d", &operate, &KEY);
		if (operate == 1) {
			printf("%d\n", xth(root, KEY, 0) + 1);
		}
		else if (operate == 2) {
			printf("%d\n", kth(root, KEY));
		}
		else if (operate == 3) {
			NODE* x = root;
			ans = Predecessor(IterativeTreeSearch(x, KEY));
			if (ans == NULL) {
				printf("−2147483647\n");
			}
			else {
				printf("%d\n", ans->key);
			}
		}
		else if (operate == 4) {
			NODE* x = root;
			ans = Successor(IterativeTreeSearch(x, KEY));
			if (ans == NULL) {
				printf("2147483647\n");
			}
			else {
				printf("%d\n", ans->key);
			}
		}
		else if (operate == 5) {
			TreeInsert();
		}
		else if (operate == 6) {
			TreeDelete(root->left);
		}
	}
	InorderTreeWalk(root);
	DestroyBiTree(root);

	return 0;
}
void TreeInsert() {
	NODE *z = (NODE*)malloc(sizeof(NODE));
	z->key = KEY, z->left = NULL, z->parent = NULL, z->right = NULL, z->lsum = 0, z->rsum = 0;
	NODE *x, *y;
	y = NULL;
	x = root;
	while (x != NULL) {
		y = x;
		if (z->key <= x->key) {
			x->lsum++;
			x = x->left;
		}
		else {
			x->rsum++;
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NULL) {
		root = z;
	}
	else if (z->key <= y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
}
void Transplant(NODE* u, NODE* v) {
	if (u->parent == NULL) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	if (v != NULL) {
		v->parent = u->parent;
	}
}
void TreeDelete(NODE* z) {
	NODE* y;
	if (z->left == NULL) {
		Transplant(z, z->right);
	}
	else if (z->right == NULL) {
		Transplant(z, z->left);
	}
	else {
		y = TreeMinimum(z->right);
		if (y->parent != z) {
			Transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}
NODE* IterativeTreeSearch(NODE* x, int k) {
	while (x != NULL && k != x->key) {
		if (k <= x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}
NODE* TreeMinimum(NODE* x) {
	while (x->left !=	NULL) {
		x = x->left;
	}
	return x;
}
NODE* TreeMaximun(NODE* x) {
	while (x->right != NULL) {
		x = x->right;
	}
	return x;
}
NODE* Successor(NODE* x) {
	NODE* y;
	if (x->right != NULL) {
		return TreeMinimum(x->right);
	}
	y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}
NODE* Predecessor(NODE* x) {
	NODE* y;
	if (x->left != NULL) {
		return TreeMaximun(x->left);
	}
	y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = y->parent;
	}
	return y;
}
int kth(Node* now, int K) 
{
	if (!now)
		return 2147483647;
	int tmp = now->lsum + 1;
	if (tmp == K)
		return now->key;
	if (tmp < K)
		return kth(now->right, (K - tmp));
	else
		return kth(now->left, K);
}
int xth(Node* now, int x, int K) {
	if (!now) return K;
	if (now->key == x)
		return K + now->lsum + 1;
	if (now->key < x)
		return xth(now->right, x, K + (now->lsum + 1));
	else
		return xth(now->left, x, K);
}
void InorderTreeWalk(NODE* x) {
	if (x != NULL) {
		InorderTreeWalk(x->left);
		printf("%d ", x->key);
		InorderTreeWalk(x->right);
	}
}
void DestroyBiTree(NODE* x) { /* 初始条件：二叉树T存在。操作结果：销毀二叉树T */
	if (x->parent != NULL) {/* 非空树 */
		if (x->left != NULL) /* 有左孩子 */
			DestroyBiTree(x->left); /* 销毀左孩子子树 */
		if (x->right != NULL) /* 有右孩子 */
			DestroyBiTree(x->right); /* 销毀右孩子子树 */
		free(x); /* 释放根结点 */
		x = NULL;
	}
}