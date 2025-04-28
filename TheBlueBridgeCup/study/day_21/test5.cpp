#include <bits/stdc++.h>
using namespace std;
int a[5][50];
void help(int x)
{
    int ans = 0;
    int bit = 0;
    while (x > 0)
    {
        int temp = x % 10;
        ans += temp;
        x /= 10;
        bit++;
    }
    a[bit][ans]++;
}
int main()
{
    // 100000000 一共八位
    for (int i = 1; i <= 9999; i++)
    {
        help(i);
    }
    int count = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i * 9; ++j)
        {
            for (int k = 1; k <= i; ++k)
            {
                count += a[i][j] * a[k][j];
            }
        }
    }
    cout << count;
}