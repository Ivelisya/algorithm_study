#if 0
给你一个下标从 0 开始的字符串数组 words 和两个整数：left 和 right 。

如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 元音字符串 ，其中元音字母是 'a'、'e'、'i'、'o'、'u' 。

返回 words[i] 是元音字符串的数目，其中 i 在闭区间 [left, right] 内。
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        const string vowel = "aeiou";
        for (int i = left; i < right + 1; ++i) {
            string& s = words[i];
            count += vowel.find(s[0]) != string::npos &&
                      vowel.find(s.back()) != string::npos;
        }
        return count;
    }
};
#endif