#include <stdio.h>
#include <vector>
using namespace std;

int n, num, pre, len[10010];
vector<int> V[10010];

int main()
{
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &num, &len[i]);
		while (scanf("%d", &pre) != 0)
		{
			V[i].push_back(pre);
		}
	}

	

	return 0;
}