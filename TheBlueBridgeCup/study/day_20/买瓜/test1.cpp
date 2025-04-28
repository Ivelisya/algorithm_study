#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int n, m;
vector<ll> A; // 使用 vector 动态分配内存，避免固定大小的限制
int ans = 0;

void dfs(int cnt, ll current_weight)
{
    if (cnt == n)
    {
        if (current_weight == m)
        {
            ans++;
        }
        return;
    }

    // 两种选择：包含 A[cnt] / 2 或不包含
    dfs(cnt + 1, current_weight + A[cnt] / 2); // 包含
    dfs(cnt + 1, current_weight);              // 不包含
}

int main()
{
    cin >> n >> m;

    A.resize(n); // 动态调整 vector 大小

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    dfs(0, 0);

    cout << ans << endl;

    return 0;
}
