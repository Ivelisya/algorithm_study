#if 0
给你一个字符串 s ，请你返回满足以下条件且出现次数最大的 任意 子串的出现次数：

子串中不同字母的数目必须小于等于 maxLetters 。
子串的长度必须大于等于 minSize 且小于等于 maxSize 。

class Solution {
    public:
        int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
            //出现次数最大的字串 因为aab 中 包含 ab ，ab出现的次数一定等于或 大于aab
            unordered_map<string,int> stringCounts; //存子串的个数
            int maxCount = 0;
            for(int i = 0;i <= (int)s.size() - minSize; ++i){
                string subString = s.substr(i,minSize);
                unordered_set<char> differ;
                for(auto ch : subString){
                    differ.insert(ch);
                }
                if(differ.size() <= maxLetters){
                    stringCounts[subString]++;
                    maxCount = max(maxCount,stringCounts[subString]);
                }
            }
            return maxCount;
    
        }
    };
#endif