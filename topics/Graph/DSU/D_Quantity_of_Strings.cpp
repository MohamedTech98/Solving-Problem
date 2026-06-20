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

int fast_power(int base,int power) {
    int res = 1;
    while(power > 1) {
        if(power % 2 == 0) {
            base *=base % mod;
            base %= mod;
            power /=2;
        } else {
            res *= base;
            power -= 1;
        }
    }
    res *= base % mod;
    res %= mod;
    return res;
}

int main() {
    ana_Yano;
    int n,m,k; cin>> n >> m >> k;
    DSU dsu(n);
    for(int i = 1;i + k - 1 <= n;i++) {
        int l = i,r = i + k - 1;
        while(l <= r) {
            dsu.join(l,r);
            l++;
            r--;
        }
    }
    cout << fast_power(m,dsu.ncomp) << endl;
    return 0;
}