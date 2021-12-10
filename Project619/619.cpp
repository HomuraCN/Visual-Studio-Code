#include <stdio.h>
#include <string.h>

const int maxn = 1e3 + 10;
int n, m, waite_time;
int a[maxn], b[maxn];
bool visited[maxn];

int main() {
	scanf("%d %d", &n, &m);
	memset(visited, false, sizeof(visited));
	waite_time = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		visited[a[i]] = true;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= m; i++) {
		int now_time = b[i] + waite_time;
		if (visited[now_time] == true) {
			waite_time++;
			i = 1;
		}
	}
	printf("%d\n", waite_time);

	return 0;
}