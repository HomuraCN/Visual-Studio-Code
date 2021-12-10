#include <stdio.h>

int Gcd(int x, int y);
int Lcm(int x, int y);

int main()
{
	int up, down, tempup, tempdown, mul, mulleft, mulright;

	scanf("%d/%d", &up, &down);

	while (scanf("%d/%d", &tempup, &tempdown) != EOF)
	{
		mul = Lcm(down, tempdown);
		mulleft = mul / down;
		mulright = mul / tempdown;
		up = up * mulleft + tempup * mulright;
		down = mul;
	}

	mul = Gcd(up, down);
	up /= mul;
	down /= mul;

	if (down < 0)
	{
		down *= -1;
		up *= -1;
		printf("%d/%d", up, down);
	}
	else if (down == 1)
	{
		printf("%d", up);
	}
	else
	{
		printf("%d/%d", up, down);
	}

	return 0;
}
int Gcd(int x, int y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
	{
		Gcd(y, x % y);
	}
}
int Lcm(int x, int y)
{
	return (x * y) / Gcd(x, y);
}