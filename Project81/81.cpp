#include <stdio.h>

int main()
{
	int i;
	float score[3][5], total[3], aver[3];

	printf("�������1λѧ���Ŀγ̳ɼ�(���ġ���ѧ��Ӣ���ѧ������):");

	for (i = 0; i < 5; i++)
	{
		scanf("%f", &score[0][i]);
	}

	total[0] = score[0][0] + score[0][1] + score[0][2] + score[0][3] + score[0][4];
	aver[0] = total[0] / 5.0;

	printf("�ܷ�:%.2f\tƽ����:%.2f\n", total[0], aver[0]);

	printf("\n");

	printf("�������2λѧ���Ŀγ̳ɼ�(���ġ���ѧ��Ӣ���ѧ������):");

	for (i = 0; i < 5; i++)
	{
		scanf("%f", &score[1][i]);
	}

	total[1] = score[1][0] + score[1][1] + score[1][2] + score[1][3] + score[1][4];
	aver[1] = total[1] / 5.0;

	printf("�ܷ�:%.2f\tƽ����:%.2f\n", total[1], aver[1]);

	printf("\n");

	printf("�������3λѧ���Ŀγ̳ɼ�(���ġ���ѧ��Ӣ���ѧ������):");

	for (i = 0; i < 5; i++)
	{
		scanf("%f", &score[2][i]);
	}

	total[2] = score[2][0] + score[2][1] + score[2][2] + score[2][3] + score[2][4];
	aver[2] = total[2] / 5.0;

	printf("�ܷ�:%.2f\tƽ����:%.2f\n", total[2], aver[2]);
	
	return 0;
}