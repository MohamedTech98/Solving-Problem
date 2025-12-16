#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define ana_Yano ios::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int n, l, r, x;
vector<int> problems;
int ans = 0;

void contest(int idx, ll sum, int max_val, int min_val, int cnt) {
    if (cnt >= 2 && sum >= l && sum <= r && max_val - min_val >= x) {
        ans++;
    }

    for (int i = idx; i < n; i++) {
        if (sum + problems[i] > r) continue;

        contest(
            i + 1,
            sum + problems[i],
            max(max_val, problems[i]),
            min(min_val, problems[i]),
            cnt + 1
        );
    }
}

int main() {
    ana_Yano;
    cin >> n >> l >> r >> x;

    problems.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> problems[i];
    }

    contest(0, 0, -1, 1e9, 0);
    cout << ans << endl;

    return 0;
}
