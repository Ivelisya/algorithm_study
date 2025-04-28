#include <stdio.h>
#include <stdlib.h>

int move_count = 0; // 记录移动次数

/**
 * 递归实现汉诺塔移动
 * @param n 盘子的数量
 * @param source 源柱子
 * @param auxiliary 辅助柱子
 * @param target 目标柱子
 * @param target_move 需要输出的第 target_move 次移动
 */
void hanoi(int n, char source, char auxiliary, char target, int target_move)
{
    if (n == 1)
    { // 递归终止条件：仅有一个盘子，直接移动
        move_count++;
        if (move_count == target_move)
        {
            printf("#%d: %c -> %c\n", move_count, source, target);
        }
        return;
    }

    // 递归调用：先将 n-1 个盘子从 source 移动到 auxiliary
    hanoi(n - 1, source, target, auxiliary, target_move);

    // 移动第 n 个盘子到 target
    move_count++;
    if (move_count == target_move)
    {
        printf("#%d: %c -> %c\n", move_count, source, target);
    }

    // 递归调用：再将 n-1 个盘子从 auxiliary 移动到 target
    hanoi(n - 1, auxiliary, source, target, target_move);
}

int main()
{
    int n, target_move;

    // 输入盘子数量和目标步数
    scanf("%d %d", &n, &target_move);

    // 执行汉诺塔算法
    hanoi(n, 'A', 'B', 'C', target_move);

    // 输出总步数
    printf("Total moves: %d\n", move_count);

    return 0;
}
