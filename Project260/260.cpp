#include <stdio.h>
#include <string.h>
#include <algorithm>
#define base 255
using namespace std;

unsigned long long Hash();

int N, num = 1;
unsigned long long h[10001];
char str[1510];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", str);
		h[i] = Hash();
	}

	sort(h + 1, h + 1+ N);

	for (int i = 1; i < N; i++) {
		if (h[i] != h[i + 1]) {
			num++;
		}
	}

	printf("%d", num);

	return 0;
}
unsigned long long Hash()
{
	int len = strlen(str);
	unsigned long long num = 0;
	for (int i = 0; i < len; i++) {
		num = num * base + (unsigned long long)str[i];
	}
	return num;
}