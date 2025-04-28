#include <bits/stdc++.h>
using namespace std;
int n, m, a[30];
void dfs(int pos, int cnt)
{
    if (cnt > m)
        return;
    if (pos > n)
    {
        if (cnt == m)
        {
            for (int i = 1; i <= m; i++)
                cout << a[i] << ' ';
            cout << '\n';
            // return;
        }
        return;
    }
    a[cnt + 1] = pos;
    dfs(pos + 1, cnt + 1);
    a[cnt + 1] = 0;
    dfs(pos + 1, cnt);
}
int main()
{
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}