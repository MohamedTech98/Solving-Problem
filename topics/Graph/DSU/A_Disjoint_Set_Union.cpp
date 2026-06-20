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
    int find(int node) {
        if(parent[node] < 0) return node; // root
        return parent[node] = find(parent[node]);
    }
    void init(int n) {
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
        parent[small] = big;
        return true;
    }
};

int main() {
    ana_Yano;
    int n,q; cin>>n>>q;
    DSU tree;
    tree.init(n);
    while(q--) {
        int ch,u,v; cin>>ch>>u>>v;
        if(ch == 0) {
            tree.join(u,v);
        } else {
            cout << (tree.find(u) == tree.find(v) ? 1 : 0) << endl;
        }
    }
    return 0;
}