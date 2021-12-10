#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int length;
}LIST;

void CreateList(LIST& L);
int SequentialSearch(LIST L, int key);
int BinarySearch(LIST L, int key);

int main() {
	LIST L1, L2;
	L1.length = 15;
	CreateList(L1);
	printf("%d\n", SequentialSearch(L1, 10));
	printf("%d\n", BinarySearch(L1, 7));

	return 0;
}
void CreateList(LIST& L) {
	L.data = (int*)malloc(L.length * sizeof(int));
	for (int i = 1; i < L.length; i++) {
		scanf("%d", &L.data[i]);
	}
}
int SequentialSearch(LIST L, int key) {
	int i;
	for (i = L.length - 1; i > 0; i--) {
		if (L.data[i] == key) {
			break;
		}
	}
	return i;
}
int BinarySearch(LIST L, int key) {
	int left = 1, right = L.length - 1, mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (L.data[mid] > key) {
			right = mid - 1;
		}
		else if (L.data[mid] < key) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
}