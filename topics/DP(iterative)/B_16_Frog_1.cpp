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
    int n; cin>>n;
    vector<int> dp(n + 1,0);
    vector<int> heights(n,0);
    for(int &val : heights) {
        cin>>val;
    }

    // int res = 1e9;
    for(int i = n - 2;i >= 0;i--) {
        int ch1 = 1e9,ch2 = 1e9;
        if(i + 1 < n) {
            ch1 = dp[i + 1] + abs(heights[i] - heights[i + 1]);
        }
        if(i + 2 < n) {
            ch2 = dp[i + 2] + abs(heights[i] - heights[i + 2]);
        }
        dp[i] = min(ch1,ch2);
    }
    cout<<dp[0]<<endl;
    return 0;
}