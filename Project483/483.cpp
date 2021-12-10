#include <stdio.h>
#include <math.h>

const int maxn = 100010;
int n;
char str[maxn];

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		int temp1, temp2;
		if (i % 2 == 1) {
			if (i > 25) {
				temp1 = i % 26;
			}
			else {
				temp1 = i;
			}
			if (str[i] + temp1 > 122) {
				temp2 = str[i] + temp1;
				str[i] = 'a' + (temp2 - 122 - 1);
			}
			else {
				str[i] = str[i] + temp1;
			}
		}
		else {
			if (i > 25) {
				temp1 = i % 26;
			}
			else {
				temp1 = i;
			}
			if (str[i] - temp1 < 97) {
				temp2 = str[i] - temp1;
				str[i] = 'z' - (97 - temp2 - 1);
			}
			else {
				str[i] = str[i] - temp1;
			}
		}
	}
	printf("%s", str + 1);

	return 0;
}