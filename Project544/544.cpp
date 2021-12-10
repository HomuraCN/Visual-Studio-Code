#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	int* s;
}LIST;

void InitList(LIST& L);
void InsertionSort(LIST& L);
void BubbleSort(LIST& L);
void SelectSort(LIST& L);

int n = 10;

int main() {
	LIST L;
	InitList(L);
	SelectSort(L);
	for (int i = 1; i <= n; i++) {
		printf("%d ", L.s[i]);
	}

	return 0;
}
void InitList(LIST &L) {
	L.s = (int*)malloc(100 * sizeof(int));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &L.s[i]);
	}
}
void InsertionSort(LIST &L) {
	for (int i = 2; i <= n; i++) {
		int key = L.s[i];
		int j = i - 1;
		while (j > 0 && L.s[j] > key) {
			L.s[j + 1] = L.s[j];
			j--;
		}
		L.s[j + 1] = key;
	}
}
void BubbleSort(LIST &L) {
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (L.s[j] > L.s[j + 1]) {
				L.s[j] ^= L.s[j + 1];
				L.s[j + 1] ^= L.s[j];
				L.s[j] ^= L.s[j + 1];
			}
		}
	}
}
void SelectSort(LIST &L) {
	for (int i = 1; i <= n - 1; i++) {
		int flag = i;
		for (int j = i + 1; j <= n; j++) {
			if (L.s[j] < L.s[flag]) {
				flag = j;
			}
		}
		if (i != flag) {
			L.s[i] ^= L.s[flag];
			L.s[flag] ^= L.s[i];
			L.s[i] ^= L.s[flag];
		}
	}
}