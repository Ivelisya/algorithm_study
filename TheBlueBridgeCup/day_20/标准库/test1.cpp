#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<int> q;
    while (n--)
    {
        string op;
        int k;
        cin >> op;
        if (op == "push")
        {
            cin >> k;
            q.push(-k);
        }
        else if (op == "min")
        {
            if (q.empty())
                printf("empty\n");
            else
                printf("%d\n", -q.top());
        }
        else if (op == "remove")
        {
            if (q.empty())
                printf("empty\n");
            else
            {
                q.pop();
            }
        }
        else if (op == "print")
        {
            cin >> k;
            while (k--)
            {
                cout << -q.top() << " ";
                q.pop();
            }
            printf("\n");
        }
    }
}