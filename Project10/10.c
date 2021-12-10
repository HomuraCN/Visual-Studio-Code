#include <stdio.h>

int main(void)
{
	const float oz_to_g = 28.350;
	float oz, g;

	printf("请输入盎司质量：");
	scanf_s("%f", &oz);

	g = oz * oz_to_g;

	printf("%.2f盎司 = %.2f克", oz, g);

	return 0;
}