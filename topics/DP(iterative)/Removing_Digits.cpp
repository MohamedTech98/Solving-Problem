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
const int N = 1e6 + 2;
// int dp[N];
// int calc(int n) {
//     if(n == 0) {
//         return 0;
//     }
//     if(~ dp[n]) {
//         return dp[n];
//     }
//     string dig = to_string(n);
//     int max_dig = 0;

//     for(int i = 0;i<dig.size();i++) {
//         max_dig = max(max_dig,dig[i] - '0');
//     }
//     return calc(n - max_dig) + 1;
// }

int main() {
    ana_Yano;
    int n; cin>>n;
    vector<int> dp(n + 1,1e9);
    dp[0] = 0; // base case
    // int number = n;
    for(int i = 1;i<=n;i++) {
        int number = i;
        string dig = to_string(number);
        for(int j = 0;j<dig.size();j++) {
            dp[i] = min(dp[i],(dp[i - (dig[j] - '0')]) + 1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}