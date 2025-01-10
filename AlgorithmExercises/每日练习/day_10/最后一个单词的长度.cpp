#if 0
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大
子字符串

。
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int length = 0;
        while(i >= 0 && s[i] ==' '){
            i --;
        }
        while(i >= 0 && s[i] != ' '){
            length ++;
            i --;
        }
        return length;
    }
};
#endif
