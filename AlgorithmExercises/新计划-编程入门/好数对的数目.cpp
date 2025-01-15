#if 0
给你一个整数数组 nums 。

如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。

返回好数对的数目
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> cnt;
        for(int x:nums){
            ans += cnt[x] ++;

        }
        return ans;
    }
};
#endif