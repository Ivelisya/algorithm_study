// 每个小朋友至少获得 1x1 也就是 至少要有k个小朋友分到巧克力
// 既然是这样 那我们可以转换成 0，1 二分的题目
#include <bits/stdc++.h>
using namespace std;
int k, h, w, res;
int check(int x)
{
    long long sum = 0;
    sum = 1LL * h / x * w / x;
    if (sum >= k)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n >> k;
    int ans = 0;
    while (n--)
    {
        cin >> h >> w;
        int l = 1, r = 1e5;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        res = max(ans, res);
    }
    cout << res << endl;
}
