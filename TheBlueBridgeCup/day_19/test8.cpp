#include <bits/stdc++.h>
using namespace std;
int n, m, a[30];
void dfs(int c, int cnt) // c是目前的元素位置，cnt是剩下的可选择的元素数量
{
    if (n - c + cnt < m)
        return; // 剪枝，一旦剩下的部分不能够满足排列长度，那那条搜索链就不管了
    if (cnt == m)
    {
        for (int i = 1; i <= m; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = c + 1; i <= n; i++) // 因为是从当前元素的下一个开始遍历，所以不需要vis数组来标记是否重复
    {
        a[cnt + 1] = i;
        dfs(i, cnt + 1);
        a[cnt + 1] = 0; // 恢复现场
    }
}
int main()
{
    cin >> n >> m;
    dfs(0, 0);
    return 0;
}