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
vector<ll> dist;

void Dijkstra(int s) {
    priority_queue<
    pair<ll,int>,
    vector<pair<ll,int>>,
    greater<pair<ll,int>>
    > pq;
    dist[s] = 0;

    pq.emplace(0,s);

    while(! pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();

        if(d > dist[u])
            continue;

        for(auto [v,w] : adj[u]) {
            ll nd = d + w;
            if(nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd,v);
            }
        }
    }
}

int main() {
    ana_Yano;
    int n,m,y; cin >> n >> m >> y;
    dist.assign(n + 2,1e18);
    adj.assign(n + 2,vector<pair<int,int>>());
    for(int i = 0;i < m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    const int W = n + 1; // create center node between all nodes
    for(int i = 1;i <= n;i++) {
        int x; cin >> x;
        adj[i].push_back({W,x}); // node -> w cost = x
        adj[W].push_back({i,x + y}); // w -> node cost = x + y
        // if the path i -> w -> node(j) in shortest path 
        // so the total cost from 1 to j is dist[i] + xi + xj + y (amazing) 
    }

    Dijkstra(1);
    for(int i = 2;i <= n;i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}