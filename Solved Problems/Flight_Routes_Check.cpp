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
vector<bool> vis;

int DFS(int node,vector<vector<int>>& adj) {
    vis[node] = 1;
    int ans = 0;
    for(auto ch : adj[node]) {
        if(vis[ch] == 0) {
            ans += DFS(ch,adj) + 1;
        }
    }
    return ans;
}

int main() {
    ana_Yano;
    vector<vector<int>> adj;
    vector<vector<int>> rev;
    int n,m; cin >> n >> m;
    adj.resize(n + 1,vector<int>());
    rev.resize(n + 1,vector<int>());
    vis.resize(n + 1, 0);
    for(int i = 0;i < m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    if(DFS(1,adj) == n - 1) {
        vis.assign(n + 1,0);
        if(DFS(1,rev) == n - 1) {
            cout << "YES" << endl;
            return 0;
        } else {
            cout << "NO" << endl;
            for(int i = 1;i <= n;i++) {
                if(vis[i] == 0) {
                    cout << i << ' ' << 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    for(int i = 1;i <= n;i++) {
        if(vis[i] == 0) {
            cout << 1 << ' ' << i << endl;
            return 0;
        }
    }
    return 0;
}