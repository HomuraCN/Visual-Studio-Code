#include <stdio.h>

int main()
{
	int hun, ten, ind, num;

	printf("������һ����λ����:");
	scanf_s("%d", &num);

	hun = (num / 100) % 10;
	ten = (num / 10) % 10;
	ind = (num / 1) % 10;

	if (num == hun * hun * hun + ten * ten * ten + ind * ind * ind)
	{
		printf("����ˮ�ɻ���");
	}
	else
	{
		printf("�ⲻ��ˮ�ɻ���");
	}

	return 0;
}