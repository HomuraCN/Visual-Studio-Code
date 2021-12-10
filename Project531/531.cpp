#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 10;
int t;
int num[maxn];

int main() {
	scanf("%d", &t);
	while (t--) {
		int s1, s2, s3, s4, maxxleft = 0, maxxright = 0;
		scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
		num[1] = s1, num[2] = s2, num[3] = s3, num[4] = s4;
		sort(num + 1, num + 1 + 4);
		maxxleft = max(s1, s2);
		maxxright = max(s3, s4);
		if ((maxxleft > maxxright) && num[3] == maxxright && num[4] == maxxleft) {
			printf("YES\n");
		}
		else if ((maxxleft < maxxright) && num[3] == maxxleft && num[4] == maxxright) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}