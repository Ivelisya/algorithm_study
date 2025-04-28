#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> H, W;
bool check(int side)
{
    long long sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += 1LL * (H[i] / side) * (W[i] / side);
        if (sum >= K)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    H.resize(N);
    W.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> H[i] >> W[i];
    }
    int l = 1, r = 1e5; // 由题意得 最小分的边 1x1, h w  < 1e5
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return cout << ans << endl, 0;
}