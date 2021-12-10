#include <stdio.h>
#include <math.h>
#define LL long long

void F(int num);

LL cnt = 0;
int n, flag = 0;

int main() {
	scanf("%d", &n);
	F(n);

	return 0;
}
void F(int num) {
	cnt++;
	if (num == 1) {
		printf("HAPPY\n");
		return;
	}
	if ((num == n && flag == 1)) {
		printf("UNHAPPY\n");
		return;
	}
	flag = 1;
	LL r, sum = 0;
	while (1) {
		r = num % 10;
		sum += pow(r, 2);
		if (num / 10 == 0) {
			break;
		}
		num /= 10;
	}
	F(sum);
}