#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t = 1, x = 343720, y = 233333;
    while (1)
    {
        if ((15 * t) % x == 0 && (17 * t) % y == 0)
            break;
        t++;
    }
    printf("%.2f", 2 * sqrt(15 * 15 * t * t + 17 * 17 * t * t));
    return 0;
}