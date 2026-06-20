// #include<bits/stdc++.h>
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
        parent.assign(n + 1,-1);
        // n_edges.assign(n + 1,0);
        ncomp = n;
    }
    int find(int node) {
        if(parent[node] < 0) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void join(int big,int small) {
        big = find(big);
        small = find(small);
        if(big == small) {
            return;
        }
        if(-parent[big] < -parent[small]) {
            swap(big,small);
        }
        parent[big] += parent[small];
        parent[small] = big;
        ncomp--;
    }
};

int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    DSU tree(n);
    vector<int> n_edges(n + 1,0);
    vector<pair<int,int>> edges(m + 1);
    for(int i = 1,u,v;i <= m;i++) {
        cin>>u>>v;
        edges[i].first = u;
        edges[i].second = v;
        n_edges[u]++;
        n_edges[v]++;
        tree.join(u,v);
    }
    int q; cin>>q;
    while(q--) {
        int edge; cin>>edge;
        int node1 = edges[edge].first;
        int node2 = edges[edge].second;
        n_edges[node1]--;
        n_edges[node2]--;
        // cout <<edge<<" "<< n_edges[node1] <<" "<<n_edges[node2]<<endl;
        if(n_edges[node1] <= 0 || n_edges[node2] <= 0) {
            tree.ncomp++;
        }
        cout << tree.ncomp << " ";
    }
    return 0;
}