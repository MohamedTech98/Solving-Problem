#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.assign(n + 1, -1);
    }
    int find(int x) {
        if(parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }
    ll join(int a,int b) {
        a = find(a);
        b = find(b);
        if(a == b) return 0;

        if(-parent[a] < -parent[b])
            swap(a,b);

        ll res = 1LL * (-parent[a]) * (-parent[b]); // a * b

        parent[a] += parent[b];
        parent[b] = a;

        return res;
    }
};

int main() {
    ana_Yano;

    int n,q; cin>>n>>q;

    vector<array<int,3>> edge(n - 1);
    for(int i = 0;i < n - 1;i++) {
        cin>>edge[i][1]>>edge[i][2]>>edge[i][0]; // u v w
    }

    vector<pair<int,int>> queries(q); // {query, index}
    for(int i = 0;i < q;i++) {
        cin>>queries[i].first;
        queries[i].second = i;
    }

    sort(edge.begin(), edge.end());          // sort edges by weight
    sort(queries.begin(), queries.end());    // sort queries

    vector<ll> ans(q);
    DSU dsu(n);

    ll cur = 0;
    int j = 0;

    for(int i = 0;i < q;i++) {
        int val = queries[i].first;

        while(j < n-1 && edge[j][0] <= val) {
            cur += dsu.join(edge[j][1], edge[j][2]);
            j++;
        }

        ans[queries[i].second] = cur;
    }

    for(int i = 0;i < q;i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}