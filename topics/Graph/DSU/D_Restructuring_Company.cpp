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
    vector<int> nxt;
    int ncomp;
    DSU(int n) {
        ncomp = n;
        parent.assign(n + 1,-1);
        nxt.assign(n + 2,0);
        for(int i = 1; i <= n; i++) nxt[i] = i;
    }
    int get_next(int x) {
        if(nxt[x] == x) return x;
        return nxt[x] = get_next(nxt[x]);
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
    ana_Yano;
    int n,q; cin>>n>>q;
    DSU dsu(n);
    vector<int> vec(n + 1,0);
    while(q--) {
        int type,u,v; cin>>type>>u>>v;
        if(type == 3) {
            if(dsu.find(u) == dsu.find(v)) {
                cout << "YES" <<endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else if(type == 2) {
            int i = dsu.get_next(u);
            while(i < v) {
                dsu.join(i, i + 1);
                dsu.nxt[i] = i + 1; // remove it
                i = dsu.get_next(i);
            }
            vec[u] = max(vec[u],u - v);
        } else {
            dsu.join(u,v);
        }
    }
    return 0;
}