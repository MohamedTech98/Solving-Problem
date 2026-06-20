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
    DSU(int n) {
        parent.assign(n + 1,-1);
    }
    int find(int node) {
        if(parent[node] < 0) return node;
        return parent[node] = find(parent[node]);
    }
    bool join(int big,int small) {
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
        return true;
    }
};


int main() {
    ana_Yano;
    int t; cin>>t;
    int test = 0;
    while(t--) {
        test++;
        string s; cin>>s;
        int n = s.size();
        vector<int> update_test;
        int q; cin>>q;
        stack<pair<int,int>> query;
        vector<int> removed(n,0);
        // int last = 0;
        while(q--) {
            int type,node; cin>>type>>node;
            query.emplace(make_pair(type,node));
            if(type == 2) {
                removed[node] = 1;
            } else {
                update_test.push_back(test);
            }
        }
        // build
        DSU dsu(n);
        for(int i = 1;i < n;i++) {
            if(removed[i] != 0 || removed[i - 1] != 0) {
                continue;
            }
            if(s[i] == s[i - 1]) {
                dsu.join(i,i-1);
            }
        }
        stack<int> ans;
        while(! query.empty()) {
            int type = query.top().first;
            int ind = query.top().second;
            query.pop();
            if(type == 1) {
                ans.emplace(-dsu.parent[dsu.find(ind)]);
            } else {
                removed[ind] = 0;
                if(ind - 1 >= 0 && removed[ind - 1] == 0 &&s[ind - 1] == s[ind]) {
                    dsu.join(ind,ind - 1);
                }
                if(ind + 1 < n && s[ind + 1] == s[ind]  && removed[ind + 1] == 0) {
                    dsu.join(ind,ind + 1);
                }
            }
        }
        int i = 0;
        int cur_test = -1;
        while(! ans.empty()) {
            if(cur_test != update_test[i]) {
                cur_test = update_test[i];
                cout <<"Case "<< cur_test <<':'<< endl;
            }
            cout << ans.top() << endl;
            ans.pop();
            i++;
        }
    }
    return 0;
}