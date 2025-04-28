#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int n;
int get_ans(ll *a, ll *b, ll *c)
{
    ll sum = 0;
    int temp[N];
    for (int i = 0;i < n;++i){
        temp[i] = a[i] - b[i] - c[i];
    }
    sort(temp,temp + n,[](int a,int b){
        return a > b;
    });
    int ans = 0;
    for(int i = 0; i < n;++i){
        sum += temp[i];
        if(sum > 0){
            ans++;
        }else{
            break;
        }
    }
    if(ans == 0) return -1;
    return ans;
}
int main()
{
    cin >> n;
    ll a[N], b[N], c[N];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }
    int ans_a = get_ans(a,b,c);
    int ans_b = get_ans(b,a,c);
    int ans_c = get_ans(c,a,b);

    int ans = max({ans_a,ans_b,ans_c});

    cout << ans;
    return 0;
}