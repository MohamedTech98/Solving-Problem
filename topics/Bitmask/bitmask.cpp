#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<int> convertbase(int n , int base) {
    vector<int> ans;
    while(n!=0) {
        ans.push_back(n % base); // 1%2 = 1 && 8%2 = 0
        n /= base;
    }
    return ans;
}

long long combination(int n, int r) {
    if (r > n) return 0;

    r = min(r, n - r);

    long long result = 1;

    for (int i = 1; i <= r; i++) {
        result = result * (n - r + i) / i;
    }

    return result;
}

int main() {
    ana_Yano;

    int n, r;

    while (cin >> n >> r) {
        if (n == 0 && r == 0)
            break;

        cout << n << " things taken "
             << r << " at a time is "
             << combination(n, r)
             << " exactly.\n";
    }

    return 0;
}
