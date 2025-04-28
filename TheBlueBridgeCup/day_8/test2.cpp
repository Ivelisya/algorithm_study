#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int help(int num, vector<int> &vec)
{
    int ans = 0;
    if (num < 10)
        ans += 13; // 数字<10时加“零”的13画
    while (num > 0)
    {
        ans += vec[num % 10];
        num /= 10;
    }
    return ans;
}

int main()
{
    vector<int> vec = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2}; // 0-9笔画数
    vector<int> mon = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int basketball_days = 0;

    for (int i = 2000; i <= 2024; ++i)
    {
        if (isLeapYear(i))
            mon[1] = 29;
        else
            mon[1] = 28;
        int max_month = (i == 2024) ? 4 : 12; // 2024年只到4月
        for (int j = 0; j < max_month; ++j)
        {
            int max_day = (i == 2024 && j == 3) ? 13 : mon[j]; // 2024年4月到13日
            for (int k = 0; k < max_day; ++k)
            {
                int stroke_count = help(i, vec) + help(j + 1, vec) + help(k + 1, vec);
                if (stroke_count > 50)
                {
                    basketball_days++;
                }
            }
        }
    }
    cout << basketball_days << endl;
    return 0;
}