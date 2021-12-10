#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<string, ll>mp;
stack<ll>st;
int main()
{
	ll n, m, k;
	string s;
	cin >> m >> n;
	for (ll i = 1; i <= m; i++)
	{
		cin >> s >> k;
		mp[s] = k;
	}
	while (n--)
	{
		cin >> s;
		ll n = s.size();
		string t;
		for (ll i = 0; i < n; i++)
		{
			if (s[i] == '(')st.push(-1);
			else if (s[i] == ')')
			{
				ll x = 0;
				while (st.top() != -1)x += st.top(), st.pop();
				st.pop();
				st.push(x);
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				ll x = 0;
				bool fff = 0;
				while (s[i] >= '0' && s[i] <= '9')x = x * 10 + s[i++] - '0', fff = 1;
				ll y = st.top();
				st.pop();
				st.push(y * x);
				i -= fff;
			}
			else
			{
				t = s[i];
				i++;
				while (islower(s[i]) && i < n)t += s[i++];
				i--;
				st.push(mp[t]);
			}
		}
		ll x = 0;
		while (st.size())x += st.top(), st.pop();
		cout << x << '\n';
	}
	return 0;
}