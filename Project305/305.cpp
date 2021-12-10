#include <stdio.h>
#include <algorithm>
using namespace std;

struct Bottle {
	int position, num;
}bottle[100010];

bool cmp(struct Bottle x, struct Bottle y);

int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		bottle[i].position = i;
		scanf("%d", &bottle[i].num);
	}
	sort(bottle + 1, bottle + 1 + n, cmp);
	int Q;
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int m;
		scanf("%d", &m);
		int left = 1, right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (bottle[mid].num < m) {
				left = mid + 1;
			}
			else if (bottle[mid].num > m) {
				right = mid - 1;
			}
			else if (bottle[mid].num == m) {
				printf("%d\n", bottle[mid].position);
				break;
			}
		}
		if (left > right) {
			printf("0\n");
		}
	}

	return 0;
}
bool cmp(struct Bottle x, struct Bottle y) {
	return x.num <= y.num;
}