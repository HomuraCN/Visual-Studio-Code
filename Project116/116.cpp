#include <stdio.h>

int main()
{
	int i, N;
	int a[100010];

	scanf("%d", &N);

	for (int j = 0; j < N; j++)
	{
		scanf("%d", &a[j]);
	}

	quickSort(a, 0, N);
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
/*����*/
void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


int partition(int a[], int low, int high)
{
	int pivotkey;
	pivotkey = a[low];//�����ļ�¼ֵ
	while (low < high)//��pivoekeyΪ����ý�飨���ᣩ�����������ķ��ں�ߣ�С�����ķ���ǰ��
	{
		while (low < high && a[high] >= pivotkey)//�����ж� low < high
			high--;
		swap(a, low, high);
		while (low < high && a[low] <= pivotkey)
			low++;
		swap(a, low, high);
	}
	return low;//������������λ��
}

/*�ݹ����*/
void QSort(int a[], int low, int high)
{
	int pivot;
	if (low < high)//�� if 
	{
		pivot = partition(a, low, high);//��a[]һ��Ϊ��

		QSort(a, low, pivot - 1);//�Ե��ӱ�ݹ�����
		QSort(a, pivot + 1, high);//�Ը��ӱ�ݹ�����
	}
}

/*����*/
void quickSort(int a[], int low, int high)
{
	QSort(a, low, high);
}