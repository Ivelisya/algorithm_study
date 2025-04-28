#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node
{
    long long p, c;
    bool operator<(const node &x) const
    {
        return c < x.c;
    }
} a[N];
int n;
long long C, sum_p[N], sum_cp[N];
long long getP(int l, int r)
{
    return sum_p[r] - sum_p[l - 1];
}
long long getCP(int l, int r)
{
    return sum_cp[r] - sum_cp[l - 1];
}
int main()
{
    cin >> n >> C;
    for (int i = 1; i <= n; i++)
        cin >> a[i].p >> a[i].c;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        sum_p[i] = sum_p[i - 1] + a[i].p, sum_cp[i] = sum_cp[i - 1] + a[i].p * a[i].c;
    long long ans = 0x3f3f3f3f3f3f3f3fll;
    for (int i = 0; i <= n; i++)
    {
        long long now = C * a[i].c + (getCP(1, n) - getP(i + 1, n) * a[i].c - sum_cp[i]);
        ans = min(ans, now);
    }
    cout << ans << '\n';
    return 0;
}