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
    int n,m1,m2; cin>>n>>m1>>m2;
    DSU mocha(n),diana(n);
    for(int i = 0;i < m1;i++) {
        int u,v; cin>>u>>v;
        mocha.join(u,v);
    }
    for(int i = 0;i < m2;i++) {
        int u,v; cin>>u>>v;
        diana.join(u,v);
    }
    vector<pair<int,int>> ans;
    int j = 1; 
    while(mocha.ncomp > 1 && diana.ncomp > 1 && j <= n) {
        for(int i = 2;i <= n;i++) {
            // cout << mocha.find(i) << " " << diana.find(i) << endl;
            if(mocha.find(j) != mocha.find(i) && diana.find(j) != diana.find(i) ) {
                mocha.join(j,i) && diana.join(j,i);
                ans.push_back({j,i});
            }
        }
        j++;
    }
    cout << ans.size() << endl;
    for(auto edge : ans) {
        cout << edge.first << ' ' << edge.second << endl;
    }
    return 0;
}