#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>
using namespace std;

const int maxkey = 30, maxn = 55;
int t;
map<char, int> key;

int main() {
	scanf("%d", &t);
	while (t--) {
		char word[maxn];
		getchar();
		for (int i = 1; i <= 26; i++) {
			char temp;
			scanf("%c", &temp);
			key[temp]= i;
		}
		getchar();
		scanf("%s", word + 1);
		/*printf("%d", strlen(word + 1));*/
		int ans = 0;
		int indexpre = key[word[1]], indexnow;
		for (int i = 2; i <= strlen(word + 1); i ++) {
			indexnow = key[word[i]];
			ans += abs(indexnow - indexpre);
			indexpre = indexnow;
		}
		printf("%d\n", ans);
	}

	return 0;
}