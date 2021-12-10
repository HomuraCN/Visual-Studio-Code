#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 15;
int n;
int a[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (prev_permutation(a + 1, a + 1 + n) == true) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
	}
	else {
		printf("ERROR");
	}

	return 0;
}