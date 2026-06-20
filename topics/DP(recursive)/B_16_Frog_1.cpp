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
int n;
int go(int i) {
    
    if(i == n - 1) {
        return 0;
    }
    int ch1 = 1e9,ch2 = 1e9;
    if(dp[i] != -1) {
        return dp[i];
    }
    if(i + 1 < n) {
        ch1 = go(i + 1) + abs(heights[i] - heights[i + 1]);
    }
    if(i + 2 < n) {
        ch2 = go(i + 2) + abs(heights[i] - heights[i + 2]);
    }
    return dp[i] = min(ch1,ch2);
}

int main() {
    ana_Yano;
    cin>>n;
    heights.resize(n);
    for(int i = 0;i<n;i++) {
        cin>>heights[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<go(0);
    return 0;
}