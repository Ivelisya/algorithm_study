#if 0
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1,num = 0;
        while(n){
            int i = n % 10;
            n /= 10;
            product *=i ;
            num += i;
        }
        return product - num;
    }
};
#endif