//#include<pch.h>
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cstring>
#include <cmath>
#define DETERMINATION main
#define lldin(a) scanf_s("%lld", &a)
#define println(a) printf("%lld\n", a)
#define reset(a, b) memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
using namespace std;
const double PI = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int mod = 1000000007;
const int tool_const = 19991126;
const int tool_const2 = 33;
inline ll lldcin()
{
    ll tmp = 0, si = 1;
    char c;
    c = getchar();
    while (c > '9' || c < '0')
    {
        if (c == '-')
            si = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        tmp = tmp * 10 + c - '0';
        c = getchar();
    }
    return si * tmp;
}
///Untersee Boot IXD2(1942)
/**Although there will be many obstructs ahead,
the desire for victory still fills you with determination..**/
/**Last Remote**/
ll factories[65000];
ll schemes[65000];
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int DETERMINATION()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> factories[i];
    ll lcmans = factories[1];
    for (int i = 2; i <= n; i++)
        lcmans = lcm(factories[i], lcmans);//最小公倍数
    ll totality = 0;
    for (int i = 1; i <= n; i++)
    {
        schemes[i] = lcmans / factories[i];
        totality += schemes[i];
    }//求得基本方案的人数和
    if (m % totality != 0)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++)
        {
            if (i != n)
                cout << schemes[i] * m / totality << " ";
            else
                cout << schemes[i] * m / totality << endl;//放大一定倍数
        }
    }
    return 0;
}