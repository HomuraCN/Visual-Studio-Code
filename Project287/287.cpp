#include <stdio.h>

int Func1();
int Func2();
int Func3();

int n, flag = 1;
char str[30][30];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	flag = Func1();
	if (flag == 0) {
		printf("0");
		return 0;
	}
	flag = Func2();
	if (flag == 0) {
		printf("0");
		return 0;
	}
	flag = Func3();
	if (flag == 0) {
		printf("0");
		return 0;
	}
	else {
		printf("1");
	}

	return 0;
}
int Func1() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[0][i] == 'B') {
			cnt++;
		}
	}
	for (int i = 1; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			if (str[i][j] == 'B') {
				temp++;
			}
		}
		if (cnt != temp) {
			return 0;
		}
	}
	return 1;
}
int Func2() {
	for (int j = 1; j < n; j++) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			if (str[i][j] == 'B') {
				temp++;
			}
		}
		if (temp != n / 2) {
			return 0;
		}
	}
	return 1;
}
int Func3() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 2; j++) {
			if (str[i][j] == str[i][j + 1] && str[i][j] == str[i][j + 2]) {
				return 0;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 2; i++) {
			if (str[i][j] == str[i + 1][j] && str[i][j] == str[i + 2][j]) {
				return 0;
			}
		}
	}
	return 1;
}