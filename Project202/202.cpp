#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct point
{
	int x;
	int y; /*��Ҹ߶�*/
};

bool cmp(struct point a, struct point b);
int Judge(struct point GoldenCoin[], struct point FJ, int N);

int main()
{
	int G, N, ans[5];
	struct point GoldenCoin[55], FJ;

	scanf("%d", &G);
	FJ.x = 0, FJ.y = 0; /*��ʼ��FJ������*/

	for (int i = 0; i < G; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d %d", &GoldenCoin[j].x, &GoldenCoin[j].y);
		sort(GoldenCoin, GoldenCoin + N, cmp); /*�õ�i���ҵ����갴�ո߶���������*/
		ans[i] = Judge(GoldenCoin, FJ, N);
	}

	for (int i = 0; i < G; i++) { /*�����*/
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
				GoldenCoin[j].y -= GoldenCoin[i].y;/*�ȴ�������һ�����ͬʱ����Ľ��Ҳ������,���»�δ�ӵ��Ľ�ҵĸ߶�*/
			FJ.x = GoldenCoin[i].x;/*����FJ��λ��*/
		}
		else {
			FJ.x = 0; /*������ܽ�סȫ����ң���FJ�Ż�(0,0),������һ�νӽ��*/
			return 0;
		}
	}
	if (i == N) {
		FJ.x = 0;/*��ʼFJλ��*/
		return 1;
	}
}