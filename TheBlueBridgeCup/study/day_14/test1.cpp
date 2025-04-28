// 对于X、Y、Z三个国家,X获胜的条件为X>Y+Z
// 初始时三者得分均为0,故X能否获胜完全取决于每个事件对应的得分与其他国家得分之差
// 假设发生事件i,X得4分,Y得2分,Z得1分,可知4-2-1>0,X获胜
// 若要求某个国家获胜所发生的最多事件,只需处理每个事件对该国家的纯贡献即可
// 所谓纯贡献就是该事件对该国家的得分与其他国家得分之差,只要大于0即说明可获胜
// 计算每个事件对该国家的纯贡献并从大到小排序,依次累加贡献,
// 只要总的贡献仍然大于0,就说明当前事件是可以发生的,计数值加1
// 依次枚举三个国家,比较出可发生的事件数的最大值即为答案
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 100;

bool cmp(int a, int b) // 从大到小排序
{
    return a > b;
}

int A[N], B[N], C[N]; // 存放魏蜀吴三个国家发生对应事件的得分
int weight[N];        // weight[i]存放魏/蜀/吴发生第i件事对于总得分的影响
int n;

int get_ans(int a[], int b[], int c[]) // a获胜,发生最多的事件数
{
    ll sum = 0;                        // 累加当前总贡献
    memset(weight, 0, sizeof(weight)); // weight数组清零
    for (int i = 1; i <= n; i++)       // 计算每个事件对a的纯贡献
    {
        // 假设a[i]=7,b[i]=2,c[i]=2,则发生i事件对a的纯贡献是7-2-2=3,
        // 可以理解为该发生事件使a比b+c的得分高了3
        weight[i] = a[i] - b[i] - c[i];
    }
    sort(weight + 1, weight + n + 1, cmp); // 将纯贡献按从大到小排序
    int ans = 0;                           // 记录可以发生多少事件使a>b+c
    for (int i = 1; i <= n; i++)
    {
        sum += weight[i]; // 累加贡献
        if (sum > 0)
            ans++; // 累计贡献严格大于0,计数加1
        else
            break; // 若不大于0,由于序列递减,后面只会越来越小,直接退出
    }
    if (ans == 0)
        return -1; // 一个事件都不能发生,返回-1
    return ans;
}

int main()
{
    scanf("%d", &n);
    // 输入原始数据,A、B、C分别存储魏蜀吴三个国家发生对应事件增加的得分
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);

    int ans_A = get_ans(A, B, C);            // 假设魏国获胜,发生最多的事件数
    int ans_B = get_ans(B, A, C);            // 假设蜀国获胜,发生最多的事件数
    int ans_C = get_ans(C, A, B);            // 假设吴国获胜,发生最多的事件数
    int ans = max(ans_A, max(ans_B, ans_C)); // 三者取最大值即可
    printf("%d\n", ans);
    return 0;
}