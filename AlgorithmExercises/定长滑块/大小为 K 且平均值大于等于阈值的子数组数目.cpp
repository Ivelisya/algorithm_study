#if 0
给你一个整数数组 arr 和两个整数 k 和 threshold 。

请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int num = 0, aver = 0, ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            // 进入
            num += arr[i];
            if (i < k - 1) {
                continue;
            }
            aver = num / k;

            if(aver >= threshold)
                ans++;
            // 出去
            num -= arr[i - k + 1];
        }
        return ans;
    }
};
#endif