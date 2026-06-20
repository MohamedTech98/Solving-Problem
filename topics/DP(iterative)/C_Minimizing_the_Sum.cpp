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
    int t; cin>>t;
    while(t--) {
        int n,k; cin>>n>>k;
        vector<int> nums(n);
        for(int &val : nums) {
            cin>>val;
        }
        vector<vector<int>> dp(n+1,vector<int>(k + 1,1e9));
        for(int i = 0;i<=k;i++) {
            dp[n][i] = 0;
        }
        for(int i = n - 1;i>=0;i--) {
            for(int rem = 0;rem <= k;rem++) {
                if(rem - 1 >= 0) {
                    int right = dp[i + 1][rem - 1] + (i + 1 < n ? nums[i + 1]:1e9);
                    int left = dp[i + 1][rem - 1] + (i - 1 >= 0? nums[i - 1]:1e9);
                    dp[i][rem] = min({dp[i + 1][rem - 1] + nums[i],right,left});
                }
            }
        }
        cout<< dp[0][k] << endl;
    }
    return 0;
}