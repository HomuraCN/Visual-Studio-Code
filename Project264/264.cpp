#include <stdio.h>
using namespace std;
typedef long long LL;
LL t, i, n, sum, ans, a[100005], m, cnt = 1;                  //要使用longlong类型
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        sum = 0;
        ans = 0;
        scanf("%lld%lld", &n, &m);
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        if (sum % m != 0)                                    //除于m不等于0
        {
            printf("Case #%lld: -1\n", cnt++);
            continue;
        }
        sum /= m;                                            //使sum成为最终要分成的数值
        for (i = 0; i < n; i++)
        {
            if (a[i] >= sum)                                 //模拟操作一，向右分一个数值为sum的块
            {
                ans += a[i] / sum;
                a[i] %= sum;
                if (a[i] == 0)                               //这种情况，上面多分了一次，所以要减一
                {                                            //例如a[i]=8,sum=4,其实只用分一次就可以
                    ans--;
                }
                else
                {
                    ans++;                                  //模拟操作二，将剩余的数值加到下一块
                    a[i + 1] += a[i];
                }
            }
            else
            {
                ans++;                                      //模拟操作二，将数值加到下一块
                a[i + 1] += a[i];
            }
        }
        printf("Case #%lld: %lld\n", cnt++, ans);
    }
    return 0;
}