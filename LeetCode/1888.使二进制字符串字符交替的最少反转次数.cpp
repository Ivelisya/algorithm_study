/*
 * @lc app=leetcode.cn id=1888 lang=cpp
 *
 * [1888] 使二进制字符串字符交替的最少反转次数
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minFlips(string s)
    {

        int k = s.size(); // 获取原始字符串长度 n
        if (k == 0)       // 处理空字符串的边界情况
            return 0;

        s += s;                // 将字符串自身拼接，长度变为 2n，用于处理循环移位
        int length = s.size(); // 新字符串的总长度 2n

        // 'ans' 用于追踪当前窗口相对于其起始字符 s[l] 的交替模式所需的翻转次数
        int ans = 0;
        // 'mi' 用于存储找到的全局最小翻转次数，初始化为 k (一个安全的最大可能值)
        int mi = k;
        int l = 0; // 滑动窗口的左边界指针

        // r 是滑动窗口的右边界指针，遍历整个拼接后的字符串
        for (int r = 0; r < length; ++r)
        {
            // 累加计算 ans：比较当前字符 s[r] 与窗口起始字符 s[l]
            // (r - l) 是 s[r] 在当前窗口 [l, r] 中的相对索引 (0-based)
            // 如果相对索引是奇数，期望 s[r] != s[l]；如果 s[r] == s[l] 则不匹配，ans++
            // 如果相对索引是偶数，期望 s[r] == s[l]；如果 s[r] != s[l] 则不匹配，ans++
            // 这部分计算逻辑与你之前代码和 PowerCloud 代码一致
            if (((r - l) % 2 != 0 && s[r] == s[l]) || ((r - l) % 2 == 0 && s[r] != s[l]))
            {
                ans++;
            }

            // 如果当前窗口大小 r - l + 1 还不足 k，则跳过后续处理，继续扩大窗口
            if (r - l + 1 < k)
            {
                continue;
            }

            // --- 执行到这里时，窗口大小 r - l + 1 至少为 k ---

            // 如果窗口大小 r - l + 1 超过了 k (即 k + 1)，说明窗口需要向右滑动
            // 这个条件判断和内部逻辑块模仿了 PowerCloud 代码在收缩窗口前的处理
            if (r - l + 1 > k)
            {
                // 比较即将移出窗口的字符 s[l] 和窗口新的起始字符 s[l+1]
                if (s[l] == s[l + 1])
                {
                    // 如果它们相等，应用 PowerCloud 代码中的 (可能存疑的) 更新规则
                    ans = k - ans;
                }
                // 将窗口左边界右移一位
                l++;
            }

            // --- 执行到这里时，窗口大小刚好是 k (r - l + 1 == k) ---
            // 无论是刚达到大小 k，还是在上面 > k 的块中滑动 l 后达到的大小 k

            // 更新全局最小值 mi
            // 注意：这里使用的是 ans，它是在可能应用了 k - ans 规则 *之后* 的值
            mi = min(mi, ans);
        }

        // 返回找到的最小翻转次数
        return mi;
    }
};
// @lc code=end
