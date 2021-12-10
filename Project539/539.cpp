#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Ticket {
	int a;
	int b;
}TICKET;

bool cmp(TICKET x,	TICKET y) {
	return (x.a - x.b) > (y.a - y.b);
}

const int maxn = 1e3 + 10, maxk = 1e4 + 10;
int n, k, dp[maxk];
TICKET ticket[maxn];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &ticket[i].a, &ticket[i].b);
	}
	sort(ticket + 1, ticket + 1 + n, cmp);
	for (int i = 1; i <= k; i++) {
		dp[i] = i;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = k; j >= ticket[i].a; j--) {
			dp[j] = min(dp[j], dp[j - ticket[i].b]);
		}
	}
	printf("%d", dp[k]);

	return 0;
}