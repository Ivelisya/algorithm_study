#if 0
给你一个正整数 n ，返回 2 和 n 的最小公倍数（正整数）。
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n <<(n&1);
    }
};
#endif