#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;

        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            vector<pair<double,int>> events;

            for(int j = i + 1; j < n; j++) {
                double mid = (a[i] + a[j]) / 2.0;

                if(a[j] > a[i]) {
                    events.push_back({mid, 1}); // RIGHT
                } else if(a[j] < a[i]) {
                    events.push_back({mid, 0}); // LEFT
                }
            }

            sort(events.begin(), events.end());

            int cur = 0;
            for(auto &e : events) {
                if(e.second == 0) cur++;
            }

            int best = cur;

            for(auto &e : events) {
                if(e.second == 0) cur--;
                else cur++;
                best = max(best, cur);
            }

            ans[i] = best;
        }

        for(int x : ans) cout << x << " ";
        cout << '\n';
    }

    return 0;
}