#include <bits/stdc++.h>
using namespace std;
int ans;
void dfs(int depth, int sum)
{
    if (depth == 4)
    {
        if (sum == 384)
            ans++;
        cout << ans;
        ans = 0;
        return;
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
}
int main()
{
    dfs(1, 1);
}