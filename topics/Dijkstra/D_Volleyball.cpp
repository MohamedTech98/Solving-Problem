#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    int x,y;
    cin >> x >> y;

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<ll> t(n + 1), c(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
    }

    if(x == y) {
        cout << 0 << '\n';
        return 0;
    }

    vector<vector<pair<int,ll>>> taxi_adj(n + 1);

    for(int src = 1; src <= n; src++) {

        vector<ll> dist(n + 1, INF);

        priority_queue<
            pair<ll,int>,
            vector<pair<ll,int>>,
            greater<pair<ll,int>>
        > pq;

        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()) {

            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v,w] : adj[u]) {

                if(dist[v] > d + w) {

                    dist[v] = d + w;
                    pq.push({dist[v],v});
                }
            }
        }

        for(int v = 1; v <= n; v++) {

            if(v != src && dist[v] <= t[src]) {

                taxi_adj[src].push_back({v,c[src]});
            }
        }
    }

    vector<ll> cost(n + 1, INF);

    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    cost[x] = 0;
    pq.push({0,x});

    while(!pq.empty()) {

        auto [cur,u] = pq.top();
        pq.pop();

        if(cur > cost[u]) continue;

        for(auto &[v,w] : taxi_adj[u]) {

            if(cost[v] > cur + w) {

                cost[v] = cur + w;
                pq.push({cost[v],v});
            }
        }
    }

    cout << (cost[y] == INF ? -1 : cost[y]) << '\n';

    return 0;
}