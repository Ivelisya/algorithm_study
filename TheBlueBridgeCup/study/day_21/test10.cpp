#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int a[N], b[N];
int n;
long long m;
int f(int x)
{
    long long cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] + b[i] < x)
            return 0;
        if (a[i] >= x)
            continue;
        cnt += x - a[i];
    }
    if (m >= cnt)
        return 1;
    else
        return 0;
    return 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    int l = 1, r = 4 * n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (f(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}