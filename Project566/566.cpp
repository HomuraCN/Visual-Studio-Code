#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 10;
int s1s2, s2s3, s1s3, n, cnt = 0, temps1s2, temps2s3, temps1s3;
char str1[maxn], str2[maxn], str3[maxn];

int main() {
	scanf("%d %d %d %d", &temps1s2, &temps2s3, &temps1s3, &n);
	s1s3 = max(max(temps1s2, temps1s3), temps2s3);
	s1s2 = min(min(temps1s2, temps1s3), temps2s3);
	s2s3 = temps1s2 + temps2s3 + temps1s3 - s1s3 - s1s2;
	// 1
	for (int i = 1; i <= s1s2; i++) {
		str1[i] = str2[i] = str3[i] = 'a';
		cnt++;
	}
	// 2
	for (int i = s1s2 + 1; i <= s2s3; i++) {
		str2[i] = str3[i] = 'b';
		cnt++;
	}
	// 3
	for (int i = s2s3 + 1; i <= s1s3 + s2s3 - s1s2; i++) {
		str1[i] = str3[i] = 'c';
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (str1[i] < 'a' || str1[i] >'z') {
			str1[i] = 'd';
		}
		if (str2[i] < 'a' || str2[i] >'z') {
			str2[i] = 'e';
		}
		if (str3[i] < 'a' || str3[i] >'z') {
			str3[i] = 'f';
		}
	}
	int cnt1 = temps1s2 + temps1s3, cnt2 = temps1s2 + temps2s3, cnt3 = temps1s3 + temps2s3;
	if (s1s3 + s2s3 - s1s2 > n) {
		printf("NO\n");
		return 0;
	}
	if (cnt1 <= cnt2 && cnt2 <= cnt3) {
		for (int i = 1; i <= n; i++) {
			printf("%c", str2[i]);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%c", str1[i]);
		}
		printf("\n"); for (int i = 1; i <= n; i++) {
			printf("%c", str3[i]);
		}
		printf("\n");
	}
	if (cnt1 <= cnt3 && cnt3 <= cnt2) {
		for (int i = 1; i <= n; i++) {
			printf("%c", str2[i]);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%c", str3[i]);
		}
		printf("\n"); 
		for (int i = 1; i <= n; i++) {
			printf("%c", str1[i]);
		}
		printf("\n");
	}
	if (cnt2 <= cnt3 && cnt3 <= cnt1) {
		for (int i = 1; i <= n; i++) {
			printf("%c", str3[i]);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%c", str2[i]);
		}
		printf("\n"); for (int i = 1; i <= n; i++) {
			printf("%c", str1[i]);
		}
		printf("\n");
	}
	if (cnt2 <= cnt1 && cnt1 <= cnt3) {
		for (int i = 1; i <= n; i++) {
			printf("%c", str1[i]);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%c", str2[i]);
		}
		printf("\n"); 
		for (int i = 1; i <= n; i++) {
			printf("%c", str3[i]);
		}
		printf("\n");
	}
	if (cnt3 <= cnt1 && cnt1 <= cnt2) {
		for (int i = 1; i <= n; i++) {
			printf("%c", str1[i]);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%c", str3[i]);
		}
		printf("\n"); 
		for (int i = 1; i <= n; i++) {
			printf("%c", str2[i]);
		}
		printf("\n");
	}
	if (cnt3 <= cnt2 && cnt2 <= cnt1) {
		for (int i = 1; i <= n; i++) {
			printf("%c", str3[i]);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%c", str1[i]);
		}
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%c", str2[i]);
		}
		printf("\n");
	}

	return 0;
}