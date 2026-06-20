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
int n,target;
const int N = 2e5 + 7;
int dp[N][N / 2];
vector<int> nums;
int GCD(int x,int y) {
    if(x == 0) return y;
    if(y == 0) return x;
    return GCD(y,x % y);
}
int go(int i,int gcd) {
    if(i >= n) {
        return 0;
    }
    if(gcd == target) {
        return 1 + go(i + 1,GCD(gcd,nums[i])) +  go(i + 1,gcd);
    }
    int take = go(i + 1,GCD(gcd,nums[i]));
    int leave = go(i + 1,gcd);
    return take + leave;
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
        int min_val = 1e9,max_val = -1;
        for(int val : nums) {
            min_val = min(min_val,val);
            max_val = max(max_val,val);
        }
        target = max_val - min_val;
        sort(nums.begin(),nums.end());
        int ans = go(0,0);
        cout << ans << endl;
    }
    return 0;
}