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
    int n,W; cin>>n>>W;
    vector<vector<ll>> dp(2,vector<ll>(W + 1,0));
    // vector<ll> oldDP(W + 1,0);
    vector<int> weights(n);
    vector<ll> values(n);
    for(int i = 0;i<n;i++) {
        cin>>weights[i]>>values[i];
    }
    for(int i = n - 1;i>=0;i--) {
        // vector<ll> newDP(W + 1);
        for(int rem = 0;rem <= W;rem++) {
            ll take = -1;
            if(rem - weights[i] >= 0)
                {take = dp[(i + 1) & 1][rem - weights[i]] + values[i];}
            ll leave = dp[(i + 1) & 1][rem];
            dp[i & 1][rem] = max(take,leave);
        }
        
    }
    cout<< dp[0][W] << endl;
    return 0;
}