#include <stdio.h>

int main()
{
	const float PI = 3.14;
	int radius, height;
	float area, volume;

	printf("��ֱ�����Բ����ĵ���뾶�͸�:");
	scanf_s("%d %d", &radius, &height);

	area = PI * radius * radius * 2 + 2 * PI * radius * height;
	volume = PI * radius * radius * height;

	printf("area = %.2f, volume = %.2f", area, volume);

	return 0;
}