#include <stdio.h>
#include <string.h>

const int maxn = 1e2 + 10;
int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		int flag = 0;
		scanf("%d", &n);
		char str[maxn];
		scanf("%s", str);
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == 'U') {
				flag = 1;
				break;
			}
			if (str[i] == 'D') {
				flag = 2;
				break;
			}
		}
		if (flag == 0) {
			printf("%s\n", str);
		}
		else if (flag == 1) {
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == 'U') {
					printf("D");
				}
				else {
					printf("%c", str[i]);
				}
			}
			printf("\n");
		}
		else if (flag == 2) {
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == 'D') {
					printf("U");
				}
				else {
					printf("%c", str[i]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}