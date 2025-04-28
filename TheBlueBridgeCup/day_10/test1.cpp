#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long mod = 998244353;
    long long ans = 0;
    ans = (n - 1) * n / 2 % mod;
    for (long long i = 3; i <= n; i += 1)
    {
        ans = ans * i % mod;
    }
    cout << ans;
    return 0;
}