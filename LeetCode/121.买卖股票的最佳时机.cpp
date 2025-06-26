/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxCount = 0;
        int minCount = INT_MAX;
        for (int price : prices)
        {
            minCount = min(price, minCount);
            maxCount = max(maxCount, price - minCount);
        }
        return maxCount;
    }
};
// @lc code=end
