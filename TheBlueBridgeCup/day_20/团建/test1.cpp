#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, res, a[N], b[N];
vector<int> G1[N], G2[N];
void dfs(int u1, int far1, int u2, int far2, int dep)
{
    res = max(res, dep);
    map<int, int> mp;
    for (auto v : G1[u1])
    {
        if (v == far1)
            continue;
        mp[a[v]] = v;
    }
    for (auto v : G2[u2])
    {
        if (v == far2)
            continue;
        if (mp[b[v]])
            dfs(mp[b[v]], u1, v, u2, dep + 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    for (int i = 2; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }
    if (a[1] != b[1])
        return cout << 0 << '\n', 0;
    dfs(1, 0, 1, 0, 1);
    cout << res << '\n';
    return 0;
}