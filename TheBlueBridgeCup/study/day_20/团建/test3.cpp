#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int res,a[N],b[N],n,m; //a,b 存入权值
vector<int> G1[N],G2[N]; //G1 G2 邻接图
void dfs(int u1,int f1,int v2,int f2,int dep){
    res = max(res,dep);
    map<int,int> mp;
    for(auto& i : G1[u1]){
        if(i == f1) continue;
        mp[a[i]] = i;
    }
    for(auto& i:G2[v2]){
        if(i == f2) continue;
        if(mp[b[i]]){
            dfs(mp[b[i]],u1,i,v2,dep+1);
        }
    }

}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> b[i];
    }
    for(int i = 1;i <= n - 1;i++){
        int u,v;
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    
    for(int i = 1;i <= m - 1;i++){
        int u,v;
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }

    if(!(a[1] == b[1])) return cout << 0 << endl,0;
    dfs(1,0,1,0,1);
    return cout << res << endl,0;
}
