#include <bits/stdc++.h>
using namespace std;
// const int N = 1e5 + 5;
int T,A,B;
int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    cin >> T;
    for(int i = 1; i<= T;++i){
        cin >> A >> B;
        cout << gcd(A,B) << endl;
    }
    return 0;
}