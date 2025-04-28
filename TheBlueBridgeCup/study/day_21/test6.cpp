#include <bits/stdc++.h>
using namespace std;
int check(int x)
{
    int count = 0;
    while (x)
    {
        int temp = x % 10;
        count++;
        x /= 10;
    }
    if (count % 2 == 0)
        return count;
    return 0;
}
int same(int bit, int y)
{
    //
    if (bit == 0)
        return 0;
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= bit / 2; i++)
    {
        num1 += y % 10;
        y /= 10;
    }
    for (int i = 1; i <= bit / 2; i++)
    {
        num2 += y % 10;
        y /= 10;
    }
    if (num1 == num2)
        return 1;
    return 0;
}
int main()
{
    int ans = 0;
    for (int i = 1; i <= 100000000; i++)
    {
        if (same(check(i), i))
        {
            ans++;
        };
    }
    cout << ans;
}