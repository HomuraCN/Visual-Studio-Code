#include <stdio.h>
using namespace std;
typedef long long LL;
LL t, i, n, sum, ans, a[100005], m, cnt = 1;                  //Ҫʹ��longlong����
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
        if (sum % m != 0)                                    //����m������0
        {
            printf("Case #%lld: -1\n", cnt++);
            continue;
        }
        sum /= m;                                            //ʹsum��Ϊ����Ҫ�ֳɵ���ֵ
        for (i = 0; i < n; i++)
        {
            if (a[i] >= sum)                                 //ģ�����һ�����ҷ�һ����ֵΪsum�Ŀ�
            {
                ans += a[i] / sum;
                a[i] %= sum;
                if (a[i] == 0)                               //�����������������һ�Σ�����Ҫ��һ
                {                                            //����a[i]=8,sum=4,��ʵֻ�÷�һ�ξͿ���
                    ans--;
                }
                else
                {
                    ans++;                                  //ģ�����������ʣ�����ֵ�ӵ���һ��
                    a[i + 1] += a[i];
                }
            }
            else
            {
                ans++;                                      //ģ�������������ֵ�ӵ���һ��
                a[i + 1] += a[i];
            }
        }
        printf("Case #%lld: %lld\n", cnt++, ans);
    }
    return 0;
}