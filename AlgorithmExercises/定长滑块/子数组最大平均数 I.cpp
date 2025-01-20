#if 0
给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。

请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。

任何误差小于 10-5 的答案都将被视为正确答案。
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0,aver = 0,num = 0;
        for(int i = 0;i < nums.size();++i){
            // 进入滑窗
            num += nums[i];
            if(i < k - 1)
                continue;
            //当到达k时离开滑窗 此时已经滑窗内已经有k个

            aver = num/k;
            if(i == k - 1)
                ans = aver;
            else
                ans = max(ans,aver);

            //退出弹窗

            num -= nums[i - k + 1];
        }
        return ans;
    }
};
#endif