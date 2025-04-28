#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0;
    int result = 0;
    for (int i = 0; i < 100; ++i)
    {
        int temp = i;
        sum = 0;
        while (temp)
        {
            if (temp % 2 == 1)
            {
                sum++;
            }
            temp /= 2;
        }
        if (sum == 3)
        {
            result++;
            if (result == 23)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}