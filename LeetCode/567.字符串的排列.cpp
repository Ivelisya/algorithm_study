/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }
        int len = s1.size();
        vector<int> s1_count(26, 0), s2_count(26, 0);
        for (int i = 0; i < len; i++)
        {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        if (s1_count == s2_count)
        {
            return true;
        }
        for (int i = len; i < s2.size(); ++i)
        {
            // 进
            s2_count[s2[i] - 'a']++;
            // 出
            s2_count[s2[i - len] - 'a']--;
            // 比较
            if (s1_count == s2_count)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=endLeetCode/567.字符串的排列.cpp
