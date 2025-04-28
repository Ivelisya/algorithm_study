#include <bits/stdc++.h> // 引入万用标头档，包含了常用的 C++ 标准库
using namespace std;     // 使用标准命名空间，这样就不需要写 std::cin, std::cout 等

using ll = long long; // 定义宏 ll 作为 long long 类型的别名，方便书写，用于处理可能很大的整数

const ll p = 1e9 + 7;  // 定义常量 p 为模数 10^9 + 7。使用 const ll 确保类型正确且不可修改
const int N = 1e5 + 9; // 定义常量 N 作为数组大小。通常比题目数据范围的最大值 (1e5) 稍大一点，以防越界

ll dp[N];     // dp 数组：dp[i] 存储到达第 i 层的方法数 (结果对 p 取模)
ll prefix[N]; // prefix 数组：prefix[i] 存储 dp[0] 到 dp[i] 的累加和 (即前缀和，结果对 p 取模)

int main()
{
    // (可选) 加速 C++ 输入输出流，在处理大量输入输出时可以节省时间
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll n, m, k;         // 定义长整型变量 n, m, k
    cin >> n >> m >> k; // 从标准输入读取塔高 n，最小步长 m，最大步长 k

    // --- 初始化 (这里的初始化方式与标准从 0 开始略有不同) ---
    dp[1] = 1;     // 代码假设到达第 1 层的方法数为 1。这可能隐含了 m=1 或将第1层视为某种起点。
    prefix[1] = 1; // 初始化前缀和数组，prefix[1] 等于 dp[1] (假设 dp[0] 为 0)。

    // --- 动态规划计算 ---
    // 循环从 i = 2 开始，计算到达第 2 层到第 n 层的方法数
    for (ll i = 2; i <= n; i++)
    {
        // 计算能够转移到状态 i 的上一个状态 j 的区间 [i-k, i-m]
        // 我们需要计算 dp[i-k] + ... + dp[i-m]

        // 计算区间和的右端点索引 (对应于 i-m)
        // 如果 i-m < 0，则取 0，因为楼层不能是负数
        int low = max(i - m, 0ll); // 0ll 表示长整型的 0

        // 计算区间和的左端点索引减 1 (对应于 i-k-1)
        // 注意：这里 max(..., 1ll) 确保 up 最小为 1，因此 up-1 最小为 0
        // 这意味着计算 dp[i] 时，最多减去 prefix[0]
        // 这与标准的 i-k-1 可能为负数的情况处理不同，需要特别注意其含义
        int up = max(i - k, 1ll); // 1ll 表示长整型的 1

        // 使用前缀和计算 dp[i]
        // dp[i] = (prefix[low] - prefix[up - 1]) % p
        // prefix[low] 是 dp[0] + ... + dp[low]
        // prefix[up - 1] 是 dp[0] + ... + dp[up - 1]
        // 两者相减得到 dp[up] + ... + dp[low] (根据本代码的 low 和 up 定义)
        dp[i] = (prefix[low] - prefix[up - 1] + p) % p;
        // 加上 p 再取模是为了防止 prefix[low] < prefix[up - 1] 时出现负数
        // C++ 的负数取模结果可能还是负数，(a - b + p) % p 是保证结果非负的标准做法

        // 更新前缀和数组
        // prefix[i] = (dp[0] + ... + dp[i-1]) + dp[i]
        prefix[i] = (prefix[i - 1] + dp[i]) % p; // 在前一个前缀和的基础上加上当前的 dp[i]，并取模
    }

    // 输出结果
    cout << dp[n] << endl; // 输出到达第 n 层的方法数，endl 表示换行

    return 0; // main 函数正常结束
}