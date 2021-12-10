#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct point
{
	int x;
	int y; /*金币高度*/
};

bool cmp(struct point a, struct point b);
int Judge(struct point GoldenCoin[], struct point FJ, int N);

int main()
{
	int G, N, ans[5];
	struct point GoldenCoin[55], FJ;

	scanf("%d", &G);
	FJ.x = 0, FJ.y = 0; /*初始化FJ的坐标*/

	for (int i = 0; i < G; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d %d", &GoldenCoin[j].x, &GoldenCoin[j].y);
		sort(GoldenCoin, GoldenCoin + N, cmp); /*让第i组金币的坐标按照高度升序排序*/
		ans[i] = Judge(GoldenCoin, FJ, N);
	}

	for (int i = 0; i < G; i++) { /*答案输出*/
		if (ans[i] == 0)
			printf("Notabletocatch\n");
		else
			printf("Abletocatch\n");
	}

	return 0;
}
bool cmp(struct point a, struct point b)
{
	return a.y < b.y;
}
int Judge(struct point GoldenCoin[], struct point FJ, int N)
{
	int i;
	for (i = 0; i < N; i++) {
		if (abs(FJ.x - GoldenCoin[i].x) <= GoldenCoin[i].y) {
			for (int j = i + 1; j < N; j++)
				GoldenCoin[j].y -= GoldenCoin[i].y;/*等待接其中一个金币同时，别的金币也在下落,更新还未接到的金币的高度*/
			FJ.x = GoldenCoin[i].x;/*更新FJ的位置*/
		}
		else {
			FJ.x = 0; /*如果不能接住全部金币，则将FJ放回(0,0),进行下一次接金币*/
			return 0;
		}
	}
	if (i == N) {
		FJ.x = 0;/*初始FJ位置*/
		return 1;
	}
}