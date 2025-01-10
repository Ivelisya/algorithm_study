#if 0
平衡字符串 中，'L' 和 'R' 字符的数量是相同的。

给你一个平衡字符串 s，请你将它分割成尽可能多的子字符串，并满足：

每个子字符串都是平衡字符串。
返回可以通过分割得到的平衡字符串的 最大数量 。

class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0, total = 0;
        for (auto ch : s) {
            balance += (ch == 'L' ? 1 : -1);
            if (balance == 0) {
                total++;
            }
        }
        return total;
    }
};
#endif