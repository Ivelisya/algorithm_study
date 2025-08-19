#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ret = 0, left = 0, n = 0;
        n = nums.size();
        while (left < n)
        {
            if (nums[left] != 0)
            {
                left += 1;
                continue;
            }
            // 到这里找到了一个非0值
            long long right = left;
            while (right < n && nums[right] == 0)
            {
                right++;
            }
            long long l = right - left;
            ret += l * (l + 1) / 2;
            left = right;
        }
        return ret;
    }
};