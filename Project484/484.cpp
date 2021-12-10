#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#define re register
#define lowbit(x) ((x)&(-(x)))
#define maxn 100005
#define LL long long
const LL mod = 1e9 + 7;
std::map<LL, LL> ma;
LL c[maxn];
int n, count = 0;
LL a[maxn], b[maxn];
LL lastans[maxn];
int f[maxn];
int flag[20] = { 0 };
char str[1000010];

inline void add(int x, LL v)
{
	for (re LL i = x; i <= n; i += lowbit(i))
		c[i] = (c[i] + v) % mod;
}
inline LL query(LL x)
{
	LL ans = 0;
	for (re LL i = x; i; i -= lowbit(i))
		ans = (ans + c[i]) % mod;
	return ans;
}
signed main()
{
	scanf("%s", str + 1);
	for (re int i = 1; i <= n; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			a[i] = b[i] = str[i] - 'A' + 10;
			if (flag[a[i]] == 0) {
				flag[a[i]] = 1;
				count++;
			}
		}
		else {
			a[i] = b[i] = str[i] - '0';
			if (flag[a[i]] == 0) {
				flag[a[i]] = 1;
				count++;
			}
		}
	}
	std::sort(b + 1, b + n + 1);
	int tot = std::unique(b + 1, b + 1 + n) - b - 1;
	for (re int i = 1; i <= tot; i++)
		ma[b[i]] = i;
	LL cnt = 0;
	for (re int i = 1; i <= n; i++)
	{
		int j = ma[a[i]];
		if (!f[j])
		{
			LL mid = query(j - 1);
			cnt = (cnt + mid) % mod;
			add(j, mid + 1);
			lastans[j] = mid;
			f[j] = 1;
			continue;
		}
		LL mid = query(j - 1);
		cnt = (cnt + mid - lastans[j] + mod) % mod;
		add(j, (mid - lastans[j] + 2 * mod) % mod);
		lastans[j] = mid;
	}
	std::cout << cnt + count;
	return 0;
}