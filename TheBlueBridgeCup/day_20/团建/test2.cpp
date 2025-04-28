#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, res, a[N], b[N];
vector<int> G1[N], G2[N];
void dfs(int g1, int f1, int g2, int f2, int dep)
{
    res = max(res, dep);
    map<int, int> mp; // 使用mp判断节点有没有访问过
    for (auto &v : G1[g1])
    {
        if (v == f1)
            continue;
        mp[a[v]] = v;
    }
    for (auto &v : G2[g2])
    {
        if (v == f2)
            continue;
        if (mp[b[v]])
            dfs(mp[b[v]], g1, v, g2, dep + 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1;i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    // 存入邻接表
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    for (int i = 1; i <= m - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }
    if (a[1] != b[1])
    {
        return cout << 0 << endl,0;
    }
    dfs(1, 0, 1, 0, 1);
    cout << res << '\n';
    return 0;
}