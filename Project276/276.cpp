#include <stdio.h>
#include <string.h>

int main()
{
	int t, len, cnt, flag = 0;
	char str[55], STR[55];

	scanf("%d", &t);
	for (int j = 1; j <= t; j++) {
		flag = 0;
		scanf("%s", str);
		strcpy(STR, str);
		len = strlen(str);
		if (str[0] == str[len - 1]) {
			printf("NO\n");
			continue;
		}
		else {
			char left = str[0], right = str[len - 1];
			str[0] = '(', str[len - 1] = ')';
			for (int i = 1; i < len - 1; i++) {
				if (str[i] != left && str[i] != right) {
					str[i] = '(';
				}
				else if (str[i] == left) {
					str[i] = '(';
				}
				else if (str[i] == right) {
					str[i] = ')';
				}
			}/*预处理情况一*/
			cnt = 0;
			for (int i = 0; i < len; i++) {
				if (str[i] == '(') {
					cnt++;
				}
				else {
					cnt--;
				}
				if (cnt < 0) {
					break;
				}
				if (cnt == 0 && i == len - 1) {
					printf("YES\n");
					flag = 1;
					break;
				}
			}/*情况一*/
			STR[0] = '(', STR[len - 1] = ')';
			for (int i = 1; i < len - 1; i++) {
				if (STR[i] != left && STR[i] != right) {
					STR[i] = ')';
				}
				else if (STR[i] == left) {
					STR[i] = '(';
				}
				else if (STR[i] == right) {
					STR[i] = ')';
				}
			}/*预处理情况二*/
			cnt = 0;
			for (int i = 0; i < len; i++) {
				if (flag == 1) {
					break;
				}
				if (STR[i] == '(') {
					cnt++;
				}
				else {
					cnt--;
				}
				if (cnt < 0) {
					printf("NO\n");
					flag = 1;
					break;
				}
				if (cnt == 0 && i == len - 1) {
					printf("YES\n");
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				printf("NO\n");
			}
		}
	}

	return 0;
}