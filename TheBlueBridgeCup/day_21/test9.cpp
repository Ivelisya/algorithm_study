/*
不允许同排 不允许同列 不允许在斜线上
*/
#include <bits/stdc++.h>
using namespace std;
int N;
int count = 0;
vector<int> vec; // 保存行对应的列;
bool check(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        if (vec[i] == col || abs(row - i) == abs(col - vec[i]))
        {
            return false;
        }
    }
    return true;
}
void dfs(int row)
{
    if (row > N)
    {
        ::count++;
        return;
    }
    for(int col = 1;col <= N;col++){
        if(check(row,col)){
            vec[row] = col;
            dfs(row + 1);
        }
    }

}
int main()
{
    cin >> N;
    vec.resize(N + 1);
    dfs(1);
    cout << ::count<< endl;
}