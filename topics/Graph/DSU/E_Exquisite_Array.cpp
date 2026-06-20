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
const int mod = 1e9 + 7;
struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.assign(n, -1);
    }

    int find(int x) {
        if (parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }

    ll join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return 0;

        if (-parent[a] < -parent[b]) swap(a, b);

        ll res = 1LL * (-parent[a]) * (-parent[b]);

        parent[a] += parent[b];
        parent[b] = a;

        return res;
    }
};

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        // edges: (difference, index)
        vector<pair<int,int>> edges;
        for (int i = 0; i < n - 1; i++) {
            int d = abs(p[i] - p[i + 1]);
            edges.push_back({d, i});
        }

        // sort descending
        sort(edges.rbegin(), edges.rend());

        DSU dsu(n);

        vector<ll> ans(n, 0);

        ll cur = 0;
        int j = 0;

        for (int k = n - 1; k >= 1; k--) {

            while (j < edges.size() && edges[j].first >= k) {
                int i = edges[j].second;
                cur += dsu.join(i, i + 1);
                j++;
            }

            ans[k] = cur;
        }

        for (int k = 1; k <= n - 1; k++) {
            cout << ans[k] << " ";
        }
        cout << "\n";
    }
    return 0;
}