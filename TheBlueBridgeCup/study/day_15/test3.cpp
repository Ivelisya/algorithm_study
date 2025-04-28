#include <bits/stdc++.h>
using namespace std;
int a[1010], p[1010], o[1010];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i];
        o[p[i]] = 1; // 存储可以交换的情况
    }
    for (int i = 1; i < n; i++)
    { // 小于n防止数组溢出
        if (a[i] > a[i + 1])
        {
            if (o[i] == 1)
                swap(a[i], a[i + 1]);
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}