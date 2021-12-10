#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 10;
int n, k, cnt = 0, a[maxn], b[maxn], pos[maxn];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		b[temp1] = temp2;
		pos[i] = temp1;
	}
	pos[0] = 1; /*pos[0]为特殊边界点，设为第一个元素的位置（1）*/
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	if (b[1] != 0 && b[1] != 1) { /*如果b[1]被赋值了，但b[1] != 1，则不可能，输出-1*/
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		if (pos[i] - pos[i - 1] + cnt < pos[i] - b[pos[i]]) { /* cnt为已经pop的数量    pos[i] - pos[i - 1] + cnt 是当前最多可以pop的总量      pos[i] - b[pos[i]]为 pos[i](包括pos[i])之前总共需要pop的数量*/
			printf("-1");
			return 0;
		}
		else {
			if (cnt > pos[i] - b[pos[i]]) {
				printf("-1");
				return 0;
			}
			int temp;
			temp = a[pos[i - 1]];
			a[pos[i - 1]] = a[pos[i - 1] + pos[i] - b[pos[i]] - cnt];
			a[pos[i - 1] + pos[i] - b[pos[i]] - cnt] = temp;
			cnt = pos[i] - b[pos[i]];
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	
	return 0;
}