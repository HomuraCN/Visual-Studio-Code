#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

double Min(double x, double y);

int main() {
	int a = 0, b = 0, c = 0, left = 0, right = 0;
	string str = "";
	getline(cin, str);
	str += '#';
	for (int i = 2; i < str.length(); i++) {
		if (str[i] == '+') {
			continue;
		}
		int num = 0;
		while (str[i] >= '0' && str[i] <= '9') {
			num = num * 10 + (str[i++] - '0');
			if (str[i] == '*' && str[i + 1] == 'x' && str[i + 2] == '^') {
				i += 4;
				a = num;
				break;
			}
			else if (str[i] == '*' && str[i + 1] == 'x' && str[i + 2] == '+') {
				i += 2;
				b = num;
				break;
			}
			else if (str[i] == ' ') {
				c = num;
				i += 2;
				num = 0;
				while (str[i] >= '0' && str[i] <= '9') {
					num = num * 10 + (str[i++] - '0');
					if (str[i] == ',') {
						left = num;
						num = 0;
						i++;
					}
					if (str[i] == ')') {
						right = num;
						break;
					}
				}
				break;
			}
		}
	}
	printf("%d %d %d %d %d\n", a, b, c, left, right);
	double mid = -(1.0 * b / (2.0 * a));
	printf("%lf\n", mid);
	if (mid <= left || mid >= right) {
		printf("%lf", Min(a * left * left + b * left + c, a * right * right + b * right + c));
	}
	else {
		printf("%lf", Min(Min(a * left * left + b * left + c, a * right * right + b * right + c), a * mid * mid + b * mid + c));
	}

	return 0;
}
double Min(double x, double y) {
	return x < y ? x : y;
}