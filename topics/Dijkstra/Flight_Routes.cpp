#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<pair<int,int>>> adj;
vector<int> cnt;

void Dijkstra(int n, int k) {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    pq.push({0, 1});

    vector<ll> ans;

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        cnt[u]++;

        if(cnt[u] > k) continue;

        if(u == n) {
            ans.push_back(d);
            if(ans.size() == k) break;
        }

        for(auto [v, w] : adj[u]) {
            pq.push({d + w, v});
        }
    }

    for(auto x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    adj.assign(n + 1, {});
    cnt.assign(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    Dijkstra(n, k);
}