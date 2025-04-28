#include <iostream>
using namespace std;
int main()
{
    int res = 0, i, x;         // res 记录数中三个一总的个数
    for (i = 1; res < 23; i++) // res=23时循环结束
    {
        int cnt = 0; // 记录二进制数中1的个数
        int x = i;
        while (x)
        {
            if (x & 1) // 逻辑与（低位为1 true 否则 false）例 : x=5 二进制转换 101 & 1 --> 1
                cnt++;
            x >>= 1; // 右移 （低位移走，高位补0）；101 -> 010 (000时 x=0 循环结束)
        }
        if (cnt == 3)
            res++;
    }
    cout << i - 1; // res自增到23时,i++,在下一次循环退出,所以这里输出i-1
    return 0;
}