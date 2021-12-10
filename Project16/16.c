#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	float f;

	printf("请输入自变量的值:");
	scanf_s("%d", &x);

	f = pow((1 + log(x)) , 2);

	printf("%.2f", f);

	return 0;
}