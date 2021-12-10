#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

void GetPrime(int n);

const int maxn = 5e5 + 10;
int minn = 0x7fffffff, a[maxn], prime[100000010], visit[100000010] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	GetPrime(maxn);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int start = lower_bound(a, a + n, n) - a;
	for (int i = start; i < 100000010; i ++) {
		int flag = 0;
		memset(visit, 0, sizeof(visit));
		int j; 
		for (j = 0; j < n; j++) {
			int MOD = a[j] % prime[i];
			if (visit[MOD] == 1) {
				flag = 1;
				break;
			}
			else {
				visit[MOD] = 1;
			}
		}
		if (j == n && flag == 0) {
			minn = prime[i];
			break;
		}
	}
	for (int i = n; i < minn; i++) {
		memset(visit, 0, sizeof(visit));
		int j;
		for (j = 0; j < n; j++) {
			int MOD = a[j] % i;
			if (visit[MOD] == 1) {
				break;
			}
			else {
				visit[MOD] = 1;
			}
		}
		if (j == n) {
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", minn);

	return 0;
}
void GetPrime(int n) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (visit[i] == 0) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] <= n; j++) {
			visit[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}