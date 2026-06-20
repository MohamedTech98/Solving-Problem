#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        int mx = p[i];
        int pos = -1;

        // نجيب أكبر عنصر بعد i
        for (int j = i + 1; j < n; j++) {
            if (p[j] > mx) {
                mx = p[j];
                pos = j;
            }
        }

        // لو لقينا عنصر أكبر
        if (pos != -1) {
            reverse(p.begin() + i, p.begin() + pos + 1);
            break; // عملية واحدة بس
        }
    }

    // نطبع المصفوفة
    for (int x : p) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}
