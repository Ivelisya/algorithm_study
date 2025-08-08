#include <vector>
#include <cmath>

class Solution
{
private:
    // 使用二維向量作為備忘錄 (memoization table)
    // 儲存已經計算過的 solve(a, b) 的結果
    std::vector<std::vector<double>> memo;

    // 遞迴輔助函數，實現記憶化搜索
    double solve(int a, int b)
    {
        // 基本情況 1: A 和 B 同時或之前耗盡
        if (a <= 0 && b <= 0)
        {
            return 0.5;
        }
        // 基本情況 2: A 先耗盡
        if (a <= 0)
        {
            return 1.0;
        }
        // 基本情況 3: B 先耗盡
        if (b <= 0)
        {
            return 0.0;
        }

        // 如果當前狀態已經計算過，直接從備忘錄返回結果
        if (memo[a][b] != -1.0)
        {
            return memo[a][b];
        }

        // 狀態轉移方程：遞迴計算四種操作的期望概率
        // 每種操作的概率是 0.25
        double result = 0.25 * (solve(a - 4, b) +
                                solve(a - 3, b - 1) +
                                solve(a - 2, b - 2) +
                                solve(a - 1, b - 3));

        // 將計算結果存入備忘錄並返回
        return memo[a][b] = result;
    }

public:
    double soupServings(int n)
    {
        // 剪枝優化：當 n 非常大時，湯 A 的消耗速度遠快於湯 B，
        // 導致 A 先耗盡的概率會無限趨近於 1。
        // 經過數學和實驗驗證，當 n >= 4800 時，結果與 1 的誤差已小於 10^-5。
        // 直接返回 1.0 可以避免處理大 N 時的超時或堆疊溢位問題。
        if (n >= 4800)
        {
            return 1.0;
        }

        // 將 n 毫升轉換為以 25 毫升為單位的「份數」
        // (n + 24) / 25 是 ceil(n / 25.0) 的高效整數實現方式
        int N = (n + 24) / 25;

        // 初始化備忘錄，大小為 (N+1) x (N+1)，初始值設為 -1.0 表示尚未計算
        memo.assign(N + 1, std::vector<double>(N + 1, -1.0));

        // 從初始狀態 (N, N) 開始求解
        return solve(N, N);
    }
};