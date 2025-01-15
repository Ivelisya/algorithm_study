#if 0
给你两个整数，n 和 start 。

数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。

请返回 nums 中所有元素按位异或（XOR）后得到的结果。
class Solution {
    int xor_n(int n) {
        switch (n % 4) {
            case 0: return n;
            case 1: return 1;
            case 2: return n + 1;
            default: return 0;
        }
    }

public:
    int xorOperation(int n, int start) {
        int a = start / 2;
        int b = n & start & 1; // 都为奇数才是 1
        return (xor_n(a + n - 1) ^ xor_n(a - 1)) * 2 + b;
    }
};
#endif