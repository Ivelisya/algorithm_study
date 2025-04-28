#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> mymap;
    int n;
    cin >> n;
    int max = 0;
    while(n--){
        int temp;
        cin >> temp;
        mymap[temp - 1]++;
        mymap[temp] ++;
        mymap[temp + 1]++;
    }
    for(const auto& pair : mymap){
        if(pair.second > max) max =pair.second;
    }
    cout << max << endl;
}