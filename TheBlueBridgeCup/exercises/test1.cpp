#include <bits/stdc++.h>
using namespace std;
int vis[20], flag;
vector<char> a(10, 0), b(10, 0);
void dfs(int x, int cnt)
{
    if (flag)
        return;
    if (cnt == 42)
    {
        flag = 1;
        return;
    }
    if (x == 6)
        return;
    for (int i = 1; i <= 6; i++)
    {
        if (vis[b[i]] == 0)
            continue;
        vis[b[i]]--;
        dfs(x + 1, cnt + b[i]);
        dfs(x + 1, cnt - b[i]);
        dfs(x + 1, cnt * b[i]);
        if (b[i] != 0 && cnt % b[i] == 0)
            dfs(x + 1, cnt / b[i]);
        vis[b[i]]++;
    }
    return;
}
int main()
{
    for (int i = 1; i <= 6; i++)
    {
        
        cin >> a[i];
        if (a[i] >= '1' && a[i] <= '9')
        {
            b[i] = a[i] - '0';
            vis[b[i]]++;
        }
        else if (a[i] == 'J')
        {
            b[i] = 10;
            vis[b[i]]++;
        }
        else if (a[i] == 'Q')
        {
            b[i] = 11;
            vis[b[i]]++;
        }
        else if (a[i] == 'K')
        {
            b[i] = 12;
            vis[b[i]]++;
        }
        else
        {
            b[i] = 1;
            vis[b[i]]++;
        }
    }
    dfs(0, 0);
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}