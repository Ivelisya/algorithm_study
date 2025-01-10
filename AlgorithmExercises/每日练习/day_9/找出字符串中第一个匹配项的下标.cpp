#if 0
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

 

示例 1：

输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
示例 2：

输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。

class Solution {
public:
    // 函数 strStr 实现了在字符串 haystack 中查找子字符串 needle 的功能
    // 如果找到 needle，返回其在 haystack 中的起始索引；否则返回 -1
    int strStr(string haystack, string needle) {
        // 获取 haystack 和 needle 的长度
        int n = haystack.size(); // haystack 的长度
        int m = needle.size();   // needle 的长度

        // 遍历 haystack，尝试找到与 needle 匹配的子字符串
        for (int i = 0; i + m <= n; ++i) { // i 是 haystack 的当前起始索引，i + m <= n 确保剩余部分长度足够匹配 needle
            bool flag = true; // flag 表示是否匹配成功，初始设为 true

            // 遍历 needle，与 haystack 当前子串逐字符比较
            for (int j = 0; j < m; j++) { // j 是 needle 的当前索引
                if (haystack[i + j] != needle[j]) { // 如果字符不匹配
                    flag = false; // 设置 flag 为 false
                    break;        // 提前退出内层循环
                }
            }

            // 如果 flag 仍然为 true，说明当前子串完全匹配
            if (flag) {
                return i; // 返回匹配的起始索引 i
            }
        }

        // 如果遍历结束仍未找到匹配的子串，返回 -1
        return -1;
    }
};
#endif