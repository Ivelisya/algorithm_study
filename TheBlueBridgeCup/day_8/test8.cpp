#include <bits/stdc++.h>
using namespace std;

// 判断是否为闰年
bool isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    int year = 2022; // 可修改为其他年份
    // 定义每个月的天数，month[0] 为一月，month[1] 为二月，依此类推
    vector<int> month = {
        31, isLeap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 假设 2022年1月1日 是星期六，week_day = 6 (1=星期一, 7=星期日)
    int week_day = 6;
    int result = 0;

    // 遍历 12 个月
    for (int i = 0; i < 12; ++i)
    {
        // 遍历该月的所有天
        for (int j = 1; j <= month[i]; ++j)
        {
            // 统计周末 或 特定日期（1日、11日、21日、31日）
            if (week_day == 6 || week_day == 7 || j == 1 || j == 11 || j == 21 || (j == 31 && month[i] == 31))
            {
                result++;
            }
            week_day++; // 星期递增
            if (week_day > 7)
                week_day = 1; // 超过星期日，重置为星期一
        }
    }

    // 输出结果
    cout << "Total days meeting the criteria in " << year << ": " << result << endl;
    return 0;
}