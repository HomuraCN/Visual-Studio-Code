#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Node
{
	long long root;
	int left;
	int right;
	long long distinction;
	int visited;
	int order;
}NODE;

void BFS(NODE x);
long long Min(long long x, long long y);

int n;
long long sum = 0, ans = 4000000000;
NODE node[110], NOW;

int main()
{
	int w, u, v;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &w, &u, &v);
		node[i].root = w, node[i].left = u, node[i].right = v;
		node[i].visited = 0, node[i].order = i;
	}

	for (int i = 1; i <= n; i++)
	{
		BFS(node[i]);
		for (int j = 1; j <= n; j++)
		{
			sum += node[j].root * node[j].distinction;
		}
		ans = Min(sum, ans);
		sum = 0;
		for (int h = 1; h <= n; h++)
		{
			node[h].visited = 0, node[h].distinction = 0;
		}
	}

	printf("%d", ans);

	return 0;
}
void BFS(NODE x)
{
	int k;
	queue<NODE> Q;
	x.visited = 1;
	x.distinction = 0;
	Q.push(x);
	while (!Q.empty())
	{
		NOW = Q.front();
		Q.pop();
		if (node[NOW.left].visited == 0 && NOW.left != 0)
		{
			node[NOW.left].visited = 1; /*Í¿»Ò*/
			node[NOW.left].distinction = NOW.distinction + 1;
			Q.push(node[NOW.left]);
		}
		if (node[NOW.right].visited == 0 && NOW.right != 0)
		{
			node[NOW.right].visited = 1; /*Í¿»Ò*/
			node[NOW.right].distinction = NOW.distinction + 1;
			Q.push(node[NOW.right]);
		}
		for (k = 1; k <= n; k++)
		{
			if (node[k].left == NOW.order || node[k].right == NOW.order)
			{
				break;
			}
		}
		if (k != n + 1 && node[k].visited == 0)
		{
			node[k].visited = 1;
			node[k].distinction = NOW.distinction + 1;
			Q.push(node[k]);
		}
		node[NOW.order].visited = 1;
	}
}
long long Min(long long x, long long y)
{
	return x <= y ? x : y;
}