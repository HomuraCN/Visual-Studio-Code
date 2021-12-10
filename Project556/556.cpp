#include <stdio.h>
#define int long long

void Merge(int A[], int p, int q, int r);
void MergeSort(int A[], int p, int r);

const int maxn = 5e5 + 10;
int n, sum = 0, A[maxn];
int A1[maxn], A2[maxn];

signed main() {
	scanf("%lld", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &A[i]);
	}

	MergeSort(A, 1, n);

	printf("%lld", sum);

	return 0;
}
void Merge(int A[], int p, int q, int r) {
	int len1 = q - p + 1, len2 = r - (q + 1) + 1;

	for (int i = 1; i <= len1; i++) {
		A1[i] = A[p + i - 1];
	}
	for (int i = 1; i <= len2; i++) {
		A2[i] = A[q + i];
	}

	A1[len1 + 1] = 0x7fffffff, A2[len2 + 1] = 0x7fffffff;

	int j = 1, k = 1;

	for (int i = p; i <= r; i++) {
		if (A1[j] <= A2[k]) {
			A[i] = A1[j];
			j++;
		}
		else if (A1[j] > A2[k]) {
			A[i] = A2[k];
			k++;
			sum += len1 - j + 1;
		}
	}

	return;
}
void MergeSort(int A[], int p, int r) {
	if (p >= r) {
		return;
	}
	else if (p < r) {
		int q = (p + r) / 2;

		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);

		return;
	}
}