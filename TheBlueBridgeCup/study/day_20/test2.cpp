#include <iostream>
using namespace std;
int mp[6][6];
long long sum = 0;

bool check()
{
    for (int i = 1; i <= 5; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= 5; ++j)
        {
            if (mp[i][j])
            {
                cnt++;
            }
        }
        if (cnt == 5 || cnt == 0)
        {
            return false;
        }
        cnt = 0;
        for (int j = 1; j <= 5; ++j)
        {
            if (mp[j][i])
            {
                cnt++;
            }
        }
        if (cnt == 5 || cnt == 0)
        {
            return false;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 5; ++i)
    {
        if (mp[i][i])
        {
            cnt++;
        }
    }
    if (cnt == 5 || cnt == 0)
    {
        return false;
    }
    cnt = 0;
    for (int i = 1; i <= 5; ++i)
    {
        if (mp[i][6 - i])
        {
            cnt++;
        }
    }
    if (cnt == 5 || cnt == 0)
    {
        return false;
    }
    return true;
}

int main()
{
    const int N = 1 << 25;
    for (int i = 0; i < N; ++i)
    {
        int cnt = 0, pos = 0;
        for (int j = 1; j <= 5; ++j)
        {
            for (int k = 1; k <= 5; ++k)
            {
                mp[j][k] = (i >> pos) & 1;
                pos++;
                if (mp[j][k])
                {
                    cnt++;
                }
            }
        }
        if (cnt == 13)
        {
            if (check())
            {
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}