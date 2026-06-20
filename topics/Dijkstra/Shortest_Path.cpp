#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s,t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    vector<ll> dist(n,INF);
    vector<int> parent(n,-1);

    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    dist[s]=0;
    pq.push({0,s});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(d!=dist[u]) continue;

        for(auto &[v,w]:adj[u]){
            ll nd=d+w;

            if(nd<dist[v]){
                dist[v]=nd;
                parent[v]=u;
                pq.push({nd,v});
            }
        }
    }

    if(dist[t]==INF){
        cout << -1 << '\n';
        return 0;
    }

    vector<pair<int,int>> path;

    for(int cur=t; parent[cur]!=-1; cur=parent[cur]){
        path.push_back({parent[cur],cur});
    }

    reverse(path.begin(),path.end());

    cout << dist[t] << ' ' << path.size() << '\n';

    for(auto &[u,v]:path){
        cout << u << ' ' << v << '\n';
    }
}