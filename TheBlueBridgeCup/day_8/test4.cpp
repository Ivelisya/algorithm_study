#include <iostream>
#include <map>
using namespace std;

// 判断是否为闰年
bool isLeap(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// 检查日期是否合法
bool check(int year, int month, int day)
{
    int days[] = {0, 31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return 1 <= month && month <= 12 && 1 <= day && day <= days[month];
}

int main()
{
    map<int, int> mp;
    mp[0] = 13;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 3;
    mp[4] = 5;
    mp[5] = 4;
    mp[6] = 4;
    mp[7] = 2;
    mp[8] = 2;
    mp[9] = 2;

    int sum1 = 0;
    int sum2 = 0;
    for (int k = 20000101; k <= 20240413; k++)
    {
        int a = k % 10;          // 1
        int b = k / 10 % 10;     // 2
        int c = k / 100 % 10;    // 3
        int d = k / 1000 % 10;   // 4
        int e = k / 10000 % 10;  // 5
        int f = k / 100000 % 10; // 6

        int year = k / 10000;
        int month = k % 10000 / 100;
        int day = k % 100;

        if (check(year, month, day))
        {
            int sum = mp[a] + mp[b] + mp[c] + mp[d] + mp[e] + mp[f];
            if (sum <= 35)
            {
                sum2++;
            }
            else
            {
                sum1++;
            }
        }
    }
    cout << sum1 << endl;
    return 0;
}