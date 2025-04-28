#include <bits/stdc++.h>
using namespace std;
int row[24], col[24], id[24][24], R, C, vis[24][24];
int ans[430], step;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int n;
void dfs(int x, int y)
{
    if (R == 0 && C == 0 && x == n && y == n)
    {
        for (int i = 1; i <= step; ++i)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
        exit(0);
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (col[yy] > 0 && row[xx] > 0 && xx >= 0 && xx <= n && yy >= 0 && yy <= n && !vis[xx][yy])
            {
                ans[++step] = id[xx][yy];
                col[yy]--;
                row[xx]--;
                C--;
                R--;
                vis[xx][yy] = 1;
                dfs(xx, yy);
                ans[step + 1] = 0;
                step--;
                C++;
                R++;
                col[yy]++;
                row[xx]++;
                vis[xx][yy] = 0;
            }
        }
    }
}
int main()
{

    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            id[i][j] = cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
        C += col[i];
        // 统计列上箭的个数
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> row[i];
        R += row[i];
    }
    // 统计行上箭的个数
    // 初始化 骑士第一步一定是 (1,1)
    ans[step++] = id[1][1];
    C--;
    R--;
    col[1]--;
    row[1]--;
    vis[1][1] = 1;
    dfs(1, 1);
}