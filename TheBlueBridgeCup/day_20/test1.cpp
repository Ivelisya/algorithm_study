#include <bits/stdc++.h>
using namespace std;
int mp[6][6];
long long sum = 0;
bool check()
{
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
    {
        // 先判断棋盘横行
        for (int j = 1; j <= 5; j++)
        {
            if (mp[i][j])
                cnt++;
        }
        if (cnt == 5 || cnt == 0)
            return false;
        cnt = 0;
        // 再判断棋盘竖行
        for (int j = 1; j <= 5; j++)
        {
            if (mp[j][i])
                cnt++;
        }
        if (cnt == 5 || cnt == 0)
            return false;
        cnt = 0;
    }
    // 判断斜行
    for (int i = 1; i <= 5; ++i)
    {
        if (mp[i][i])
            cnt++;
    }
    if (cnt == 5 || cnt == 0)
        return false;
    cnt = 0;
    for (int i = 1; i <= 5; ++i)
        if (mp[i][6 - i])
            cnt++;
    if (cnt == 5 || cnt == 0)
        return false;
    return true;
}
int main()
{
    const int N = 1 << 25;
    for (int i = 0; i < N; i++)
    {
        int pos = 0, cnt = 0;
        // cnt为白棋个数
        for (int j = 1; j <= 5; j++)
        {
            for (int k = 1; k <= 5; k++)
            {
                if ((i >> pos) & 1)
                {
                    cnt++;
                }
                mp[j][k] = (i >> pos) & 1;
                pos++;
            }
        }
        // 13 12 这个时候棋盘被下满
        if (cnt == 13)
        {
            if (check())
            {
                sum++;
            }
        }
    }
    cout << sum;
}