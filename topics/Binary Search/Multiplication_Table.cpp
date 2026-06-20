#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll countLessEqual(int n, ll mid) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += min((ll)n, mid / i);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll l = 1, r = 1LL * n * n;
    ll target = (1LL * n * n + 1) / 2;
    ll ans = 0;

    while (l <= r) {
        ll mid = l + (r - l) / 2;

        if (countLessEqual(n, mid) >= target) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}