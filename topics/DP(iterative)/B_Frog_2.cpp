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
    int n,k; cin>>n>>k;
    vector<int> dp(n + 1,0);
    vector<int> heights(n,0);
    for(int &val : heights) {
        cin>>val;
    }

    // int res = 1e9;
    for(int i = n - 2;i >= 0;i--) {
        int res = 1e9;
        for(int j = 1;j<=k;j++) {
            if(i + j < n) {
                res = min(res,dp[i + j] + abs(heights[i] - heights[i + j]));
            }
        }
        dp[i] = res;
    }
    cout<<dp[0]<<endl;
    return 0;
}