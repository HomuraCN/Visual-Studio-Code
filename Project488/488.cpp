#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1000010;
int a[maxn], f[maxn];
int n, i, len, l, r, mid, inf = 0x7fffffff;
char str[maxn];

int main() {
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (i = 1; i <= n; i++) {
        a[i] = str[i];
    }
    f[1] = a[1];
    len = 1;
    for (i = 2; i <= n; i++) {
        l = 1, r = len;
        while (l <= r)
        {
             mid = (l + r) / 2;
             if (f[mid] > a[i])
                 r = mid - 1;
             else
                 l = mid + 1;
            }
        f[l] = a[i];
        len = max(len, l);
    }
    printf("%d\n", n - len);

    return 0;
}