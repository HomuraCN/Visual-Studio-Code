#include <stdio.h>

const int maxn = 1e6 + 10;
int n, k, b[maxn], cnt[maxn];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int pos, temp;
        scanf("%d %d", &pos, &temp);
        b[--pos] = temp;
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        num++;
        if (b[i] > 0) {
            if (b[i] > num) {
                printf("-1\n");
                return 0;
            }
            num = b[i];
        }
        else {
            b[i] = num;
        }
    }
    for (int i = 0; i < n; i++) {
        cnt[b[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", cnt[b[i]]--);
    }

    return 0;
}