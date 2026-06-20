#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>


#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

map<pair<int,int>,int> vis;

int bfs(int a,int b,int x) {
    queue<array<int,3>> q;
    q.push({a,b,0}); // lvl = 0
    while(! q.empty()) {
        auto cur = q.front();
        int n1 = cur[0]; // a
        int n2 = cur[1]; // b
        int lvl = cur[2]; // level
        q.pop();

        if(n1 == n2) {
            return lvl;
        }

        int max_val = max(n1,n2);
        int min_val = min(n1,n2);
        if(vis[{max_val / x,min_val}] == 0) {
            q.push({max_val / x,min_val, lvl + 1});
            vis[{max_val / x,min_val}] = 1;
        }
        if(vis[{min_val + 1,max_val}] == 0) {
            q.push({min_val + 1,max_val, lvl + 1});
            vis[{min_val + 1,max_val}] = 1;
        }
    }
}

int main() {
    ana_Yano;
    int t; cin >> t;
    while(t--) {
        int a,b,x; cin >> a >> b >> x;
        cout << bfs(a,b,x) << endl;
        vis.clear();
    }
    return 0;
}