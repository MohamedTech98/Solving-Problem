#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    int ncomp;
    DSU(int n) {
        ncomp = n;
        parent.assign(n + 1,-1);
    }
    int find(int x) {
        if(parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }
    bool join(int big,int small) {
        int u = big,v = small;
        big = find(big);
        small = find(small);
        if(big == small) {
            return false;
        }
        if(-parent[big] < -parent[small]) {
            swap(big,small);
        }
        parent[big] += parent[small];
        parent[small] = big;
        ncomp--;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> p(n);
    unordered_map<int,int> id;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        id[p[i]] = i;
    }

    DSU dsu(n);

    // نبني القيود
    for (int i = 0; i < n; i++) {
        int x = p[i];

        if (id.count(a - x)) {
            dsu.join(i, id[a - x]);
        }
        if (id.count(b - x)) {
            dsu.join(i, id[b - x]);
        }
    }

    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
        int root = dsu.find(i);

        if (color[root] == -1) {
            // نختار A = 0, B = 1
            if (id.count(a - p[i]))
                color[root] = 0;
            else
                color[root] = 1;
        }

        color[i] = color[root];
    }

    // تحقق
    for (int i = 0; i < n; i++) {
        int x = p[i];

        if (color[i] == 0) { // A
            if (!id.count(a - x)) {
                cout << "NO\n";
                return 0;
            }
        } else { // B
            if (!id.count(b - x)) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";

    return 0;
}