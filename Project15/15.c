#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, delta;
	float X1, X2;

	printf("����������һԪ���η��̵�ϵ���ͳ���:");
	scanf_s("%d %d %d", &a, &b, &c);

	delta = b * b - 4 * a * c;

	if (delta >= 0)
	{
		X1 = (-b - sqrt(delta)) / 2 * a;
		X2 = (-b + sqrt(delta)) / 2 * a;
		printf("��һԪ���η��̵�������X1 = %.2f, X2 = %.2f", X1, X2);
	}
	else
	{
		printf("��һԪ���η�����ʵ��");
	}

	return 0;
}