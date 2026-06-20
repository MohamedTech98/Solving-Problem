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

int main() {
    ana_Yano;
    int n; cin >> n;
    ll k; cin >> k;

    vector<vector<int>> up(n + 1,vector<int>(64,0));

    for(int node = 1;node <= n;node++) {
        cin >> up[node][0];
        // city(node) can move to city[0] 
    }
    // build answer

    for(int step = 1;step <= 64;step++) {
        for(int node = 1;node <= n;node++) {
            // new step : go to the city(pre) which you go to in previous step
            // and take the city that pre can move to it
            int pre_node = up[node][step - 1]; 
            // back to the city go to it in previous step
            int go_pre_node = up[pre_node][step - 1];
            up[node][step] = go_pre_node;
        }
    }
    int cur = 1; // start from 1
    for(int bit = 0;bit < 64;bit++) {
        if((k >> bit) & 1) {
            cur = up[cur][bit];
            // return 0;
        }
    }
    cout << cur << endl;
    return 0;
}