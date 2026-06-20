#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> x(n), r(n);

        for (int &i : x) cin >> i;
        for (int &i : r) cin >> i;

        map<int,int> mx;

        for (int i = 0; i < n; i++) {

            for (int curX = x[i] - r[i]; curX <= x[i] + r[i]; curX++) {

                ll d = curX - x[i];

                ll y = sqrt(1LL * r[i] * r[i] - d * d);

                mx[curX] = max(mx[curX], (int)y);
            }
        }

        long long ans = 0;

        for (auto [X, y] : mx) {
            ans += 2LL * y + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}