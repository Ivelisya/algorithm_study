// 二维差分 从单独的元素反过来看前缀
// 对每一个元素计算前缀和的影响叫做差分
// 涉及一种区间的情况 先计算前缀和的影响 再计算前缀和
#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
int sum[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    // 标记差分数组
    for (int i = 1; i <= m; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        sum[x1][y1]++;
        sum[x1][y2 + 1]--;
        sum[x2 + 1][y1]--;
        sum[x2 + 1][y2 + 1]++;
    }
    // 计算前缀和
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] += sum[i][j - 1];
        }
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] += sum[i - 1][j];
        }
    }
    // 输出
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << sum[i][j] % 2;
        }
        cout << endl;
    }
}