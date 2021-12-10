#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Steaks {
	int index;
	int time;
	int id_pan;
	int l, r;
}STEAKS;
typedef struct Pan {
	int id;
	int totaltime;
}PAN;

struct CMP {
	bool operator()(const PAN& pan1, const PAN& pan2)
	{ 
		return pan1.totaltime > pan2.totaltime;
	}
};
bool cmp(STEAKS x, STEAKS y) {
	return x.time > y.time;
}
bool cmp_ans(STEAKS x, STEAKS y) {
	return x.index < y.index;
}

const int maxn = 1e5 + 10;
int n, m;
int pan_right[maxn];
STEAKS steaks[maxn];
priority_queue<PAN, vector<PAN>, CMP> Q;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		steaks[i].index = i;
		scanf("%d", &steaks[i].time);
	}
	sort(steaks + 1, steaks + 1 + n, cmp);
	for (int i = 1; i <= m; i++) {
		PAN temp;
		temp.id = i, temp.totaltime = 0;
		Q.push(temp);
	}
	for (int i = 1; i <= n; i++) {
		PAN temp = Q.top();
		Q.pop();
		steaks[i].id_pan = temp.id;
		steaks[i].l = temp.totaltime, steaks[i].r = temp.totaltime + steaks[i].time;
		temp.totaltime = steaks[i].r;
		Q.push(temp);
	}
	sort(steaks + 1, steaks + 1 + n, cmp_ans);
	for (int i = 1; i <= n; i++) {
		printf("1 %d %d %d\n", steaks[i].id_pan, steaks[i].l, steaks[i].r);
	}

	return 0;
}