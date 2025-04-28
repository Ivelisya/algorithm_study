#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    set<int> myset;
    char method = ' ';
    while (q--)
    {
        int temp = 0;
        cin >> method;
        if (method == 'Q')
        {
            cin >> temp;
            if (myset.count(temp))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        if (method == 'I')
        {
            cin >> temp;
            if (!myset.count(temp))
            {
                myset.insert(temp);
            }
        }
    }
}