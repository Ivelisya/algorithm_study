#include <iostream>
using namespace std;
int main()
{
    int month[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 一年有12个月，从每个月的第一天开始跑，直到最后日期
    int road_k = 0;                                                // 记录跑过多少
    int week_day = 6;                                              // 记录今天星期几，刚开始为星期六
    for (int year_st = 2000; year_st <= 2020; year_st++)           // 开始判断是否是闰年，并记录每天跑过多少，及更新星期
    {
        if ((year_st % 4 == 0 && year_st % 100 != 0) || (year_st % 400 == 0)) // 闰年即要么整除4并不能整除100，要么整除400
        {
            month[1] = 29; // 闰年二月是29天
        }
        else
        {
            month[1] = 28; // 平年二月是29天
        }

        for (int month_st = 0; month_st <= 11; month_st++) // 开始一年的跑步
        {
            for (int day = 1; day <= month[month_st]; day++) // 判断是否跑完一个月
            {
                road_k++; // 不是星期一就跑一千米
                if (week_day > 7)
                {
                    week_day = 1; // 当一周跑完后，星期重新设置
                }
                if (week_day == 1 || day == 1)
                {
                    road_k++; // 是星期一就跑两千米,是月初也跑两千米
                }
                week_day++;                                       // 更新星期
                if (year_st == 2020 && month_st == 9 && day == 1) // 当到2022.10.1时输出结果
                {
                    cout << road_k;
                }
            }
        }
    }
    return 0;
}