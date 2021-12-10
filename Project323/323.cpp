#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

bool cmp(double x, double y) {
	return x > y;
}
double Max(double x, double y) {
	return x >= y ? x : y;
}

int main() {
	int n;
	double per[110], maxx = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &per[i]);
		per[i] *= 0.01;
	}
	sort(per + 1, per + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {/*�ύ��*/
		for (int j = 1; j <= i; j++) {/*ͨ����*/
			double J = j, I = i, PER = 1;
			double temp = pow(J, J / I);
			for (int k = 1; k <= i; k++) {/*ö��ͨ�������ĵĸ���*/
				if (k <= j) {
					PER *= per[k];
				}
				else {
					PER *= (1 - per[k]);
				}
			}
			maxx = Max(temp * PER, maxx);
		}
	}
	printf("%lf", maxx);

	return 0;
}