#include <iostream>
#include <vector>

using namespace std;

int ans[10];  // 存储当前排列的数组
bool vis[10]; // 标记数字是否被使用，vis[i] 为 true 表示数字 i 已经被使用
int n;        // 要排列的数字的个数

void dfs(int cnt)
{
    // cnt 为当前递归的深度，表示正在填充第 cnt 个位置 (从 0 开始)
    if (cnt == n)
    {
        // 递归到最后一层，说明已经生成了一个完整的排列，输出它
        for (int i = 0; i < n; ++i)
        { // 修改：从 0 开始，到 n-1 结束
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        // 循环遍历所有可能的数字
        if (!vis[i])
        {
            // 如果数字 i 还没有被使用
            vis[i] = true;  // 标记数字 i 为已使用
            ans[cnt] = i;   // 将数字 i 放入 ans 数组的第 cnt 个位置
            dfs(cnt + 1);   // 递归调用自身，继续填充下一个位置
            vis[i] = false; // 回溯：将数字 i 标记为未使用，以便在后续的循环中可以选择这个数字
        }
    }
}

int main()
{
    cin >> n; // 输入要排列的数字的个数
    dfs(0);   // 修改：从第 0 层开始递归
    return 0;
}
