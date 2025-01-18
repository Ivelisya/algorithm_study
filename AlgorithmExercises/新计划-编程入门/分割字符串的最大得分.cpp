#if 0
给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。

「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
class Solution {
public:
    int maxScore(string s) {
       int right1 = ranges::count(s,'1');
       int left1 = 0,ans = 0;
       for(int i = 0;i + 1 < s.size();++i){
            if(s[i] == '0'){
                left1 ++;
            }else{
                right1--;
            }
            ans = max(ans,left1 + right1);
       }
       return ans;
    }
};
#endif
