#include <bits/stdc++.h>
using namespace std;
long long MOD = pow(10, 9) + 7;
long long dp[100000];
int help(int n, int m, int k)
{
    int result;
    if (k < n)
    {
        result = result + (k - m) + help(n - k, m, k);
    }
    if (dp[result] != -1)
    {
        dp[result] = (result + (n - m)) % MOD;
    }
    return dp[result];
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));

    cout << help(n, m, k);
    return 0;
}