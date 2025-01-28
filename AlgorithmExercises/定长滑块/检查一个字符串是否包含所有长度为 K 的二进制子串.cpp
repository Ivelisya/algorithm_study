#if 0
给你一个二进制字符串 s 和一个整数 k 。如果所有长度为 k 的二进制字符串都是 s 的子串，请返回 true ，否则请返回 false 。
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k)
            return false;
        // 将所有可能的长度为 k 的二进制字符串保存到 unMap 中
        std::unordered_map<std::string, int> unMap;
        int numStrings = 1 << k;
        for (int i = 0; i < numStrings; ++i) {
            std::bitset<32> bs(i);
            std::string binaryStr = bs.to_string().substr(32 - k);
            unMap[binaryStr] = 0; // 初始化计数为 0
        } 

        std::string testStr;
        for (int i = 0; i < s.size(); ++i) {
            // 进：构造滑动窗口字符串
            testStr += s[i];
            if (i < k - 1)
                continue; // 窗口长度不够，跳过

            // 窗口长度达到 k，更新 unMap 中对应子串的计数
            if (unMap.find(testStr) != unMap.end()) {
                unMap[testStr] = 1; // 标记该子串已出现
            }

            // 出：缩小窗口
            testStr = testStr.substr(1);
        }

        // 检查是否所有可能的二进制字符串都出现
        for (const auto& [key, value] : unMap) {
            if (value == 0)
                return false; // 如果有未出现的子串，返回 false
        }
        return true;
    }
};

#endif