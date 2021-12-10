#include <stdio.h>
#include <math.h>

struct Point {
	double x, y, z;
}point[5010];

int N;
double ans;
const double eps = 1e-4;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lf %lf %lf", &point[i].x, &point[i].y, &point[i].z);
	}

	for (int i = 1; i <= 3; i++) {/*正方体三个面xy上下, xz左右, yz前后*/
		double left = 1e-9, right = 2830;
		while (abs(left - right) >= eps ) {
			double mid = (left + right) / 2;
			for (int j = 1; j <= N; j++) {
				if (mid < Distance(point[])) {
					left = mid;
				}
				else {
					right = mid;
				}
			}
		}
	}

	return 0;
}
double Min(double x, double y) {
	return x <= y ? x : y;
}
double Distance(double x1, double y1, double x2, double y2) {
	return sqrt( pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2) );
}