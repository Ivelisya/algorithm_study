/*
句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。

如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现
，那么这个单词就是 不常见的 。

给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按
任意顺序 组织。*/
#if 0
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> wordsCount;
        string word;
        vector<string> result;
        auto helper = [&](const string s1){
            istringstream iss(s1);
            while(iss >> word){
                wordsCount[word] ++;
            }
        };
        helper(s1);
        helper(s2);
        for(auto &[first,second] : wordsCount){
            if(second == 1){
                result.push_back(first);
            }
        };
        return result;
    }
};
#endif
