#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 5e6 + 10;
int len, times[30];
char str[maxn];
priority_queue<int, vector<int>, greater<int>> Q;

int main() {
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		times[str[i] - 'a' + 1]++;
	}
	for (int i = 1; i <= 26; i++) {
		if (times[i] == 0) {
			continue;
		}
		Q.push(times[i]);
	}
	int ans = 0;
	while (Q.size() > 1) {
		int temp = 0;
		temp += Q.top();
		Q.pop();
		temp += Q.top();
		Q.pop();
		ans += temp;
		Q.push(temp);
	}
	printf("%d", ans);

	return 0;
}