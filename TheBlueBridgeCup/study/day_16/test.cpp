#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;

        cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
    }

    return 0;
}
