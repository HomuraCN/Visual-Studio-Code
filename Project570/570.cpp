#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Color{
	int index;
	char R[10], G[10], B[10];
	int RED = 0, GREEN = 0, BLUE = 0;
}COLOR;

void type1(int up);
void type2(int down, int up);

const int maxn = 1e5 + 10;
int T, n, q;
COLOR color[maxn];
char ans[10], alpher[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++) {
			char temp[20];
			scanf("%d", &color[i].index);
			scanf("%s", temp + 1);
			color[i].R[1] = temp[1], color[i].R[2] = temp[2];
			color[i].G[1] = temp[3], color[i].G[2] = temp[4];
			color[i].B[1] = temp[5], color[i].B[2] = temp[6];
			if (color[i].R[1] >= '0' && color[i].R[1] <= '9') {
				color[i].RED += (color[i].R[1] - '0') * 16;
			}
			else {
				color[i].RED += (color[i].R[1] - 'A' + 10) * 16;
			}
			if (color[i].R[2] >= '0' && color[i].R[2] <= '9') {
				color[i].RED += color[i].R[2] - '0';
			}
			else {
				color[i].RED += color[i].R[2] - 'A' + 10;
			}
			/**/
			if (color[i].G[1] >= '0' && color[i].G[1] <= '9') {
				color[i].GREEN += (color[i].G[1] - '0') * 16;
			}
			else {
				color[i].GREEN += (color[i].G[1] - 'A' + 10) * 16;
			}
			if (color[i].G[2] >= '0' && color[i].G[2] <= '9') {
				color[i].GREEN += color[i].G[2] - '0';
			}
			else {
				color[i].GREEN += color[i].G[2] - 'A' + 10;
			}
			/**/
			if (color[i].B[1] >= '0' && color[i].B[1] <= '9') {
				color[i].BLUE += (color[i].B[1] - '0') * 16;
			}
			else {
				color[i].BLUE += (color[i].B[1] - 'A' + 10) * 16;
			}
			if (color[i].B[2] >= '0' && color[i].B[2] <= '9') {
				color[i].BLUE += color[i].B[2] - '0';
			}
			else {
				color[i].BLUE += color[i].B[2] - 'A' + 10;
			}
		}
		for (int i = 1; i <= q; i++) {
			int down, up;
			scanf("%d %d", &down, &up);
			if (color[up].index == 1) {
				type1(up);
				printf("%s\n", ans + 1);
			}
			else {
				type2(down, up);
				printf("%s\n", ans + 1);
			}
		}
	}

	return 0;
}
void type1(int up) {
	ans[1] = color[up].R[1], ans[2] = color[up].R[2], ans[3] = color[up].G[1], ans[4] = color[up].G[2], ans[5] = color[up].B[1], ans[6] = color[up].B[2];
}
void type2(int bottom, int up) {
	int tempRED = color[up].RED, tempGREEN = color[up].GREEN, tempBLUE = color[up].BLUE;
	while (up > bottom) {
		int down = up - 1;
		tempRED = min(color[down].RED + tempRED, 255);
		tempGREEN = min(color[down].GREEN + tempGREEN, 255);
		tempBLUE = min(color[down].BLUE + tempBLUE, 255);
		up--;
		if (color[down].index == 1) {
			break;
		}
	}
	ans[2] = alpher[min(tempRED, 255) % 16];
	ans[1] = alpher[(min(tempRED, 255) / 16) % 16];
	ans[4] = alpher[min(tempGREEN, 255) % 16];
	ans[3] = alpher[(min(tempGREEN, 255) / 16) % 16];
	ans[6] = alpher[min(tempBLUE, 255) % 16];
	ans[5] = alpher[(min(tempBLUE, 255) / 16) % 16];
}