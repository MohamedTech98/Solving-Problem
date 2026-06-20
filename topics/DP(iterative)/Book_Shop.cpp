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
    vector<int> price(n);
    vector<int> pages(n);
    for(int i = 0;i<n;i++) {
        cin>>price[i];
    }
    for(int i = 0;i<n;i++) {
        cin>>pages[i];
    }
    vector<vector<int>> dp(2,vector<int>(x + 1,-1e9));
    for(int i = 0;i<=x;i++) {
        dp[n & 1][i] = 0;
    }
    for(int i = n - 1;i >= 0;i--) {
        for(int rem = 0;rem <= x;rem++) {
            int take = -1e9;
            if(rem - price[i] >= 0) {
                take = dp[(i + 1) & 1][rem - price[i]] + pages[i];
            }
            int leave = dp[(i + 1) & 1][rem];
            dp[i & 1][rem] = max(take,leave);
        }
    }
    cout<< dp[0][x] << endl;
    return 0;
}