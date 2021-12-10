#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn = 1e3 + 10;
int n;
double delta;
char str[maxn];

int main() {
	while (cin>>n) {
		delta = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			int len = strlen(str);
			if (str[len - 1] >= '5') {
				delta += ((10 - (str[len - 1] - '0')) * 0.001);
			}
			else {
				delta -= ((str[len - 1] - '0') * 0.001);
			}
		}
		printf("%.3lf\n", delta);
	}

	return 0;
}