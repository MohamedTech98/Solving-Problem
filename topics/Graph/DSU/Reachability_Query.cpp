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
    vector<int> color;
    vector<int> root_color;
    int ncomp;
    DSU(int n) {
        ncomp = n;
        parent.assign(n + 1,-1);
        color.assign(n + 1,0);
        root_color.assign(n + 1,0);
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
        root_color[big] += root_color[small];
        ncomp--;
        return true;
    }
    void set_color(int node) {
        root_color[find(node)] += (color[node] ^ 1 == 0?-1:1); 
        color[node] = color[node] ^ 1;
    }
};

int main() {
    ana_Yano;
    int n,q; cin>>n>>q;
    DSU dsu(n);
    while(q--) {
        int type,node; cin>>type>>node;
        if(type == 1) {
            int node2; cin>>node2;
            dsu.join(node2,node);
        } else if(type == 2) {
            dsu.set_color(node);
        } else {
            cout << (dsu.root_color[dsu.find(node)] > 0 ?"Yes":"No") << endl;
        }
    }
    return 0;
}