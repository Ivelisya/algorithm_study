#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int main()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            for (int k = 1; k < 10; k++)
            {
                for (int l = 1; l < 10; l++)
                {
                    if (i * j * k * l == 384)
                        ans++;
                }
            }
        }
    }
    cout << ans << endl;
}