#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)

const int mod = 1e9 + 7;

int main() {
    ana_Yano;

    int h,w; 
    cin>>h>>w;

    vector<string> grid(h);

    for(int i = 0;i<h;i++) {
        cin>>grid[i];
    }

    vector<vector<int>> dp(2,vector<int>(w,0));

    if(grid[h-1][w-1] == '.') {
        dp[(h-1)&1][w-1] = 1;
    }

    for(int i = h-1;i>=0;i--) {
        for(int j = w-1;j>=0;j--) {

            if(grid[i][j] == '#') {
                dp[i&1][j] = 0;
                continue;
            }

            if(i == h-1 && j == w-1) continue;

            ll down = (i+1 < h ? dp[(i+1)&1][j] : 0);
            ll right = (j+1 < w ? dp[i&1][j+1] : 0);

            dp[i&1][j] = (down + right) % mod;
        }
    }

    cout<<dp[0][0]<<endl;

    return 0;
}