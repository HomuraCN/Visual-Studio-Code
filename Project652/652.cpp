#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;

const int maxn = 1e6 + 10;
int t, n, m;

int main() {
	scanf("%d", &t);
	while (t--) {
		LL r, c;
		char str[maxn];
		scanf("%d %d", &n, &m);
		scanf("%s", str + 1);
		LL index = 0, maxxR = 0, minnL = 0, limit = m;
		for (int i = 1; i <= strlen(str + 1); i++) {
			if (maxxR - minnL + 1 == limit) {
				break;
			}
			if (str[i] == 'R') {
				index++;
			}
			else if(str[i] == 'L') {
				index--;
			}
			if (index > maxxR) {
				maxxR = index;
			}
			if (index < minnL) {
				minnL = index;
			}
		}
		c = 1 - minnL;
		index = 0, limit = n;
		LL maxxD = 0, minnU = 0;
		for (int i = 1; i <= strlen(str + 1); i++) {
			if (maxxD - minnU + 1 == limit) {
				break;
			}
			if (str[i] == 'D') {
				index++;
			}
			else if(str[i] == 'U') {
				index--;
			}
			if (index > maxxD) {
				maxxD = index;
			}
			if (index < minnU) {
				minnU = index;
			}
		}
		r = 1 - minnU;
		printf("%lld %lld\n", r, c);
	}

	return 0;
}