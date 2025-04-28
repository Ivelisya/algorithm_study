#include <iostream>
#include <vector>
#include <numeric> // 实际上在这个解法中不需要

// 推荐使用 long long 来存储最终结果，防止溢出
using ll = long long;

int main()
{
    // 使用快速 I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 使用 1-based 索引存储数组 A (大小为 n+1, 索引从 1 到 n)
    std::vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> A[i];
    }

    ll total_sum = 0; // 存储最终的总和

    // 计算前缀异或和 P (大小为 n+1, 索引从 0 到 n)
    // P[0] = 0
    // P[i] = A[1] ^ A[2] ^ ... ^ A[i] for i > 0
    std::vector<int> P(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        P[i] = P[i - 1] ^ A[i];
    }

    // 遍历整数的每一位 (假设是 32 位整数，所以从 0 到 30)
    // 如果 A[i] 可能是负数或 unsigned int，可能需要检查到第 31 位
    // 如果 A[i] 是 long long，需要检查到第 63 位
    for (int bit = 0; bit < 31; ++bit)
    {
        ll count_bit_set = 0; // 记录当前位为 1 的子数组异或和的数量
        ll count0 = 0;        // 记录 P[0]...P[i-1] 中当前位为 0 的数量
        ll count1 = 0;        // 记录 P[0]...P[i-1] 中当前位为 1 的数量

        // 初始化 P[0] 的情况 (P[0]=0, 其所有位都是 0)
        count0 = 1;
        count1 = 0;

        // 遍历前缀异或和 P[1] 到 P[n]
        for (int i = 1; i <= n; ++i)
        {
            // 检查 P[i] 的第 bit 位
            if (((P[i] >> bit) & 1) == 1)
            { // 如果 P[i] 的第 bit 位是 1
                // 我们需要找到 j < i 且 P[j] 的第 bit 位是 0
                // 这样的 j 有 count0 个
                count_bit_set += count0;
                // P[i] 本身使得当前位为 1 的前缀和数量增加
                count1++;
            }
            else
            { // 如果 P[i] 的第 bit 位是 0
                // 我们需要找到 j < i 且 P[j] 的第 bit 位是 1
                // 这样的 j 有 count1 个
                count_bit_set += count1;
                // P[i] 本身使得当前位为 0 的前缀和数量增加
                count0++;
            }
        }

        // 将当前位的贡献加到总和中
        // 贡献 = (当前位为1的子数组数量) * (2^bit)
        // 使用 1LL 确保 2^bit 的计算是以 long long 进行的
        total_sum += count_bit_set * (1LL << bit);
    }

    std::cout << total_sum << std::endl;

    return 0;
}