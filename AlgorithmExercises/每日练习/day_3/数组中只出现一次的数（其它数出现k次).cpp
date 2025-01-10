/*
给定一个长度为 n 的整型数组 arr 和一个整数 k(k > 1)。
已知 arr 中只有 1 个数出现一次，其他的数都出现 k 次。
请返回只出现了 1 次的数。

数据范围:
1 ≤ n ≤ 2 * 10^5
1 < k < 100
-2 * 10^9 ≤ arr[i] ≤ 2 * 10^9

进阶：时间复杂度 O(32n)，空间复杂度 O(1)
*/
#if 0
 int foundOnceNumber(vector<int>& arr, int k) {
        // write code here
        unordered_map<int, int> frequency;
        for(auto num : arr){
            frequency[num]++;
        }
        for(const auto &[first,second]:frequency){
            if(second == 1)
                return first;
        }
        return 0;
    }
};
#endif