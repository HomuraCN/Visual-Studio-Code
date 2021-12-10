#include <stdio.h>
#define LL long long

typedef struct Railway {
	LL A, B, C;
}RAILWAY;

void BuildSegmentTree(LL s, LL t, LL p);
void Update(LL l, LL r, LL c, LL s, LL t, LL p);
LL GetSum(LL l, LL r, LL s, LL t, LL p);
LL Max(LL x, LL y);
LL Min(LL x, LL y);

const int maxn = 100010;
LL N, M, city[maxn], sum = 0;
RAILWAY railway[maxn];
LL d[maxn * 3], b[maxn * 3];

int main() {
	scanf("%lld %lld", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%lld", &city[i]);
	}
	for (int i = 1; i < N; i++) {
		scanf("%lld %lld %lld", &railway[i].A, &railway[i].B, &railway[i].C);
	}
	BuildSegmentTree(1, N, 1);
	for (int i = 1; i < M; i++) {
		Update(Min(city[i], city[i + 1]), Max(city[i], city[i + 1]) - 1, 1, 1, N, 1);
	}
	for (int i = 1; i <= N - 1; i++) {
		LL times = GetSum(i, i, 1, N, 1);
		if (times * railway[i].A <= railway[i].C + times * railway[i].B) {
			sum += times * railway[i].A;
		}
		else {
			sum += railway[i].C + times * railway[i].B;
		}
	}
	printf("%lld", sum);

	return 0;
}
void BuildSegmentTree(LL s, LL t, LL p) {
	if (s == t) {/*到达叶节点*/
		d[p] = 0;
		return;
	}
	else {
		LL m = (s + t) / 2;
		BuildSegmentTree(s, m, p * 2);
		BuildSegmentTree(m + 1, t, p * 2 + 1);
		d[p] = d[p * 2] + d[p * 2 + 1];
	}
}
void Update(LL l, LL r, LL c, LL s, LL t, LL p) {
	if (l <= s && t <= r) {
		d[p] += (t - s + 1) * c;
		b[p] += c;
		return;
	}
	else {
		LL m = (s + t) / 2;
		if (b[p] != 0 && s != t) {
			d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
			b[p * 2] += b[p], b[p * 2 + 1] += b[p];
			b[p] = 0;
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
LL GetSum(LL l, LL r, LL s, LL t, LL p) {
	if (l <= s && t <= r) {
		return d[p];
	}
	else {
		LL m = (s + t) / 2;
		if (b[p] != 0) {
			d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
			b[p * 2] += b[p], b[p * 2 + 1] += b[p];
			b[p] = 0;
		}
		LL sum = 0;
		if (l <= m) {
			sum += GetSum(l, r, s, m, p * 2);
		}
		if (r > m) {
			sum += GetSum(l, r, m + 1, t, p * 2 + 1);
		}
		return sum;
	}
}
LL Max(LL x, LL y) {
	return x >= y ? x : y;
}
LL Min(LL x, LL y) {
	return x <= y ? x : y;
}