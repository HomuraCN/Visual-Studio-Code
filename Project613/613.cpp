
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define PI acos(-1.0)
#define E 1e-6
#define MOD 1000003
#define INF 0x3f3f3f3f
#define N 1001
#define LL long long
using namespace std;
struct Node {//点
    int x, y;
    double p;
}node[N];

struct Edge {//边
    int x, y;
    double dis;
    Edge() {}
    Edge(int x, int y, double dis) :x(x), y(y), dis(dis) {}
    bool operator < (const Edge& rhs)const {
        return dis > rhs.dis;
    }
}tree[N];//存储最小生成树
int n;
vector<int> G[N];
bool vis[N];
int father[N];
priority_queue<Edge> edge;//存储边
double calculate(Node a, Node b) {//计算两点距离
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (double)(a.y - b.y) * (a.y - b.y));
}
int Find(int x) {
    if (father[x] == x)
        return x;
    return Find(father[x]);
}
double Kruskal() {
    for (int i = 0; i <= n; i++) {
        father[i] = i;
        G[i].clear();
    }

    int cnt = 0;
    double MST = 0;//最小生成树权值
    while (!edge.empty()) {
        Edge x = edge.top();
        edge.pop();

        int u = Find(x.x);
        int v = Find(x.y);
        if (u != v) {
            father[u] = v;
            MST += x.dis;

            G[x.x].push_back(x.y);
            G[x.y].push_back(x.x);
            tree[cnt++] = x;
        }

        if (cnt == n - 1)
            break;
    }
    return MST;
}
double dfs(int x, double sum) {//寻找人口数量
    vis[x] = true;

    sum = max(sum, node[x].p);
    for (int y = 0; y < G[x].size(); y++)
        if (!vis[G[x][y]])
            sum = dfs(G[x][y], sum);

    return sum;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(node, 0, sizeof(node));
        memset(tree, 0, sizeof(tree));


        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d%lf", &node[i].x, &node[i].y, &node[i].p);

        while (!edge.empty())
            edge.pop();

        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                edge.push(Edge(j, i, calculate(node[i], node[j])));

        double dis = Kruskal();
        double maxx = -INF;
        for (int i = 0; i < n - 1; i++) {//枚举所有边
            memset(vis, false, sizeof(vis));
            double people = 0;
            int x = tree[i].x;
            int y = tree[i].y;

            vis[y] = true;//将x-y两个城市分隔

            people += dfs(x, 0);//计算x一侧人口最大的城市
            people += dfs(y, 0);//计算y一侧人口最大的城市

            maxx = max(maxx, people / (dis - tree[i].dis));

        }
        printf("%0.2lf\n", maxx);
    }
    return 0;
}