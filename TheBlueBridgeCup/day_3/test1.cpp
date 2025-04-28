/*
上图给出了一个数字三角形。从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，你的任务就是找到最大的和。

路径上的每一步只能从一个数走到下一层和它最近的左边的那个数或者右 边的那个数。此外，向左下走的次数与向右下走的次数相差不能超过 1。

*/
#include <iostream>
using namespace std;
int n = 0;
int a[105][105] = {0};
int f[105][105] = {0};
int ans = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
    if (n % 2 == 0)
        ans = max(f[n][n / 2], f[n][n / 2 + 1]);
    else
        ans = f[n][n / 2 + 1];
    cout << ans;
    return 0;
}
