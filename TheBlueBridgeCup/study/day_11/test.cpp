#include <bits/stdc++.h>
using namespace std;
long long help(int x)
{
    long long result;
    if (x > 10)
    {
        result = 2LL * x * help(x - 6) % 998244353;
    }
    else if (x <= 10)
    {
        result = 1LL * x * (x - 1) % 998244353;
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    cout << help(n) % 998244353;
    return 0;
}