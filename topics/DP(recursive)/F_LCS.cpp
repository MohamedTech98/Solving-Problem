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
string s,t;

const int N = 3001;

int dp[N][N];

int go(int i,int j) {
    
    if(i >= s.size() || j >= t.size()) {
        return 0;
    }

    int ch1 = 0,ch2 = 0,ch3 = 0;
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(s[i]==t[j]) {
        ch1 = go(i + 1,j + 1) + 1;
    }
    ch2 = go(i + 1,j);
    ch3 = go(i,j + 1);
    return dp[i][j] = max({ch1,ch2,ch3});
}

string res;

void build(int i,int j) {
    if(i>=s.size() || j >= t.size()) {
        return;
    }

    int ch1 = 0,ch2 = 0;

    if(s[i] == t[j]) {
        res += s[i];
        return build(i + 1,j + 1);
    }

    ch1 = go(i + 1,j);
    ch2 = go(i,j + 1);
    
    if(ch1 > ch2) {
        build(i + 1,j);
    } else {
        build(i,j + 1);
    }
}

int main() {
    ana_Yano;
    cin>>s>>t;
    memset(dp,-1,sizeof dp);
    build(0,0);
    cout<<res<<endl;
    return 0;
}