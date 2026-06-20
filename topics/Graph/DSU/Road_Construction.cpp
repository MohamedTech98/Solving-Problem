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
    int ncmp,max_size;
    int find(int node) {
        if(parent[node] < 0) return node; // root
        return parent[node] = find(parent[node]);
    }
    void init(int n) {
        ncmp = n;
        max_size = -1;
        parent.assign(n + 1,-1);
    }
    bool join(int big,int small) {
        big = find(big);
        small = find(small);
        if(big == small) {
            return false;
        }
        if(-parent[big] < -parent[small]) {
            swap(big,small);
        }
        parent[big] += parent[small];
        ncmp--;
        max_size = max(max_size,-parent[big]);
        parent[small] = big;
        return true;
    }
};

int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    DSU tree;
    tree.init(n);
    for(int i = 0,u,v;i < m;i++) {
        cin>>u>>v;
        tree.join(u,v);
        cout << tree.ncmp << " " << tree.max_size << endl;
    }
    return 0;
}