#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int,ll> X, Y;
    map<pair<int,int>, ll> same;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        X[x]++;
        Y[y]++;
        same[{x,y}]++;
    }

    ll ans = 0;

    for(auto it : X) {
        ll cnt = it.second;
        ans += cnt * (cnt - 1) / 2;
    }

    for(auto it : Y) {
        ll cnt = it.second;
        ans += cnt * (cnt - 1) / 2;
    }

    // remove duplicates counted twice
    for(auto it : same) {
        ll cnt = it.second;
        ans -= cnt * (cnt - 1) / 2;
    }

    cout << ans << '\n';
}