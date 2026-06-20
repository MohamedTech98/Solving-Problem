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
 
const int N = 1e5 + 2,mod = 1e9 + 7;
int MX[N],MN[N],ways[N];
 
vector<ll> dist;
vector<vector<pair<int,int>>> adj;
 
 
void Dijkstra(int s,int t) {
    priority_queue<
    pair<ll,int>,
    vector<pair<ll,int>>,
    greater<pair<ll,int>>
    > pq;
    dist[s] = 0;
    MN[s] = 0;
    MX[s] = 0;
    ways[s] = 1;
    pq.emplace(0,s);
 
    while(!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
 
        if(d > dist[u])
            continue;
            
            for(auto &[v,w] : adj[u]) {
                ll nd = dist[u] + w;
                
                if(nd < dist[v]) {
                    dist[v] = nd;
                    ways[v] = ways[u];
                    MX[v] = MX[u] + 1;
                    MN[v] = MN[u] + 1;
                    pq.emplace(nd,v);
                } else if (nd == dist[v]) {
                    dist[v] = nd;
                    ways[v] += ways[u];
                    ways[v] %= mod;
                    MX[v] = max(MX[v],MX[u] + 1);
                    MN[v] = min(MN[v],MN[u] + 1);
                }
        }
    }

    cout << dist[t] << ' ';
    cout << ways[t] << ' ';
    cout << MN[t] << ' ';
    cout << MX[t] << ' ';
}

int main() {
    ana_Yano;
    int n,m; cin >> n >> m;
    adj.assign(n + 1,vector<pair<int,int>>());
    dist.assign(n + 1,1e18);
    for(int i = 1;i <= n;i++) {
        MX[i] = 0;MN[i] = 1e9;ways[i] = 0;
    }
    for(int i = 0;i < m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    Dijkstra(1 , n);
    return 0;
}