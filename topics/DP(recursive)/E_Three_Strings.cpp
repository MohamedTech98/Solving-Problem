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

string a,b,c;
const int N = 1001;
int dp[N][N];

int calc(int i,int j) {

    if(i >= a.size() && j >= b.size()) {
        return 0;
    }
    if(~ dp[i][j]) {
        return dp[i][j];
    }
    int ch1 = 1e9,ch2 = 1e9;
    if(i < a.size()) {
        ch1 = calc(i + 1,j) + (a[i] != c[i + j]);
    }

    if(j < b.size()) {
        ch2 = calc(i,j + 1) + (b[j] != c[i + j]);
    }

    return dp[i][j] = min(ch1,ch2);
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        memset(dp,-1,sizeof dp);
        cout<<calc(0,0)<<endl;
    }
    return 0;
}