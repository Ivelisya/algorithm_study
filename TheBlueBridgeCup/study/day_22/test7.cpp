#include <bits/stdc++.h>
using namespace std;
int n, m, c;
using ll = long long;
vector<vector<ll>> memo;
ll C(int n,int m){
    if(m > n || m < 0 || n < 0) return 0;
    if(m == 1) return n % c;
    if(m == 0) return 1 % c;
    if(memo[n][m] != -1){
        return memo[n][m];
    }
    memo[n][m] = (C(n -1,m) % c + C(n - 1,m -1) % c) % c;
    return memo[n][m];

}
int main()
{
    cin >> n >> m >> c;
    if(m > n - m) m = n -m;
    memo.resize(n + 1,vector<ll>(n + 1,-1));
    cout << C(n,m) << endl;
}