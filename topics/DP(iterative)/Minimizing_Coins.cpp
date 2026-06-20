#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)

int main() {
    ana_Yano;

    int n,x; 
    cin>>n>>x;

    vector<int> coins(n);
    for(int &val:coins)
        cin>>val;

    vector<vector<int>> dp(n + 1,vector<int>(x + 1,1e9));

    dp[n][0] = 0;

    for(int i = n - 1;i>= 0;i--) {
        for(int rem = 0;rem <= x;rem++) {

            int res = dp[i + 1][rem];

            if(rem - coins[i] >= 0) {
                res = min(res,
                dp[i][rem - coins[i]] + 1);
            }

            dp[i][rem] = res;
        }
    }

    cout<< (dp[0][x] == 1e9 ? -1 : dp[0][x]) << endl;
}