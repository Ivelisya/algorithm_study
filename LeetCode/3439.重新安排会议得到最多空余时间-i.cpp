/*
 * @lc app=leetcode.cn id=3439 lang=cpp
 *
 * [3439] 重新安排会议得到最多空余时间 I
 */
// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        auto get = [&](int i) -> int
        {
            if (i == 0)
                return startTime[0];
            if (i == n)
                return eventTime - endTime[n - 1];
            return startTime[i] - endTime[i - 1];
        };
        int ans = 0, s = 0;
        // base 0
        for (int i = 0; i <= n; i++)
        {
            s += get(i);
            if (i < k)
                continue;
            // i == k
            ans = max(ans, s);
            // 出
            s -= get(i - k);
        }
        return ans;
    }
};
// @lc code=end
