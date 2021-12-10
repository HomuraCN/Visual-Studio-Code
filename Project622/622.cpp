#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int maxn = 1e4 + 10;
int n, m;
int a[maxn], b[maxn];
int visited[maxn];

int main() {
	while (cin>>n>>m) {
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			visited[a[i]] = 1;
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", &b[i]);
		}
		int wait_time = 0;
		while (true) {
			int flag = 1;
			for (int i = 1; i <= m; i++) {
				if (visited[b[i] + wait_time] == 1) {
					wait_time++;
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}
		printf("%d\n", wait_time);
	}

	return 0;
}