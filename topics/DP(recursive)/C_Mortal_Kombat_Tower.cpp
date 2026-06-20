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
vector<int> monsters;
const int N = 2e5 + 2,who = 2;
int dp[N][who];
int game(int i,int role) {

    if(i >= n) {
        return 0;
    }
    if(~ dp[i][role]) {
        return dp[i][role];
    }
    int ch1 = 100,ch2 = 100;
    ch1 = game(i + 1,role ^ 1) + (role == 0?monsters[i]:0);
    if(i + 1 < n)
        ch2 = game(i + 2,role ^ 1) + (role == 0 ?monsters[i] + monsters[i + 1]:0);

    return dp[i][role] = min(ch1,ch2);
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        cin>>n;
        monsters.assign(n,0);
        for(int &val : monsters) {
            cin>>val;
        }
        memset(dp,-1,sizeof dp);
        cout<<game(0,0) << endl;
    }

    return 0;
}