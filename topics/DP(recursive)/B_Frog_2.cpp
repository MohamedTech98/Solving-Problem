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

const int N = 1e5 + 2;
int dp[N];
vector<int> heights;
int n,k;
int go(int i) {
    
    if(i == n - 1) {
        return 0;
    }
    int min_dis = 1e9;
    if(dp[i] != -1) {
        return dp[i];
    }
    for(int j = 1;j<=k;j++) {
        if(i + j < n) {
            int ch = go(i + j) + abs(heights[i] - heights[i + j]);
            min_dis = min(min_dis,ch);
        }
    }
    return dp[i] = min_dis;
}

int main() {
    ana_Yano;
    cin>>n>>k;
    heights.resize(n);
    for(int i = 0;i<n;i++) {
        cin>>heights[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<go(0);
    return 0;
}