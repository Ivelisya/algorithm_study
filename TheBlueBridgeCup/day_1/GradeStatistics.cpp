/*
小蓝给学生们组织了一场考试，卷面总分为 100 分，每个学生的得分都是一个 0 到 100 的整数。

如果得分至少是 60 分，则称为及格。如果得分至少为 85 分，则称为优秀。

请计算及格率和优秀率，用百分数表示，百分号前的部分四舍五入保留整 数。
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 0;
    int pass = 0, excellent = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        if (num >= 85)
        {
            excellent++;
            pass++;
        }
        else if (num >= 60)
        {
            pass++;
        }
        num = 0;
    }
    int a = pass * 100.0 / n * 1.0 + 0.5;
    int b = excellent * 100.0 / n * 1.0 + 0.5;
    printf("%d%\n%d%\n", a, b);
    return 0;
}