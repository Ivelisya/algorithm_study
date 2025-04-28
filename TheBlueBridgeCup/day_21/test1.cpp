#include <bits/stdc++.h>
double a;
int b;
using namespace std;
double f(double x)
{
    double res = 1;
    for (int i = 1; i <= b; ++i)
    {
        res *= x;
    }
    return res;
}
int main()
{
    cin >> a >> b;
    double l = 0, r = a;
    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2.0;
        if (f(mid) < a)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << (int)(l * 1000) << endl;
}