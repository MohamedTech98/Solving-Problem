#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>


#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
const int mod = 1e9 + 7;
struct DSU {
    vector<int> parent;
    queue<pair<int,int>> remove;
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
            remove.emplace(make_pair(u,v));
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
    ana_Yano;
    int n; cin>>n;
    DSU dsu(n);
    for(int i = 0,u,v;i < n - 1;i++) {
        cin>>u>>v;
        dsu.join(u,v);
    }
    vector<array<int,4>> ans;
    while(dsu.ncomp > 1 && !dsu.remove.empty()) {
        auto cur = dsu.remove.front();
        dsu.remove.pop();
        for(int i = 1;i <= n;i++) {
            if(dsu.join(cur.first,i)) {
                ans.push_back({cur.first,cur.second,
                    (cur.first == dsu.find(cur.first)? cur.second : cur.first),i});
                break;
            }
        }
    }
    if(ans.size() > 0) {
        cout << ans.size() << endl;
        for(auto edge : ans) {
            for(int i = 0;i < 4;i++) {
                cout << edge[i] << " ";
            }
            cout << endl;
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}