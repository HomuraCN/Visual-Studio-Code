#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<string, ll > mp;
int M, N;
string iu;

void suan() {
    int rear = 0;
    ll ans = 0, lo[5100] = { 0 };
    iu = iu + "#";
    for (int i = 0; i < iu.length(); i++) {
        if (iu[i] == ')') {
            ll sum = 0, num = 0;
            while (lo[rear] != -1) sum += lo[rear--]; rear--;
            while (iu[i + 1] <= '9' && iu[i + 1] >= '0') i++, num = num * 10 + iu[i] - '0';
            if (!num) num = 1;
            lo[++rear] = sum * num;
        }
        else if (iu[i] == '(') {
            lo[++rear] = -1;
        }
        else if (iu[i] <= 'Z' && iu[i] >= 'A') {
            string aaa = "";
            aaa += iu[i];
            if (iu[i + 1] <= 'z' && iu[i + 1] >= 'a') aaa += iu[i + 1], i++;
            ll num = 0;
            while (iu[i + 1] <= '9' && iu[i + 1] >= '0') i++, num = num * 10 + iu[i] - '0';
            if (!num) num = 1;
            lo[++rear] = mp[aaa] * num;
        }
    }
    for (int i = 1; i <= rear; i++) {
        ans += lo[i];
    }
    cout << ans << endl;
}
int main() {
    cin >> M >> N;
    string ins; ll ini;
    for (int i = 0; i < M; i++) {
        cin >> ins >> ini;
        mp[ins] = ini;
    }
    for (int i = 0; i < N; i++) {
        cin >> iu;
        suan();
    }
}