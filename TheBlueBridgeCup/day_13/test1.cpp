#include <iostream>
#include <vector>
#include <algorithm> // 包含 std::sort
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    // 使用 std::sort 函数进行排序
    sort(vec.begin(), vec.end(), [](int a, int b)
         { return a < b; });

    // 输出排序后的结果
    for (int i = 0; i < n; ++i)
    {
        cout << vec[i] << " ";
    }
    return 0;
}
