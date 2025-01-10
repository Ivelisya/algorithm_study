#if 0
给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
 

示例 1：

输入：words = ["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：words = ["cool","lock","cook"]
输出：["c","o"]
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // 初始化一个大小为26的数组minFre，用于记录每个字母在所有单词中出现的最小频率
        vector<int> minFre(26, INT_MAX);
        // 遍历每个单词
        for(const string& word: words){
            // 创建一个频率数组fre，记录当前单词中每个字母的出现次数
            vector<int> fre(26, 0);
            // 遍历当前单词的每个字符，更新fre数组中该字符的频率
            for(const char& ch : word){
                ++fre[ch - 'a'];
            }
            // 对比当前单词的频率数组fre和minFre，更新minFre为每个字母在所有单词中的最小频率
            for(int i = 0; i < 26; ++i ){
                minFre[i] = min(fre[i], minFre[i]);
            }
        }
        // 创建一个result数组，用于存储最终的结果
        vector<string> result;
        // 遍历minFre数组，将每个字母（根据其最小频率）加入到result中
        for(int i = 0; i < 26; ++i){
            // 对于每个字母，添加minFre[i]次该字母到结果中
            for(int j = 0; j < minFre[i]; ++j){
                result.emplace_back(1, i + 'a'); // 将字母转换为字符串，并添加到result
            }
        }
        // 返回最终结果
        return result;
    }
};
#endif
