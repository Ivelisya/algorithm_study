#include <bits/stdc++.h>
using namespace std;
int t,n,m;
long long C(int n,int m){
    if(m > n) return 0;
    if(m == 1) return n;
    if(m == 0) return 1;
    return C(n-1,m) + C(n -1,m-1);
}
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << C(n,m) << endl;
    }
}