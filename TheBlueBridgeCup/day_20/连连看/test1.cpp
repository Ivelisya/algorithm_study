#include <bits/stdc++.h>
using namespace std;
int a[1003][1003];
int n,m;
using ll = long long;
ll get_p(int x,int y){
    map<int,int> mp;
    ll res = 0;
    while(x <= n && y<=m ){
        int key = a[x][y];
        if(mp.count(key)){
            res += mp[key]*2;
        }
        if(mp.count(key) == 0){
            mp[key] = 1;
        }else{
            mp[key]++;
        }
        x++;
        y++;
    }
    return res;
}
ll get_rp(int x,int y){
    map<int,int> mp;
    ll res = 0;
    while(x <= n && y > 0 ){
        int key = a[x][y];
        if(mp.count(key)){
            res += mp[key]*2;
        }
        if(mp.count(key) == 0){
            mp[key] = 1;
        }else{
            mp[key]++;
        }
        x++;
        y--;
    }
    return res;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n; ++ i){
        for(int j = 1;j <= m;++j){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for(int i = 1;i<= m;++i){
        ans += get_p(1,i);
    }
    for(int i = 2;i <= n;++i){
        ans += get_p(i,1);
    }
    for(int i = 1;i<= m;++i){
        ans += get_rp(1,i);
    }
    for(int i = 2;i <= n;++i){
        ans += get_rp(i,m);
    }
    cout << ans << endl;
    return 0;
}