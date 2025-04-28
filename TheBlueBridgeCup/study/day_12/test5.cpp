#include <bits/stdc++.h> // 包含了 <vector>, <iostream>, <algorithm> 等
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // 1. 读取向量的大小 N
    cin >> N;

    // 检查 N 是否有效 (可选，但良好实践)
    if (N < 0)
    {
        cerr << "错误：向量大小不能为负数。" << endl;
        return 1; // 返回错误码
    }
    if (N == 0)
    {
        cout << endl; // 如果 N=0，输出空行或不输出
        return 0;     // 正常退出
    }

    vector<int> vec(N); // 创建大小为 N 的向量 vec
    // 2. 循环读取 N 个整数到 vec 中
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    vector<int> sorted_vec;
    // 预留空间可能提高效率，避免多次内存重新分配
    sorted_vec.reserve(N);

    // 遍历原始向量 vec 的每个元素
    for (int i = 0; i < vec.size(); ++i)
    {
        int temp = vec[i]; // 当前要插入的元素

        // 3. 找到 temp 在 sorted_vec 中应该插入的位置
        // 使用 lower_bound (二分查找) 找到第一个不小于 temp 的元素的位置
        // 这使得查找过程效率为 O(log k), k 为 sorted_vec 当前大小
        auto it = lower_bound(sorted_vec.begin(), sorted_vec.end(), temp);

        // 4. 在找到的位置插入 temp
        // vector::insert 操作本身的时间复杂度是 O(k)
        sorted_vec.insert(it, temp);
    }

    // (可选) 打印排序后的向量 sorted_vec 以验证结果
    for (int i = 0; i < sorted_vec.size(); ++i)
    {
        cout << sorted_vec[i] << (i == sorted_vec.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0; // 程序正常结束
}