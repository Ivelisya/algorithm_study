#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<bool> is_prime(N + 1, true);
int main()
{
    // 创建素数表
    int ans = 0;
    int sum = 0;
    is_prime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            ans = i;
            sum++;
            if (sum == 1e5 + 2)
                return cout << ans << endl, 0;
            if ((long long)i * i > N)
                continue;
            for (int j = i * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    cout << -1;
#if 0
    int i = 1e5 + 2;
    for (int j = 1; j <= N; j++)
    {

        if (is_prime[j])
        {
            ans = j;
            i--;
        }
        if (i == 0)
        {
            cout << ans << endl;
            return 0;
        }
    }
    return cout << -1 << endl, 0;
#endif
}