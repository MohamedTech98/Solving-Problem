#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct State {
    ll dist;
    int node;
    int bike;

    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int,int>>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> s(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }

        const ll INF = 1e18;

        vector<vector<ll>> dist(
            n + 1,
            vector<ll>(1001, INF)
        );

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        dist[1][s[1]] = 0;

        pq.push({
            0,
            1,
            s[1]
        });

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            ll d = cur.dist;
            int u = cur.node;
            int bike = cur.bike;

            if (d != dist[u][bike])
                continue;

            for (auto &[v, w] : adj[u]) {

                int newBike =
                    min(bike, s[v]);

                ll nd =
                    d + 1LL * bike * w;

                if (nd < dist[v][newBike]) {

                    dist[v][newBike] = nd;

                    pq.push({
                        nd,
                        v,
                        newBike
                    });
                }
            }
        }

        ll answer = INF;

        for (int bike = 1; bike <= 1000; bike++) {
            answer = min(
                answer,
                dist[n][bike]
            );
        }

        cout << answer << '\n';
    }

    return 0;
}