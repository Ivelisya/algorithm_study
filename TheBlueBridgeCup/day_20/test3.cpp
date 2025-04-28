#include <bits/stdc++.h>
using namespace std;
unordered_multimap<string, string> unmulmap;
int main()
{
    int n;
    cin >> n;
    string method, author, book;
    while (n--)
    {
        cin >> method;
        if (method == "find")
        {
            int temp = 0;
            cin >> author;
            for (auto &[first, second] : unmulmap)
            {
                if (first == author)
                {
                    temp++;
                }
            }
            cout << temp << endl;
        }
        else if (method == "add")
        {
            cin >> book >> author;
            unmulmap.insert({author, book});
        }
    }
}