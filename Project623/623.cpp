#include <stdio.h>
#include <vector>
using namespace std;

const int maxc = 1e2 + 10;
int n, c, siz = 0;
vector<int> G[maxc];

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		G[temp].push_back(i);
	}
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= c; j++) {
			int temp = 0;
			if (i == j) {
				continue;
			}//元素不一样
			else {
				int time_order = 0, p1 = 0, p2 = 0;
				while (true) {
					while (p1 < G[i].size() && G[i][p1] < time_order) {
						p1++;
					}
					if (p1 != G[i].size()) {
						time_order = G[i][p1];
						temp++;
					}
					else {
						break;
					}
					while (p2 < G[j].size() && G[j][p2] < time_order) {
						p2++;
					}
					if (p2 != G[j].size()) {
						time_order = G[j][p2];
						temp++;
					}
					else {
						break;
					}
				}
				siz = max(siz, temp);
			}
		}
	}
	printf("%d\n", siz);

	return 0;
}