#include <stdio.h>

int BinarySearch(int elem[], int low, int high, int key);

int main()
{
	int elem[10], result;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &elem[i]);
	}

	result = BinarySearch(elem, 0, 10, 6);

	printf("%d", result);

	return 0;
}

/*�۰���ҷ� �ݹ�ʵ��*/
int BinarySearch(int elem[], int low, int high, int key)
{
	/*����*/
	if (low > high)
	{
		return -1;
	}
	/*�ݹ�ʵ��*/
	int mid = (low + high) / 2;
	if (key == elem[mid])
	{
		return mid;
	}
	if (key < elem[mid])
	{
		BinarySearch(elem, low, mid - 1, key);
	}
	else
	{
		BinarySearch(elem, mid + 1, high, key);
	}
}