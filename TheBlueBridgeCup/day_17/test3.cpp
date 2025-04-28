#include <iostream> // 引入输入输出流库，用于cin和cout
#include <vector>   // 引入向量库，虽然此代码没直接用vector存储，但它是处理序列的常用库
#include <numeric>  // 引入数值算法库，包含如accumulate等函数，这里注释说明可能有用，但实际是手动实现前缀和

int main()
{
    // 关闭C++标准流与C标准IO的同步，解除cin与cout的绑定，以加速输入输出
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;         // 声明一个整型变量n，用于存储输入整数的个数
    std::cin >> n; // 从标准输入读取整数个数n

    // 使用 long long 类型防止整数溢出，因为两两相乘再相加的和可能非常大
    long long current_prefix_sum = 0; // 声明长整型变量，用于存储遍历过程中当前元素之前所有元素的和（即前缀和）
    long long result_s = 0;           // 声明长整型变量，用于存储最终计算结果 S

    // 开始逐个处理输入的n个整数
    // 循环n次，每次处理一个数 a_i
    for (int i = 0; i < n; ++i)
    {
        long long a_i;   // 声明长整型变量，用于存储当前读入的整数
        std::cin >> a_i; // 从标准输入读取当前的整数 a_i

        // 核心计算步骤：
        // 将当前元素 a_i 与其前面所有元素的和 (current_prefix_sum) 相乘
        // 这个乘积 a_i * current_prefix_sum 代表了 a_i * a_1 + a_i * a_2 + ... + a_i * a_{i-1}
        // 将这个乘积累加到最终结果 result_s 中
        result_s += a_i * current_prefix_sum;

        // 更新前缀和：
        // 将当前元素 a_i 加入到 current_prefix_sum 中
        // 这样，在处理下一个元素 a_{i+1} 时，current_prefix_sum 就包含了 a_1 到 a_i 的和
        current_prefix_sum += a_i;
    }

    // 循环结束后，result_s 中存储了所有满足 i < j 的 a_i * a_j 的总和
    std::cout << result_s << std::endl; // 将计算得到的最终结果 S 输出到标准输出，并换行

    return 0; // 程序正常结束，返回0
}
