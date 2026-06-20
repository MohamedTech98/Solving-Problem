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

int n,max_val = -1000;
const int N = 1e5 + 2;
vector<ll> fre(N,0);
ll dp[N];
ll go(int i) {
    if(i > max_val ) {
        return 0;
    }

    if(~ dp[i]) {
        return dp[i];
    }

    ll ch1 = go(i + 2) + (fre[i] * i);
    ll ch2 = go(i + 1);

    return dp[i] = max(ch1,ch2);
}

int main() {
    ana_Yano;
    cin>>n;
    for(int i = 0,val;i<n;i++) {
        cin>>val;
        max_val = max(max_val,val);
        fre[val]++;
    }
    memset(dp,-1,sizeof dp);
    cout<<go(1)<<endl;
    return 0;
}