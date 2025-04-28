#include <bits/stdc++.h>
using namespace std;
int b,p,k;
#if 0
long long quick_pow(){
    long long ans = 0;
    while(p > 0){
        if(p & 1){
            ans = ans * b % k;
        }
        p >>= 1;
        b = b * b % k;
    }
    return ans;
}
#endif
int main(){
    cin >> b >> p >> k;
    long long ans = 1;
    while(p > 0){
        if(p & 1){
            ans = ans * b % k;
        }
        p >>= 1;
        b = b * b % k;
    }
    return cout << ans << endl,0;
}