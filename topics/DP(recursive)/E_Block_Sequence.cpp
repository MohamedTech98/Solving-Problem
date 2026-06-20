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

int n;
vector<int> nums;
const int N = 2e5 + 1;

int dp[N];

int go(int i) {

    if(i >= n) {
        return 0;
    }

    if(~ dp[i]) {
        return dp[i];
    }
    int take = 1e9,leave = 1e9;
    if(i + nums[i] + 1<= n) {
        take = go(i + nums[i] + 1);
    }
    leave = go(i + 1) + 1;

    return dp[i] = min(leave,take);
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        cin>>n;
        nums.assign(n,0);
        for(int &val : nums) {
            cin>>val;
        }
        memset(dp,-1,sizeof dp);
        cout<<go(0)<<endl;
    }
    return 0;
}