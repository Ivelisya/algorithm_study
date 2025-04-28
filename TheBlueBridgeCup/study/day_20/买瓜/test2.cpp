#include <iostream>
#include <algorithm>
using namespace std;
int n, ans = 50;
long long m, a[50], sum[50];
void dfs(long long S, int i, int cnt)
{
    if (cnt >= ans)
        return;
    if (S == m)
        ans = cnt;
    if (i > n || S > m || S + sum[i] < m)
        return;
    dfs(S, i + 1, cnt);
    dfs(S + a[i], i + 1, cnt);
    dfs(S + a[i] / 2, i + 1, cnt + 1);
}
int main()
{
    // 请在此输入您的代码
    cin >> n >> m;
    m <<= 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] <<= 1;
    }
    sort(a, a + n, greater<>());
    for (int i = n - 1; i >= 0; --i)
    {
        sum[i] = sum[i + 1] + a[i];
    }
    dfs(0, 0, 0);
    if (ans == 50)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}