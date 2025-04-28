#include <bits/stdc++.h>
using namespace std;
int n, ans[10], vis[10];
void dfs(int cnt)
{
    if (cnt == n)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])
            {
                ans[cnt + 1] = i;
                vis[i] = 1;
                dfs(cnt + 1);
                vis[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
}