#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> nums(n);

    ll l = 0, r = 0;

    for (auto &x : nums) {
        cin >> x;
        l = max(l, x);
        r += x;
    }

    auto can = [&](ll mx) {
        int seg = 1;
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= mx) {
                sum += nums[i];
            } else {
                seg++;
                sum = nums[i];
                if (seg > k) return false;
            }
        }
        return true;
    };

    ll ans = r;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}