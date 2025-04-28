#include <iostream>
#include <vector>

using namespace std;

// 比较两个大整数的大小，以vector<int>形式表示
bool cmp(vector<int> &A, vector<int> &B)
{   
    // 如果A的位数大于B的位数，则A大于B
    if (A.size() != B.size())
        return A.size() > B.size();

    // 从最高位开始比较，如果A的某一位大于B的对应位，则A大于B
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] > B[i];
    }

    // 如果所有位都相等，则A等于B
    return true;
}

// 大整数减法，A - B，以vector<int>形式表示
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    // t表示借位
    for (int i = 0, t = 0; i < A.size(); i++)
    {
        // 计算当前位的差
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        // 将结果添加到C中，如果差为负数，则加上10，并设置借位为1
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }

    // 去除前导零
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

// 大整数乘法，A * B，以vector<int>形式表示
vector<int> mul(vector<int> &A, vector<int> &B)
{
    // C的长度为A的长度加上B的长度
    vector<int> C(A.size() + B.size());

    // 计算每一位的乘积
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            C[i + j] += A[i] * B[j];

    // 处理进位
    for (int i = 0, t = 0; i < C.size(); i++)
    {
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }

    // 去除前导零
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;
}

int main(void)
{
    vector<int> A, B, C;
    string aa, bb, a, b;

    // 输入两个大整数
    cin >> aa >> bb;

    // 处理负数
    if (aa[0] == '-')
        for (int i = 1; i < aa.size(); i++)
            a += aa[i];
    else
        a = aa;
    if (bb[0] == '-')
        for (int i = 1; i < bb.size(); i++)
            b += bb[i];
    else
        b = bb;

    // 将字符串转换为vector<int>
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    // 计算A^2和B^2
    A = mul(A, A);
    B = mul(B, B);

    // 计算A^2 - B^2
    if (cmp(A, B))
        C = sub(A, B);
    else
    {
        cout << '-';
        C = sub(B, A);
    }

    // 输出结果
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    cout << endl;

    return 0;
}