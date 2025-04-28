#include <iostream>
using namespace std;

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int h[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
    }
    // 我们需要用二分法查找从小到大“所有”可能的边长，有任何疑惑可以再审题
    // 举个例子：如果有一块巨大的巧克力就能满足条件，就不需要切分其它的巧克力了
    // 首先找到最大的边长
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        r = max(r, max(h[i], w[i]));
    }
    // 开始搜索
    int l = 1, ans = 0;
    while (l <= r)
    {                          // 注意等于的情况，l<=r是搜索区间的意思，如果更新后的l大于了r，说明找到了
        int mid = (l + r) / 2; // 中间值
        int sum = 0;           // 该中间值能够切出的总巧克力数量
        for (int i = 0; i < n; i++)
        {
            if (mid <= min(h[i], w[i]))
            {                                       // 确保该巧克力能够被切分
                sum += (h[i] / mid) * (w[i] / mid); // 更新巧克力数
                // 算法：找到巧克力长和宽最多能容纳几个中间值（即整除），然后再乘起来，画图理解更好
            }
        }

        if (sum >= k)
        {                // 如果该中间值可以切出足够多的巧克力
            ans = mid;   // 更新答案
            l = mid + 1; // 尝试寻找更大的边长
        }
        else
        {                // 如果该中间值切不出足够多的巧克力
            r = mid - 1; // 尝试寻找更小的边长
        }
    }

    cout << ans << endl;

    return 0;
}