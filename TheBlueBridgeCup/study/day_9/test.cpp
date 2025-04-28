#include <bits/stdc++.h>
using namespace std;

vector<string> step;
int n, target_move;

void hanoi(int n, string src, string aux, string target)
{
    if (n == 1)
    {
        string s = "#" + to_string(n) + "：" + src + "->" + target;
        step.push_back(s);
        return;
    }
    hanoi(n - 1, src, target, aux);
    string s = "#" + to_string(n) + "：" + src + "->" + target;
    step.push_back(s);
    hanoi(n - 1, aux, src, target);
}

int main()
{
    cin >> n >> target_move;
    hanoi(n, "A", "B", "C");

    if (target_move > 0 && target_move <= step.size())
    {
        cout << step[target_move - 1] << endl;
    }
    cout << step.size() << endl;
    return 0;
}