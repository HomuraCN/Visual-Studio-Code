#include <stdio.h>

const int maxn = 1e3;
char str[maxn];

int main() {
	scanf("%s", str);
	if (str[0] >= 'a' && str[0] <= 'z') {
		str[0] -= 32;
	}
	printf("%s", str);

	return 0;
}