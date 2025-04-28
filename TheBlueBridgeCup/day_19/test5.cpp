#include <bits/stdc++.h>
using namespace std;
int n;
int a[10], vis[10];
void dfs(int cnt)
{
    if (cnt == n) // 到限制了直接输出
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            a[cnt + 1] = i; // 储存以下当前的排列情况再递归
            dfs(cnt + 1);   // 递归下一个可能的数
            a[cnt + 1] = 0;
            vis[i] = 0; // 回溯
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}