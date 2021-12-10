#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#define LL long long
using namespace std;

void DFS(int u);

const int maxn = 2e5 + 10;
int t, n;
LL l[maxn], r[maxn], flag[maxn], dp[maxn][2];
vector<int> G[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(flag, 0, sizeof(flag));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &l[i], &r[i]);
        }
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        DFS(1);
        printf("%lld\n", max(dp[1][0], dp[1][1]));
    }

    return 0;
}
void DFS(int u) {
    flag[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (flag[v]) {
            continue;
        }
        DFS(v);
        dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
        dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
    }
}