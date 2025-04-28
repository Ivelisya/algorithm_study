#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n;
long long a[N];
int cnt[12] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int count(int x)
{
    int res;
    while (x)
    {
        res += cnt[x % 10];
        x /= 10;
    }
    return res;
}

bool comp(long long x, long long y)
{
    if (count(x) != count(y))
        return count(x) < count(y);
    return x < y;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, comp);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}