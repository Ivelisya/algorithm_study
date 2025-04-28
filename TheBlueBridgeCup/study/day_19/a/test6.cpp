#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int dfs(int depth, int sum)
{
    if (depth == 4)
    {
        if (sum == 384)
            ans++;
        }
    else
    {
        for (int i = 1; i <= 9; ++i)
        {
            sum *= i;
            dfs(depth + 1, sum);
            sum /= i;
        }
    }
    return ans;
}
int main()
{
    dfs(0, 1);
    cout << ans;
}