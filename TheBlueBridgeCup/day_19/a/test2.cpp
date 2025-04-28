#include <bits/stdc++.h>
using namespace std;
int n, m, ans[30];
// 分支决策法 对于每个分支 都有两个选择
// pos 当前的层数 cnt已经选择的个数
void dfs(int pos, int cnt)
{
    if (cnt > m)
    {
        return;
    }
    if (pos > n)
    {
        if (cnt == m)
        {
            for (int i = 1; i <= m; ++i)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    else
    {
        ans[cnt + 1] = pos;
        dfs(pos + 1, cnt + 1);
        ans[cnt + 1] = 0;
        dfs(pos + 1, cnt);
    }
}
int main()
{
    cin >> n >> m;
    dfs(1, 0);
}