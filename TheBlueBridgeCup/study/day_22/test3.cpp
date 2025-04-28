#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[21];
long long D(int x)
{
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3;i <= x;i++){
        dp[i] = (i - 1)*(dp[i - 1] + dp[i - 2]);
    }
    return dp[x];
}
int main()
{
    while (cin >> n)
    {
        cout << D(n) << endl;
    }
    return 0;
}