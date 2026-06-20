#include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<map>


#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
const int mod = 1e9 + 7;
struct DSU {
    vector<int> parent;
    int ncomp;
    DSU(int n) {
        ncomp = n;
        parent.assign(n + 1,-1);
    }
    int find(int x) {
        if(parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }
    bool join(int big,int small) {
        int u = big,v = small;
        big = find(big);
        small = find(small);
        if(big == small) {
            return false;
        }
        if(-parent[big] < -parent[small]) {
            swap(big,small);
        }
        parent[big] += parent[small];
        parent[small] = big;
        ncomp--;
        return true;
    }
};

int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    DSU dsu(n);
    ll ans = 1;
    for(int i = 0;i < m;i++) {
        int u,v; cin>>u>>v;
        if(dsu.join(u,v)) {
            ans *= 1ll * 2;
        }
    }
    cout << ans;
    return 0;
}