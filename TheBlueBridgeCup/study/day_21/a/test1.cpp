// g(x) = a/v

#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> A, B;
int check1(int x)
{
    for (int i = 1; i <= N; ++i)
    {
        if (A[i] / x >= B[i])
            continue;
        else
        {
            return 0;
        }
    }
    return 1;
}
int check2(int x)
{
    for (int i = 1; i <= N; ++i)
    {
        if (A[i] / x <= B[i])
            continue;
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> N;
    A.resize(N + 1);
    B.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
    }
    int l = 1, r = 1e9;
    int ansr = 0;
    while (r >= l)
    {
        int mid = (l + r) / 2;
        if (check1(mid))
        {
            ansr = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    l = 1, r = 1e9;
    int ansl = 0;
    while (r >= l)
    {
        int mid = (l + r) / 2;
        if (check2(mid))
        {
            ansl = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d %d", ansl, ansr);
}