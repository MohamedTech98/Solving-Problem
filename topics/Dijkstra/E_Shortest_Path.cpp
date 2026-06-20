#include <bits/stdc++.h>
using namespace std;

#define ana_Yano ios::sync_with_stdio(false), cin.tie(nullptr)

int n, m, k;

vector<vector<int>> adj;
vector<vector<int>> vis;
set<tuple<int,int,int>> forbiden;

vector<vector<pair<int,int>>> parent;

int main() {
    ana_Yano;

    cin >> n >> m >> k;

    adj.assign(n + 1, {});
    vis.assign(n + 1, vector<int>(n + 1, 0));
    parent.assign(n + 1, vector<pair<int,int>>(n + 1, {-1, -1}));

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        forbiden.insert({a, b, c});
    }

    queue<pair<int,int>> q;

    // (prev, cur)
    q.push({0, 1});
    vis[0][1] = 1;

    pair<int,int> last_state = {-1, -1};

    while(!q.empty()) {
        auto [par, u] = q.front();
        q.pop();

        if(u == n) {
            last_state = {par, u};
            break;
        }

        for(int v : adj[u]) {

            if(vis[u][v]) continue;

            if(forbiden.count({par, u, v})) continue;

            vis[u][v] = 1;
            parent[u][v] = {par, u};
            q.push({u, v});
        }
    }

    if(last_state.second == -1) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;

    int p = last_state.first;
    int c = last_state.second;

    while(!(p == 0 && c == 1)) {
        path.push_back(c);
        auto pr = parent[p][c];
        p = pr.first;
        c = pr.second;
    }

    path.push_back(1);
    reverse(path.begin(), path.end());

    cout << path.size() - 1 << "\n";
    for(int x : path) cout << x << " ";

    return 0;
}