#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void BuildSegmentTree(long long s, long long t, long long p);
void Update(long long l, long long r, long long c, long long s, long long t, long long p);
long long GetSum(long long l, long long r, long long s, long long t, long long p);

const int maxn = 55;
long long t, n, k;
long long a[maxn] = { 0 }, d[maxn * 3], b[maxn * 3] = { 0 }/*懒惰标记*/;

int main() {
	scanf("%d", &t);
	while (t--) {
		for (int i = 1; i < maxn; i++) {
			a[i] = 0;
		}
		for (int i = 1; i < maxn * 3; i++) {
			d[i] = 0;
			b[i] = 0;
		}
		int cnt = 0;
		string str = "";
		scanf("%d %d", &n, &k);
		cin >> str;
		if (str.length() == 1 && str[0] == '.') {
			printf("0\n");
			continue;
		}
		if (str[0] == '*') {
			str[0] = 'x';
			a[1] = 1;
			cnt++;
		}
		if (str[str.length() - 1] == '*') {
			str[str.length() - 1] = 'x';
			a[str.length()] = 1;
			cnt++;
		}
		BuildSegmentTree(1, n, 1);
		int flag = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '*' || str[i] == 'x') {
				flag++;
			}
		}
		if (flag == 1) {
			printf("1\n");
			continue;
		}
		for (int i = 1; i <= n - k + 1; i++) {
			int temp = GetSum(i, i + k - 1, 1, n, 1);
			if (temp == 0) {
				cnt++;
				Update(i + k - 1, i + k - 1, 1, 1, n, 1);
			}
			/*if (GetSum(i, i + k - 1, 1, n, 1) == 0) {
				cnt++;
				Update(i + k - 1, i + k - 1, 1, 1, n, 1);
			}*/
		}
		printf("%d\n", cnt);
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