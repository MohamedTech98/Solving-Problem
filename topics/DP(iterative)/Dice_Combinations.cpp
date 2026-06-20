#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>


#define ll long long
#define endl '\n'
#define all(x) weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 2;
int dp[N];

int main() {
    ana_Yano;
    int n; cin>>n;
    dp[0] = 1; // base case
    for(int i = 1;i<=n;i++) {
        for(int num = 1;num<7;num++) {
            if(i - num >= 0)
                dp[i] = (dp[i] % mod) + (dp[i - num] % mod);
                dp[i] %= mod;
        }
    }
    cout<< dp[n] << endl;
    return 0;
}