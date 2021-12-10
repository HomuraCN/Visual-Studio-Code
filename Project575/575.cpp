#include <stdio.h>
#include <string.h>

const int maxr = 35, maxc = 110;
int T;
bool C[maxc];

int main() {
	scanf("%d", &T);
	int temp = T;
	while (T--) {
		memset(C, false, sizeof(C));
		char str[maxr][maxc];
		for (int i = 1; i <= 30; i++) {
			scanf("%s", str[i] + 1);
		}
		printf("Case #%d:\n", temp - T);
		for (int i = 1; i <= 30; i++) {
			for (int j = 1; j <= 100; j++) {
				if (str[i][j] == '#') {
					C[j] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= 100; i++) {
			if (C[i] != C[i + 1]) {
				cnt++;
				if (cnt % 2 == 1) {
					printf("%d ", i + 1);
				}
				else {
					printf("%d\n", i);
				}
			}
		}
	}

	return 0;
}