#include <bits/stdc++.h>
using namespace std;
// 实现全排列
void dfs(int index, string s, vector<string> &ans)
{
    if (index == s.size())
    {
        ans.push_back(s);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        dfs(index + 1, s, ans);
        // 回溯算法
        swap(s[index], s[i]);
    }
}
vector<string> permutation(string s)
{
    vector<string> ans;
    dfs(0, s, ans);
    return ans;
}