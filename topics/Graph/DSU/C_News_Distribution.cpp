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
    ana_Yano;
    int n,m; cin>>n>>m;
    DSU dsu(n);
    for(int i = 0;i < m;i++) {
        int n_users; cin>>n_users;
        vector<int> group(n_users);
        int ii = 0;
        while(n_users--) {
            int user; cin>>user;
            group[ii++] = user;
        }
        for(int j = 1;j < group.size();j++) {
            // cout << group[j] << '-' << group[j - 1] << endl;
            dsu.join(group[j],group[j - 1]);
        }
    }
    for(int i  = 1;i <= n;i++) {
        cout << -dsu.parent[dsu.find(i)] << " ";
    }
    return 0;
}