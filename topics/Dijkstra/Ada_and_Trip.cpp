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

vector<vector<pair<int,int>>> adj;
vector<int> dist;
vector<int> parent;

void Disjkstra(int s) {
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > pq;
    dist[s] = 0;
    pq.emplace(0,s);
    while(! pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        
        if(d > dist[u]) {
            continue;
        }
        
        for(auto [v,w] : adj[u]) {
            int nd = w + d;
            if(nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
                pq.emplace(nd,v);
            }
        }
    }
}

int main() {
    ana_Yano;
    int n,m,q; cin >>n>>m>>q;
    adj.assign(n,vector<pair<int,int>>());
    dist.assign(n,1e9);
    parent.assign(n,-1);
    for(int i = 0;i < m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    while(q--) {
        int city; cin >> city;
        int cnt = 0;
        Disjkstra(city);
        int max_w = 0;
        for(int i = 0;i < n;i++) {
            if(dist[i] != 1e9) {
                max_w = max(max_w,dist[i]);
            }
        }
        for(int i = 0;i < n;i++) {
            if(dist[i] == max_w) {
                cnt++;
            }
        }
        cout << max_w << ' ' << cnt << endl;
        dist.assign(n,1e9);
        parent.assign(n,-1);
    }
    return 0;
}