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
    int n,m; cin>>n>>m;
    vector<int> nums(n);
    for(int &val : nums) {
        cin>>val;
    }
    vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
    if(nums[0] != 0) {
        dp[0][nums[0]] = 1;
    } else {
        for(int i = 1;i<=m;i++) {
            dp[0][i] = 1;
        }
    }
    for(int i = 1;i<n;i++) {
        if(nums[i] != 0) {
            int j = nums[i];
            dp[i][j] = (j - 1 >= 1 ? dp[i - 1][j - 1] : 0) % mod;
            dp[i][j] %= mod;
            dp[i][j] += dp[i - 1][j] % mod; 
            dp[i][j] %= mod;
            dp[i][j] += (j + 1 <= m ? dp[i - 1][j + 1] : 0) % mod;
            dp[i][j] %= mod;
        } else {
            for(int j = 1;j <= m;j++) {
                dp[i][j] = (j - 1 >= 0 ? dp[i - 1][j - 1] : 0) % mod;
                dp[i][j] %= mod;
                dp[i][j] += dp[i - 1][j] % mod; 
                dp[i][j] %= mod;
                dp[i][j] += (j + 1 <=m ? dp[i - 1][j + 1] : 0) % mod;
                dp[i][j] %= mod;
            }
        }
    }

    ll ans = 0;
    for(int j=1;j<=m;j++) {
        ans = (ans + dp[n-1][j]) % mod;
        ans %= mod;
    }
    cout<< ans << endl;
    return 0;
}