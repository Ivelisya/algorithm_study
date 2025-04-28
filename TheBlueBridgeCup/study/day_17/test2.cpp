#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // 关闭C++流和C流的同步
    cin.tie(0);                       // 解除cin和cout的绑定

    int n;
    while (cin >> n)
    {
        cout << "Number: " << n; // 现在不会自动刷新缓冲区
    }
    return 0;
}
