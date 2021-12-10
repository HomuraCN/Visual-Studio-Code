#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Employee {
	int times;
	int id;
}EMPLOYEE;

const int maxn = 2e5 + 10;
int t, n, cnt;
EMPLOYEE employee[maxn], temp, max1, max2;
priority_queue<EMPLOYEE> PQ;

int main() {
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &temp.times);
			temp.id = i;
			PQ.push(temp);
		}
		while (PQ.size() > 1) {
			max1 = PQ.top();
			PQ.pop();
			max2 = PQ.top();
			PQ.pop();
			if (max1.times > max2.times) {
				cnt += max2.times;
				max1.times -= max2.times;
				PQ.push(max1);
			}
			else if (max1.times < max2.times) {
				cnt += max1.times;
				max2.times -= max1.times;
				PQ.push(max2);
			}
			else {
				cnt += max1.times;
			}
		}
		printf("%d\n", cnt);
		while (!PQ.empty()) {
			PQ.pop();
		}
	}

	return 0;
}