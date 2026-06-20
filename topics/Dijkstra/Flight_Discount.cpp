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
vector<vector<ll>>dist;
// vector<int> path;

struct state {
    ll dist;
    int u;
    int coupon;
};

struct cmp {
    bool operator()(state& a,state& b) {
        return a.dist > b.dist;
    }
};

ll Dijkstra(int s,int t) {
    priority_queue<
    state,
    vector<state>,
    cmp
    >pq;
    dist[s][0] = 0;
    dist[s][1] = 0;
    pq.push({0,s,0});
    while(! pq.empty()) {
        auto cur = pq.top();
        auto d = cur.dist;
        auto u = cur.u;
        auto f = cur.coupon;
        // f = 0 not used coupon f = 1 used coupon
        pq.pop();

        if(d > dist[u][f]) {
            continue;
        }
        
        if(u == t) {
            return min(dist[u][0],dist[u][1]);
        }

        for(auto [v,w] : adj[u]) {
            if(f == 0) {
                if(dist[v][1] > d + w / 2) {
                    dist[v][1] = d + w / 2;
                    pq.push({dist[v][1],v,1});
                }
            }
            ll nd = dist[u][f] + w;
            if(nd < dist[v][f]) {
                dist[v][f] = nd;
                pq.push({dist[v][f],v,f});
            }
        }
    }
    return -1;
}

int main() {
    ana_Yano;
    int n,m; cin >> n >> m;
    adj.assign(n + 1,vector<pair<int,int>>());
    dist.assign(n + 1,vector<ll>(2,1e18));
    // path.assign(n + 1,0);
    for(int i = 0;i < m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    ll ans = Dijkstra(1,n);
    // ll max_w = -1;
    // for(int i = 1;i <= n;i++) {
    //     max_w = max(max_w,1ll * path[i]);
    //     cout << i << ' ' << path[i] << endl;
    // }
    // ans = ans - (max_w - (max_w / 2));
    cout << ans << endl;
    return 0;
}