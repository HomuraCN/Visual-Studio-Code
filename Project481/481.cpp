#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HTNode {
	int weight;
	int parent, lchild, rchild;
}HTNODE;

typedef char **HuffmanCode;

void HuffmanCoding(HTNODE*& HT, HuffmanCode& HC, int* w, int n);
void Select(HTNODE* HT, int x, int& s1, int& s2);
void printHuffmanCoding(HuffmanCode HC, char str[], int n);
void decipher(HTNODE* HT, char* str, char cypher[], int length, char* result, int n);

const int N = 110;
int s1, s2;

int main() {
	int n, w[N];
	char str[N];
	HTNODE* HT = NULL;
	HuffmanCode HC;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		getchar();
		scanf("%c %d", &str[i], &w[i]);
	}
	HuffmanCoding(HT, HC, w, n);
	printf("\n");
	printHuffmanCoding(HC, str, n);
	char cypher[30];
	scanf("%s", cypher);
	int length = strlen(cypher);
	char result[30];
	decipher(HT, str, cypher, length, result, n);
	printf("%s", result);

	return 0;
}
void HuffmanCoding(HTNODE*& HT, HuffmanCode& HC, int* w, int n) {
	if (n <= 1) {
		return;
	}
	int i;
	int m = 2 * n - 1;
	HT = (HTNODE*)malloc((m + 1) * sizeof(HTNODE));
	HTNODE* p = NULL;
	w++;
	for (p = HT + 1, i = 1; i <= n; i++, p++, w++) {
		*p = { *w, 0, 0, 0 };
	}
	for (; i <= m; i++, p++) {
		*p = { 0, 0, 0, 0 };
	}
	for (i = n + 1; i <= m; i++) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	char* cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	int c, f, start;
	for (i = 1; i <= n; i++) {
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c) {
				cd[--start] = '0';
			}
			else {
				cd[--start] = '1';
			}
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}
void Select(HTNODE* HT, int x, int &s1, int &s2) {
	int Min = 0x7fffffff, minp = 0;
	for (int i = 1; i <= x; i++) {
		if (HT[i].parent == 0) {
			if (Min > HT[i].weight) {
				Min = HT[i].weight;
				minp = i;
			}
		}
	}
	s1 = minp;
	Min = 0x7fffffff;
	for (int i = 1; i <= x; i++) {
		if (HT[i].parent == 0 && i != s1) {
			if (Min > HT[i].weight) {
				Min = HT[i].weight;
				minp = i;
			}
		}
	}
	s2 = minp;
}
void printHuffmanCoding(HuffmanCode HC, char str[], int n) {
	for (int i = 1; i <= n; i++) {
		printf("%c %s\n", str[i], HC[i]);
	}
	printf("\n");
}
void decipher(HTNODE* HT, char* str, char cypher[], int length, char* result, int n) {
	int p = 2 * n - 1;
	int i = 0;
	int j = 0;
	while (i < length) {
		if (cypher[i] == '0') {
			p = HT[p].lchild;
		}
		if (cypher[i] == '1') {
			p = HT[p].rchild;
		}

		if (p <= N) {
			result[j] = str[p];
			j++;
			p = 2 * n - 1;
		}
		i++;
	}
	result[j] = '\0';
}