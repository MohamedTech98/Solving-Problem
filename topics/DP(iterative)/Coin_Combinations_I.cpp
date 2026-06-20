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


int main() {
    ana_Yano;
    int n,x; cin>>n>>x;
    vector<int> coins(n);
    for(int &val: coins) {
        cin>>val;
    }
    vector<int> dp(x + 1,0);
    dp[0] = 1;
    for(int j = 0;j<n;j++) {
        for(int i = 1;i<=x;i++) {
            if(i - coins[j] >= 0) {
                dp[i] += (dp[i - coins[j]] % mod);
                dp[i] %= mod;
            }
        }
    }
    cout<< dp[x] << endl;
    return 0;
}