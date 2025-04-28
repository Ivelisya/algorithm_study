#include <iostream>

using namespace std;

const int N = 105;
int q[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> q[i]; // 从 1 开始，q[0] 作为哨兵

    for (int i = 2; i <= n; ++i)
    {
        int j = i - 1; // 定义并初始化 j

        if (q[i] < q[i - 1])
        {
            q[0] = q[i]; // 设置哨兵
            while (q[0] < q[j])
            {
                q[j + 1] = q[j];
                j--;
            }
            q[j + 1] = q[0];
        }
    }

    for (int i = 1; i <= n; ++i)
    {                                        // Corrected loop condition here
        cout << q[i] << (i == n ? "" : " "); // 使用i作为循环变量
    }
    cout << endl;

    return 0;
}
