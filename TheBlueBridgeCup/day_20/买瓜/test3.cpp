#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, w[35];
int res = 50;
void dfs(int depth, ll s, int cnt)
{
    if (cnt >= res)
        return;
    if (s > m)
        return;
    if (s == m)
    {
        res = cnt;
    }
    if (depth == n)
    {
        return;
    }
    dfs(depth + 1, s, cnt);
    dfs(depth + 1, s + w[depth] / 2, cnt + 1);
    dfs(depth + 1, s + w[depth], cnt + 1);
}
int main()
{
    cin >> n >> m, m *= 2;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i], w[i] *= 2;
    }
    dfs(0, 0, 0);
}