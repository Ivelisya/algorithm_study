#if 0
67. 二进制求和
相关标签
相关企业
给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
示例 1：
输入:a = "11", b = "1"
输出："100"
示例 2：
输入：a = "1010", b = "1011"
输出："10101"
提示：
1 <= a.length, b.length <= 104
a 和 b 仅由字符 '0' 或 '1' 组成
字符串如果不是 "0" ，就不含前导零
class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        int maxLen = max(lenA, lenB);
        
        string result = "";
        int carry = 0;
        
        // 从后向前逐位加
        for (int i = 0; i < maxLen; ++i) {
            int bitA = (i < lenA) ? a[lenA - 1 - i] - '0' : 0;
            int bitB = (i < lenB) ? b[lenB - 1 - i] - '0' : 0;
            
            int sum = bitA + bitB + carry;
            result = to_string(sum % 2) + result;  // 当前位的结果
            carry = sum / 2;  // 计算进位
        }
        
        // 如果最后有进位，添加进位
        if (carry) {
            result = "1" + result;
        }
        
        return result;
    }
};
#endif