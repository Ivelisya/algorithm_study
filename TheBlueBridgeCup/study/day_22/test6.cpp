#include <bits/stdc++.h>
using namespace std;
long long memo[20][20];
int t,n,m;
long long C(int n,int m){
    if (m > n || m < 0 || n < 0) return 0;
    if (m == 0 || m == n) return 1; // m=n 也是 1
    if (m == 1) return n;
    if(memo[n][m] != -1){
        return memo[n][m];
    }
    memo[n][m] = C(n -1,m) + C(n-1,m-1);
    return memo[n][m];
}
int main(){
    cin >> t;
    memset(memo,-1,sizeof(memo));
    while(t--){
        cin >> n >> m;
        cout << C(n,m) << endl;
    }
    
}