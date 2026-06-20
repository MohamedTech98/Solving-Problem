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

struct state {
    ll dist;
    int u;
    int f;
    bool operator>(state &other) const {
        return dist > other.dist;
    }
};

vector<vector<ll>> dist;
vector<int> parent;
vector<vector<pair<int,int>>> adj;
vector<int> horse;

ll Dijkstra(int s,int t) {
    priority_queue<
    state,
    vector<state>,
    greater<state>
    > pq;
    dist[s][horse[s]] = 0;

    pq.push({0,s,horse[s]});

    while(!pq.empty()) {
        auto cur = pq.top();
        auto d = cur.dist;
        auto u = cur.u;
        auto h = cur.f;

        pq.pop();

        if(d > dist[u][h])
            continue; 
            // if the same node insert in pq most one.
            // in pq may be least value is assign to node
            // so we needn't to compare

        if(u == t)
            return dist[u][h];

        for(auto &[v,w] : adj[u]) {

        int nh = h | horse[v];

        ll nd = dist[u][h] + w;

        if(h == 0 && horse[v]) {
            nd = min(nd, dist[u][h] + w/2);
        }

        if(nd < dist[v][nh]) {
            dist[v][nh] = nd;
            pq.push({nd, v, nh});
        }
}
    }
    return -1;
}

void printPath(int u) {
    if(parent[u] != -1) {
        printPath(parent[u]);
    }
    cout << u << ' ';
}

int main() {
    ana_Yano;
    int t; cin >> t;
    while(t--) {
        int n,m,h; cin >> n >> m >> h;
        adj.assign(n + 1,vector<pair<int,int>>());
        dist.assign(n + 1,vector<ll>(2,1e18));
        parent.assign(n + 1,-1);
        horse.assign(n + 1,0);
        for(int i = 0;i < h;i++) {
            int pos; cin >> pos;
            horse[pos] = 1;
        }
        for(int i = 0;i < m;i++) {
            int u,v,w; cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        cout << Dijkstra(1,n) << endl;
    }
    return 0;
}