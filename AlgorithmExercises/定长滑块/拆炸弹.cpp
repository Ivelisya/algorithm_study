#if 0
你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。

为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。

如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
如果 k == 0 ，将第 i 个数字用 0 替换。
由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。

给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！

class Solution {
    public:
        vector<int> decrypt(vector<int>& code, int k) {
            int n = code.size();
            vector<int> res(n, 0); // 初始化结果数组，所有元素设为0
    
            if (k == 0) {
                return res; // 如果 k 为 0，直接返回全为 0 的结果数组
            } else if (k > 0) { // k 为正数，向前累加
                for (int i = 0; i < n; ++i) {
                    for (int j = 1; j <= k; ++j) {
                        res[i] += code[(i + j) % n]; // 使用模运算 (%) 实现循环索引
                    }
                }
            } else { // k < 0，k 为负数，向后累加
                for (int i = 0; i < n; ++i) {
                    for (int j = 1; j <= -k; ++j) {
                        res[i] += code[(i - j + n) % n]; // 关键：处理负数索引，加 n 再取模
                    }
                }
            }
            return res;
        }
    };
#endif
