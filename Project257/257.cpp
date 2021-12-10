#include <stdio.h>
#define PRIME 1000003

typedef struct Node
{
	long long value = 0;
	int count = 0;
}NODE;

long long abs(long long x) 
{
	return x < 0 ? -x : x; 
}

long long Hash(long long key);
void HashInsert(long long key);
long long HashSearch(long long key);

long long N, C, num = 0, A[200010];
NODE hash[PRIME];

int main()
{
	scanf("%lld %lld", &N, &C);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		HashInsert(A[i]);
	}

	for (int i = 1; i <= N; i++) {
		num += hash[HashSearch(A[i] - C)].count;
	}

	printf("%lld", num);

	return 0;
}
long long Hash(long long key)/*¹þÏ£º¯Êý*/
{
	return key % PRIME;
}
void HashInsert(long long key)
{
	int h = HashSearch(key);
	hash[h].count++;
	hash[h].value = key;
}
long long HashSearch(long long key)
{
	int h = Hash(abs(key));
	while (hash[h].value && hash[h].value != key) {
		h = Hash(++h);
	}
	return h;
}