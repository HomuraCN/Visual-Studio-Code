#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

bool cmp(double x, double y);

const int maxn = 110;
int n;
double p[maxn], dp[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		double temp;
		scanf("%lf", &temp);
		p[i] = temp / 100;
	}
	sort(p + 1, p + 1 + n, cmp);
	dp[0][0] = 1;/*��ʼ��*/
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] * (1 - p[i]);/*һ��������������1*/
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];/*���������1.��iƪAC�ˡ�2.��iƪûAC������������ϼӷ�ԭ��*/
		}
		dp[i][i] = dp[i - 1][i - 1] * p[i];/*һ��������������2*/
	}
	double maxx = 0;
	for (int i = 1; i <= n; i++) {
		double ans = 0;
		for (int j = 1; j <= i; j++) {
			ans += pow(j, 1.0 * j / i) * dp[i][j];
		}
		maxx = max(maxx, ans);
	}
	printf("%.10lf", maxx);

	return 0;
}
bool cmp(double x, double y) {
	return x >= y;
}