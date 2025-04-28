// 挖矿问题 小兰每次都可以向左走一步或者向右走一步

// a[x]表示x位置上矿洞的数量
//  [l,r] 区间中矿洞的数量 前缀和
//  可以直接采用绝对值
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> r(m + 1, 0);
    vector<int> l(m + 1, 0);
    bool has_zero = false;
    for (int k = 0; k < n; k++)
    {
        int val;
        cin >> val;
        if (val == 0)
        {
            has_zero = 1;
        }
        else if (val > 0)
        {
            if (val <= m)
            {
                r[val]++;
            }
        }
        else
        {
            int abs_val = abs(val);
            if (abs_val <= m)
            {
                l[abs_val]++;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }
    int ans = 0;
    for (int j = 1; j <= m / 2; j++)
    {
        ans = max(ans, r[j] + l[m - 2 * j]);
        ans = max(ans, l[j] + r[m - 2 * j]);
    }
    ans = max(ans, r[m]);
    ans = max(ans, l[m]);
    if (has_zero)
        ans++;
    cout << ans << endl;
}