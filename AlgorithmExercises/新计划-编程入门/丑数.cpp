#if 0
丑数 就是只包含质因数 2、3 和 5 的 正 整数。

给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
class Solution {
public:
    bool isUgly(int n) {
        if(n <=  0)
            return false;

        while(n % 3 ==0){
            n /= 3;
        }

        while(n % 5 ==0){
            n /= 5;
        }
        return (n & (n-1)) == 0;
    }
};
#endif