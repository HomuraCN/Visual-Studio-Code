#include <stdio.h>

int Max(int x, int y) {
	return x >= y ? x : y;
}

int n, maxx = 0;
int num1[210] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		num1[temp] = 1;
		maxx = Max(maxx, temp);
	}
	int flag = 0;
	for (int i = 1; i <= maxx; i++) {
		if (num1[i] == 0) {
			printf("%d\n", i);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("good job");
	}

	return 0;
}