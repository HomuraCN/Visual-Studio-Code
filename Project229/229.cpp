#include <stdio.h>
#include <math.h>

long long Gcd(long long x, long long y);
long long Lcm(long long x, long long y);

long long a, b, c;

int main()
{
	scanf("%d %d %d", &a, &b, &c);

	printf("%lld", Lcm(Lcm(a, b), c));

	return 0;
}
long long Gcd(long long x, long long y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
	{
		return Gcd(y, x % y);
	}
}
long long Lcm(long long x, long long y)/*lcm(a,b)=ab/gcd(a,b)lcm(a,b)=ab/gcd(a,b)*/
{
	return (x * y) / Gcd(x, y);
}