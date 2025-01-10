#if 0
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例 1：

输入："aabcccccaaa"
输出："a2b1c5a3"
示例 2：

输入："abbccd"
输出："abbccd"
解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在 [0, 50000] 范围内。
class Solution {
public:
    // 双指针法
    string compressString(string S) {
        int i = 0, j = 0;
        string result;
        while (i < S.size()) {
            // 寻找相同字符的连续部分
            while (j < S.size() && S[i] == S[j]) {
                j++;
            }
            // 将字符和其出现次数拼接到结果中
            result.append(1, S[i]);  // 使用append避免创建新字符串
            result.append(to_string(j - i));  // 追加出现次数
            i = j;  // 移动到下一个不同字符的位置
        }
        // 如果压缩后的字符串更短，则返回压缩后的字符串，否则返回原始字符串
        if (result.size() < S.size())
            return result;
        return S;
    }
};
#endif
