#include <stdio.h>
#include <math.h>
#include <algorithm>
#define LL long long
using namespace std;

LL maxSubArray(LL dif[]);

const int maxn = 1e5 + 10;
int n;
LL a[maxn];
LL dif1[maxn], dif2[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        if (i & 1) {
            dif1[i] = abs(a[i] - a[i + 1]);
            dif2[i] = -abs(a[i] - a[i + 1]);
        }
        else {
            dif1[i] = -abs(a[i] - a[i + 1]);
            dif2[i] = abs(a[i] - a[i + 1]);
        }
    }
    LL ans = 0;
    ans = max(maxSubArray(dif1), ans);
    ans = max(maxSubArray(dif2), ans);
    printf("%lld", ans);

	return 0;
}
LL maxSubArray(LL dif[]) {
    int siz = n - 1;
    LL sum = dif[1], res = dif[1];
    for (int i = 2; i <= siz; i++) {
        if (sum < 0) sum = 0;
        sum = sum + dif[i];
        res = max(res, sum);
    }
    return res;
}