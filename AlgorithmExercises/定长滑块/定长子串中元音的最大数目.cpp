#if 0
给你字符串 s 和整数 k 。

请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。

英文中的 元音字母 为（a, e, i, o, u）。

class Solution {
public:
//定长滑窗问题
    int maxVowels(string s, int k) {
        string vowel = "aeiou";
        int vowelI = 0,ans = 0;
        //1.前k个里面的元音数目
        for(int i = 0;i < s.size();++i){
            //1.更新
            if(vowel.find(s[i]) != string::npos)
                vowelI ++;
            //k = 3 
            if(i < k - 1) //2 0 1 2
                continue;//到第三个时 进入下一步
            ans = max(vowelI,ans);
            
            char out = s[i - k + 1];

            if(vowel.find(out) != string::npos)
                vowelI--;
            

        }
        return ans;
    }
};
#endif