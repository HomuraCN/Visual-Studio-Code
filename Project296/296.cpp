#include <stdio.h>

void BuildSegmentTree(long long s, long long t, long long p);
void Update(long long l, long long r, long long c, long long s, long long t, long long p);
long long GetSum(long long l, long long r, long long s, long long t, long long p);

const int maxn = 200010;
int t;
long long n, m;
long long a[maxn] = { 0 }, d[maxn * 3], b[maxn * 3] = { 0 }/*懒惰标记*/, qujian[maxn];

int main() {
	scanf("%d", &t);
	for (int f = 1; f <= t; f++) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &qujian[i]);
		}
		BuildSegmentTree(1, n, 1);
		for (int i = 1; i <= n; i++) {
			if (qujian[i] == 0) {
				continue;
			}
			else {
				if (i - qujian[i] < 0) {
					Update(1, i, 1, 1, n, 1);
				}
				else {
					Update(i - qujian[i] + 1, i, 1, 1, n, 1);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (GetSum(i, i, 1, n, 1) == 0) {
				printf("0 ");
			}
			else {
				printf("1 ");
			}
		}
		printf("\n");
		for (int i = 0; i < maxn * 2; i++) {
			d[i] = 0;
			b[i] = 0;
		}
	}

	return 0;
}
void BuildSegmentTree(long long s, long long t, long long p) {
	if (s == t) {
		d[p] = a[s];
		return;
	}
	else {
		long long m = (s + t) / 2;
		BuildSegmentTree(s, m, p * 2);
		BuildSegmentTree(m + 1, t, p * 2 + 1);
		d[p] = d[p * 2] + d[p * 2 + 1];
	}
}
void Update(long long l, long long r, long long c, long long s, long long t, long long p) {
	if (l <= s && t <= r) {
		d[p] += (t - s + 1) * c;
		b[p] += c;
		return;
	}
	else {
		long long m = (s + t) / 2;
		if (b[p] != 0 && s != t) {
			d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
			b[p * 2] += b[p], b[p * 2 + 1] += b[p];/*懒惰标记下传*/
			b[p] = 0;/*清空当前懒惰标记*/
		}
		if (l <= m) {
			Update(l, r, c, s, m, p * 2);
		}
		if (r > m) {
			Update(l, r, c, m + 1, t, p * 2 + 1);
		}
		d[p] = d[p * 2] + d[p * 2 + 1];
	}
}
long long GetSum(long long l, long long r, long long s, long long t, long long p) {
	if (l <= s && t <= r) {
		return d[p];
	}
	else {
		long long m = (s + t) / 2;
		if (b[p] != 0) {
			d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
			b[p * 2] += b[p], b[p * 2 + 1] += b[p];
			b[p] = 0;
		}
		long long sum = 0;
		if (l <= m) {
			sum += GetSum(l, r, s, m, p * 2);
		}
		if (r > m) {
			sum += GetSum(l, r, m + 1, t, p * 2 + 1);
		}
		return sum;
	}
}