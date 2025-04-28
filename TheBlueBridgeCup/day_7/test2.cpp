#include <stdio.h>
int a[5][50] = {0}; // 定义数组a[i][j] 表示i位数和为j，j最大为9*i；
int count = 0;
void num(int x)
{
    int t = 0, sum = 0; // 判断位数
    while (x)
    {
        sum += x % 10;
        x /= 10;
        t++;
    }
    a[t][sum]++;
}
int main()
{
    for (int i = 1; i <= 9999; i++)
    {
        num(i);
    }
    for (int i = 1; i <= 4; i++)
    { // 左一半,1-4
        for (int j = 1; j <= i * 9; j++)
        {
            for (int k = 1; k <= i; k++)
            { // 右一半只要比i小前面补0
                count += a[i][j] * a[k][j];
            }
        }
    }
    printf("%d", count);
    return 0;
}