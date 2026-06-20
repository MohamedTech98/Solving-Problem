#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)

const int mod = 1e9 + 7;

int main() {
    ana_Yano;

    int n; cin>>n;

    vector<string> grid(n);

    for(int i = 0;i<n;i++) {
        cin>>grid[i];
    }

    vector<vector<int>> dp(2,vector<int>(n,0));

    if(grid[n-1][n-1] == '.') {
        dp[(n-1)&1][n-1] = 1;
    }

    for(int i = n-1;i>=0;i--) {
        for(int j = n-1;j>=0;j--) {

            if(grid[i][j] == '*') {
                dp[i&1][j] = 0;
                continue;
            }

            if(i == n-1 && j == n-1) continue;

            ll down = (i+1 < n ? dp[(i+1)&1][j] : 0);
            ll right = (j+1 < n ? dp[i&1][j+1] : 0);

            dp[i&1][j] = (down + right) % mod;
        }
    }

    cout<<dp[0][0]<<endl;

    return 0;
}