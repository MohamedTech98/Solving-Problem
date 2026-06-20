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
vector<vector<pair<int,int>>> adj;
vector<tuple<int,int,ll>> road;
vector<pair<int,int>> trains;

void Dijkstra(int s,int t) {
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
            continue; 
        


        for(auto &[v,w] : adj[u]) {
            ll nd = dist[u] + w;

            if(nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd,v);
            }
        }
    }
}


int main() {
    ana_Yano;
    int n,m,k; cin >> n >> m >> k;
    adj.assign(n + 1,vector<pair<int,int>>());
    dist.assign(n + 1,1e18);
    // road.assign(n + 1,tuple<int,int,ll>());
    // parent.assign(n + 1,-1);
    for(int i = 0;i < m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        road.push_back({u,v,w});
    }

    for(int i = 0;i < k;i++) {
        int s,y; cin >> s >> y;
        adj[1].push_back({s,y});
        adj[s].push_back({1,y});
        trains.push_back({s,y});
    }
    Dijkstra(1,n);
    vector<int> used(n + 1,0);
    for(auto [u,v,w] : road) {
        if(dist[u] + w == dist[v]) {
            // take this road
            used[v]++;
        }
        if(dist[v] + w == dist[u]) {
            used[u]++;
        }
    }
    int ans = 0;
    for(auto [s,y] : trains) {
        if(dist[s] < y) {
            // cost trian is large
            ans++;
        } else if(dist[s] == y) {
            // cost this equal check if include shortest path or not
            if(used[s] > 0) {
                ans++; // used road 
            } else {
                used[s]++; // used trian so if any train the same value remove it
            }
        }
    }
    cout << ans << endl;
    return 0;
}