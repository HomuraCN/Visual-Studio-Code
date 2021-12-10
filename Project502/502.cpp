#include <stdio.h>
#include <string.h>

const int maxn = 55;
int T, flag[130];

int main() {
	scanf("%d", &T);
	while (T--) {
		int F = 0;
		memset(flag, 0, sizeof(flag));
		int n;
		char str[maxn];
		scanf("%d", &n);
		scanf("%s", str);
		for (int i = 0; i < strlen(str) - 1; i++) {
			if (flag[str[i]] == 1) {
				F = 1;
			}
			if (str[i] != str[i + 1]) {
				flag[str[i]] = 1;
			}
		}
		/*
		for (int i = 0; i < strlen(str) - 1; i++) {
		}*/
		if (flag[str[strlen(str) - 1]] == 1) {
			F = 1;
		}
		if (F == 1) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}