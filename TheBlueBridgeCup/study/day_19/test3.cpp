/*题目名称： 子段异或和之和

题目描述：

给定一个包含 n 个整数的数组 A，你需要计算所有子段的异或和，并将这些异或和加起来。具体来说，对于所有满足 1 ≤ L ≤ R ≤ n 的 L 和 R，计算数组 A 中从第 L 个元素到第 R 个元素的异或和，然后输出所有这些异或和的总和。

输入格式：

第一行包含一个整数 n，表示数组 A 的长度。
第二行包含 n 个整数 Ai ，表示数组 A 的元素，相邻整数之间用空格分隔。
输出格式：

输出一行包含一个整数，表示所有子段异或和的总和。*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 2 ^ 20 即 有21 位
// 位运算技巧 1.拆位
// 问题转换成 对于一个 0/1数组 如何求亦或和之和
// 统计前面数组个数

// 统计0 / 1 的作用
// 对当前这位来说 存在多少个子数组

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i]; // 将元素都放进数组中
    }
    // 再开辟一个数组放前缀和
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        // 计算前缀和
        prefix[i] = prefix[i - 1] ^ v[i];
    }
    // 判断当前位所存在的子段个数
    ll sum = 0;
    for (int bit = 0; bit <= 20; ++bit)
    {
        ll bit_set = 0;
        ll count0 = 1; // 当前为0的个数
        ll count1 = 0; // 当前为1的个数
        // 判断前缀和当前位为0还是1
        for (int i = 1; i <= n; ++i)
        {
            if (((prefix[i] >> bit) & 1) == 1)
            {
                bit_set += count0;
                count1++;
            }
            else
            {
                bit_set += count1;
                count0++;
            }
        }
        sum += bit_set * (1LL << bit);
    }
    cout << sum << endl;
    return 0;
}
