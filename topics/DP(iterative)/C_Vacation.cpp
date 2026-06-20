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
    vector<vector<int>> points(n,vector<int>(3));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<3;j++) {
            cin>>points[i][j];
        }
    }
    vector<vector<int>> dp(n + 1,vector<int>(3,0));
    // base case 
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    for(int day = 1;day <n;day++) {
        dp[day][0] = max(dp[day - 1][1],dp[day - 1][2]) + points[day][0];
        dp[day][1] = max(dp[day - 1][0],dp[day - 1][2]) + points[day][1];
        dp[day][2] = max(dp[day - 1][1],dp[day - 1][0]) + points[day][2];
    }
    cout<< max({dp[n - 1][0],dp[n - 1][1],dp[n - 1][2]}) << endl;
    return 0;
}