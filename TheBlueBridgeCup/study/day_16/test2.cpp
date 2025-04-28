#include <iostream>
#include <vector>

// 使用 long long 存储前缀和，防止潜在的整数溢出
using ll = long long;

int main()
{
    // 优化输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m, q;
    std::cin >> n >> m >> q;

    // 定义原始矩阵 A 和二维前缀和矩阵 S
    // S 的大小设为 (n+1) x (m+1)，使用 1-based 索引简化计算
    // 初始化 S 为 0
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    std::vector<std::vector<ll>> s(n + 1, std::vector<ll>(m + 1, 0LL));

    // 读入矩阵 A 的元素，并同时计算二维前缀和 S
    // A[i][j] 表示原始矩阵第 i 行第 j 列的元素
    // S[i][j] 表示以 (1, 1) 为左上角，(i, j) 为右下角的子矩阵的元素和
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> a[i][j];
            // 二维前缀和递推公式:
            // S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j]
            // S[i-1][j]: 上方矩形的和
            // S[i][j-1]: 左方矩形的和
            // S[i-1][j-1]: 左上方被重复计算的矩形的和，需要减去
            // a[i][j]: 当前元素的值
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    // 处理 q 次查询
    for (int k = 0; k < q; ++k)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        // 计算子矩阵 (x1, y1) 到 (x2, y2) 的和
        // 利用容斥原理和二维前缀和矩阵 S:
        // Sum(x1, y1, x2, y2) = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]
        // S[x2][y2]: 右下角大矩形的和
        // S[x1-1][y2]: 需要减去的上方矩形的和
        // S[x2][y1-1]: 需要减去的左方矩形的和
        // S[x1-1][y1-1]: 被重复减去的左上角矩形的和，需要加回来
        ll result = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        std::cout << result << "\n"; // 每个查询结果后换行
    }

    return 0;
}
