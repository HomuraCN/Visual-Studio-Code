#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	float f;

	printf("�������Ա�����ֵ:");
	scanf_s("%d", &x);

	f = pow((1 + log(x)) , 2);

	printf("%.2f", f);

	return 0;
}