#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, w[35], sum[35];
int res = INT_MAX; // 初始化为 INT_MAX

void dfs(int depth, ll s, int cnt)
{
    if (cnt >= res)
        return;
    if (s > m)
        return;
    if (s == m)
    {
        res = cnt;
        return; // 找到解后需要返回
    }
    if (s + sum[depth] < m)
        return;
    if (depth == n)
    {
        return;
    }
    dfs(depth + 1, s, cnt);
    dfs(depth + 1, s + w[depth] / 2, cnt + 1);
    dfs(depth + 1, s + w[depth], cnt); // 不劈瓜，所以cnt不变
}
int main()
{
    cin >> n >> m, m *= 2;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i], w[i] *= 2;
    }

    // 排序，优先考虑大的瓜
    sort(w, w + n, greater<int>());
    for (int i = n - 1; i >= 0; i--)
    {
        sum[i] = sum[i + 1] + w[i];
    }


    dfs(0, 0, 0);

    if (res == INT_MAX)
    {
        cout << -1 << endl; // 没有找到解
    }
    else
    {
        cout << res << endl;
    }

    return 0;
}
