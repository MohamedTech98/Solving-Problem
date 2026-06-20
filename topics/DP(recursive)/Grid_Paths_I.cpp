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
vector<string> grid;
const int N = 1001,mod = 1e9 + 7;
ll dp[N][N];

ll go(int i,int j) {
    
    if(i == n - 1 && j == n - 1) {
        return 1;
    }
    ll ch1 = 0,ch2 = 0;
    if(~ dp[i][j]) {
        return dp[i][j];
    }
    if(i + 1 < n && grid[i + 1][j] != '*') {
        ch1 = go(i + 1,j); // down
    }
    if(j + 1 < n && grid[i][j + 1] != '*') {
        ch2 = go(i,j + 1); // right
    }
    return dp[i][j] = (ch1 + ch2) % mod;
}


int main() {
    ana_Yano;
    cin>>n;
    grid.resize(n);
    for(int i = 0;i<n;i++) {
        cin>>grid[i];
    }
    if(grid[0][0] == '*') {
        cout<<0<<endl;
        return 0;
    }
    memset(dp,-1,sizeof dp);
    cout<<go(0,0)<<endl;
    return 0;
}