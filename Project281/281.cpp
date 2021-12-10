#include <stdio.h>
#include <math.h>

struct Point {
	int x, y;
}p[155];

double Min(double x, double y);
double Max(double x, double y);
double Distance(int x1, int y1, int x2, int y2);
void Floyd();

int N, map[155][155];
double ans = 0, temp = 0, newtemp = 1e9, distance[155][155], singlelongest[155] = { 0 };

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) {
				distance[i][j] = Distance(p[i].x, p[i].y, p[j].x, p[j].y);
			}
			else {
				if (i == j) {
					distance[i][j] = 0;
				}
				else {
					distance[i][j] = 1e9;
				}
			}
		}
	}
	Floyd();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (distance[i][j] != 1e9) {
				singlelongest[i] = Max(singlelongest[i], distance[i][j]);
			}
		}
		temp = Max(temp, singlelongest[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (distance[i][j] == 1e9) {
				newtemp = Min(newtemp, Distance(p[i].x, p[i].y, p[j].x, p[j].y) + singlelongest[i] + singlelongest[j]);
			}
		}
	}

	printf("%.6lf", Max(temp, newtemp));

	return 0;
}
double Min(double x, double y) {
	return x <= y ? x : y;
}
double Max(double x, double y) {
	return x >= y ? x : y;
}
double Distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}
void Floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				distance[i][j] = Min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}
}