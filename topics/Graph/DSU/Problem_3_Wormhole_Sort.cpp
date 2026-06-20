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
    int n,m; cin>>n>>m;
    vector<int> p(n);
    for(int &val : p) cin>>val;
    DSU dsu(n);
    vector<array<int,3>> width(m);
    for(int i = 0;i < m;i++) {
        cin>>width[i][1]>>width[i][2]>>width[i][0]; // width,u,v
    }
    sort(width.begin(),width.end(),greater<array<int,3>>());
    // for(int i = 0;i < m;i++) {
    //     cout<<width[i][1]<<' '<<width[i][2]<<' '<<width[i][0]<<endl;
    // }
    for(int i = 0;i < m;i++) {
        int u = width[i][1];
        int v = width[i][2];
        dsu.join(u,v);
    }
    return 0;
}