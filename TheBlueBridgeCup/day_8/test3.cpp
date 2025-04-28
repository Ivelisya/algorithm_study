#include <bits/stdc++.h>
#define int long long

int days[13] = {0, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[10] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};
int cnt = 0, ans = 0, sum = 0;

signed main()
{
    for (int year = 2000; year <= 2024; year++)
    {
        if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
            days[2] = 29;
        else
            days[2] = 28;
        for (int month = 1; month <= 12; month++)
        {
            for (int day = 1; day <= days[month]; day++)
            {
                cnt = (year * 10000) + (month * 100) + day;
                //                std::cout << cnt << '\n';

                while (cnt)
                {
                    sum += b[cnt % 10];
                    cnt /= 10;
                    if (sum > 50)
                    {
                        //                        std::cout << sum << '\n';
                        ans++;
                        break;
                    }
                }
                sum = 0;
                if (year == 2024 && month >= 4 && day >= 13)
                {
                    std::cout << ans << '\n';
                    return 0;
                }
            }
        }
    }
}