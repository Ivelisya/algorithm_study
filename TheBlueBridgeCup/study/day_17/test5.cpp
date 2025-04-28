#include <iostream>
#include <vector>
#include <cmath>     // 引入cmath库，用于std::abs函数（绝对值）
#include <numeric>   // 可能有用，但这里手动计算前缀和
#include <algorithm> // 引入algorithm库，用于std::max函数（取最大值）

int main()
{
    // 可选项：提高I/O性能
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n; // 输入数组中元素的数量
    int m; // 最大距离/范围参数
    std::cin >> n >> m;

    // 使用vector代替Python列表。初始化大小为m+1，所有元素为0。
    // r存储正索引的计数（右侧）
    // l存储负索引的绝对值的计数（左侧）
    std::vector<int> r(m + 1, 0);
    std::vector<int> l(m + 1, 0);
    bool has_zero = false; // 标记输入中是否存在0

    // 读取n个输入值并填充计数向量
    for (int k = 0; k < n; ++k)
    {
        int val;
        std::cin >> val;
        if (val == 0)
        {
            has_zero = true; // 标记已找到0
        }
        else if (val > 0)
        {
            // 检查正值是否在范围[1, m]内
            if (val <= m)
            {
                r[val]++; // 增加此正位置的计数
            }
        }
        else
        { // val < 0
            int abs_val = std::abs(val);
            // 检查绝对值是否在范围[1, m]内
            if (abs_val <= m)
            {
                l[abs_val]++; // 增加此左侧绝对位置的计数
            }
        }
    }

    // 构建r和l向量的前缀和
    // r[i]将存储<= i的正值的总计数
    // l[i]将存储绝对值<= i的负值的总计数
    for (int i = 1; i <= m; ++i)
    {
        r[i] += r[i - 1];
        l[i] += l[i - 1];
    }

    int ans = 0; // 初始化到目前为止找到的最大计数

    // 枚举在一个方向上最初采取的步数'j'（1到m/2）
    // 计算在'm'总步数内往返收集的最大物品数
    for (int j = 1; j <= m / 2; ++j)
    {
        // 情况1：向右走'j'步，然后向左走'm - 2*j'步（总步数j + j + (m-2j) = m）
        // 收集向右走的r[j]个物品，以及从原点向左走的l[m - 2 * j]个物品
        // 注意：索引m - 2*j是有效的，因为j <= m/2确保m - 2*j >= 0
        ans = std::max(ans, r[j] + l[m - 2 * j]);

        // 情况2：向左走'j'步，然后向右走'm - 2*j'步（总步数j + j + (m-2j) = m）
        // 收集向左走的l[j]个物品，以及从原点向右走的r[m - 2 * j]个物品
        ans = std::max(ans, l[j] + r[m - 2 * j]);
    }

    // 考虑仅在一个方向上移动完整'm'步的情况
    // 情况3：仅向右移动'm'步（收集直到距离m的所有物品）
    ans = std::max(ans, r[m]);
    // 情况4：仅向左移动'm'步（收集直到距离m的所有物品）
    ans = std::max(ans, l[m]);

    // 如果原点（位置0）包含一个物品，则将1添加到答案中
    if (has_zero)
    {
        ans++;
    }

    // 打印最终最大计数
    std::cout << ans << std::endl;

    return 0; // 指示成功执行
}
