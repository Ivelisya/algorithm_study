#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> vec_pair; // Corrected: No initial size
    int closed_figure[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        int clo = 0;
        int temp2 = temp;

        while (temp2 > 0)
        {
            int a = temp2 % 10;
            clo += closed_figure[a];
            temp2 /= 10;
        }
        vec_pair.push_back({temp, clo});
    }

    sort(vec_pair.begin(), vec_pair.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)
         {
        if (p1.second != p2.second) {
            return p1.second < p2.second;
        }
        return p1.first < p2.first; });

    for (const auto &p : vec_pair)
    {
        cout << p.first << " ";
    }
    cout << endl;

    return 0;
}
