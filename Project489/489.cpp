#include <stdio.h>
#include <algorithm>
using namespace std;

int n, indexcnt = 0, cylinderscnt = 0, cubecnt = 0, cylinders[110], cube[110], flag[110];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char str[10];
		scanf("%s", str);
		if (str[1] == 'y') {
			scanf("%d", &cylinders[cylinderscnt++]);
		}
		else {
			scanf("%d", &cube[cubecnt++]);
		}
	}
	sort(cylinders, cylinders + cylinderscnt);
	sort(cube, cube + cubecnt);
	for (int i = 0; i < cubecnt; i++) {
		int cyindex = upper_bound(cylinders, cylinders + cylinderscnt, cube[i] / 2.0) - cylinders;/*第一个2R大于 正方体cube[i]的a 的cylinders*/
		if (cyindex > cylinderscnt - 1) {
			break;
		}
		if (cylinders[cyindex] * 1.414 > cube[i]) {
			flag[indexcnt++] = cyindex;
		}
		else {
			printf("impossible\n");
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < cylinderscnt; i++) {
		while(flag[cnt] == i && cnt < indexcnt) {
			printf("cube %d\n", cube[cnt++]);
		}
		printf("cylinder %d\n", cylinders[i]);
	}
	while (cnt < cubecnt) {
		printf("cube %d\n", cube[cnt++]);
	}

	return 0;
}