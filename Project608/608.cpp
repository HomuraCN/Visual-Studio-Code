#include <stdio.h>

const int maxn = 1e2 + 10;
int t, n;
char str[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		int flag = 0;
		scanf("%d", &n);
		scanf("%s", str + 1);
		str[0] = '!';
		for (int i = 1; i <= n; i++) {
			if (str[i] != '?') {
				flag = 1;
			}
		}
		if (flag == 0) {
			for (int i = 1; i <= n; i++) {
				if (i % 2 == 0) {
					printf("R");
				}
				else {
					printf("B");
				}
			}
			printf("\n");
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (i == n && str[i] == '?') {
				int k;
				for (k = i; k > 0; k--) {
					if (str[k] != '?') {
						break;
					}
				}
				k++;
				for (k; k <= n; k++) {
					if (str[k - 1] == 'R') {
						str[k] = 'B';
					}
					else {
						str[k] = 'R';
					}
				}
			}
			else {
				if (str[i] != '?') {
					for (int j = i - 1; j > 0; j--) {
						if (str[j] != '?') {
							break;
						}
						else {
							if (str[j + 1] == 'R') {
								str[j] = 'B';
							}
							else {
								str[j] = 'R';
							}
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}

	return 0;
}