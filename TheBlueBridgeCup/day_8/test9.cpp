#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> step;
int n, m;

void move(int u, string first, string aim, string temp)
{
    if (u == 1)
    {
        string s = "#" + to_string(u) + ": " + first + "->" + aim;
        step.push_back(s);
        return;
    }
    move(u - 1, "A", "B", "C");
    string s = "#" + to_string(u) + ": " + first + "->" + aim;
    step.push_back(s);
    move(u - 1, "B", "C", "A");
}

int main()
{
    cin >> n >> m;
    move(n, "A", "C", "B");
    cout << step[m - 1] << endl;
    cout << step.size() << endl;
    return 0;
}