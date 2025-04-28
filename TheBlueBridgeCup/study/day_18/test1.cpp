// 士兵训练
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int p;
    int c;
} A[100005];
int main()
{
    int n;
    ll s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i].p >> A[i].c;
    }
    sort(A, A + n, [](node &n1, node &n2)
         { return n1.c < n2.c; }); // 升序排列

    int loc = 0;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += A[i].p;
        if (sum >= s)
        {
            // 单独总价比
            loc = i;
            break;
        }
    }

    ll ans = A[loc].c * s;
    for (int i = loc + 1; i < n; i++)
        ans += (long long)(A[i].c - A[loc].c) * A[i].p;
    cout << ans << '\n';
}