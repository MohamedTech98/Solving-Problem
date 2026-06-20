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

vector<ll> dist;
vector<int> parent;
vector<vector<pair<int,int>>> adj;

ll Dijkstra(int s) {
    priority_queue<
    pair<ll,int>,
    vector<pair<ll,int>>,
    greater<pair<ll,int>>
    > pq;
    dist[s] = 0;

    pq.emplace(0,s);

    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();

        if(d > dist[u])
            continue; // if the same node insert in pq most one 

        // if(u == t)
        //     return dist[u];

        for(auto &[v,w] : adj[u]) {
            ll nd = dist[u] + w;

            if(nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
                pq.emplace(nd,v);
            }
        }
    }
    return -1;
}

void printPath(int u) {
    if(parent[u] != -1) {
        printPath(parent[u]);
    }
    cout << dist[u] << ' ';
}

int main() {
    ana_Yano;
    int n,m; cin >> n >> m;
    adj.assign(n + 1,vector<pair<int,int>>());
    dist.assign(n + 1,1e18);
    parent.assign(n + 1,-1);
    for(int i = 0;i < m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }
    Dijkstra(1);
    for(int i = 1;i <= n;i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}