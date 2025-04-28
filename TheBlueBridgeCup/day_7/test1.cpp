#include <iostream>
#include <string>
using namespace std;

int main()
{
    int result = 0;
    for (int i = 1; i <= 100000000; ++i)
    {                                 // 减少循环次数提高效率
        string number = to_string(i); // 直接将数字转换为字符串
        if (number.size() % 2 == 0)
        {
            int cmp1 = 0, cmp2 = 0;
            for (int j = 0; j < number.size() / 2; ++j)
            {
                cmp1 += (number[j] - '0');
            }
            for (int j = number.size() / 2; j < number.size(); ++j)
            {
                cmp2 += (number[j] - '0');
            }
            if (cmp1 == cmp2)
            {
                result++;
            }
        }
    }
    cout << result << endl;
    return 0;
}