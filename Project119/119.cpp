#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct point
{
	int x;
	int y;
	int z;
}POINT;

bool compare(point A, point B)
{
	return A.z < B.z;
}

int main()
{
	POINT point[50000], temp;
	int N;
	double sum = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &point[i].x, &point[i].y, &point[i].z);
	}

	/*for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (point[j].z > point[j + 1].z)
			{
				temp = point[j];
				point[j] = point[j + 1];
				point[j + 1] = temp;
			}
		}
	}*/

	sort(point, point + N, compare);

	for (int i = 0; i < N - 1; i++)
	{
		sum += sqrt( pow(point[i].x - point[i + 1].x, 2) + pow(point[i].y - point[i + 1].y, 2) + pow(point[i].z - point[i + 1].z, 2) );
	}
	
	printf("%.3lf", sum);

	return 0;
}