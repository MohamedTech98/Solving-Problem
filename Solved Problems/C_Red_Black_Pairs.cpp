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

// int n;
// const int N = 2e5 + 2
// int dp[2][N][2];
// ll calc(int x,int y,int pre) {

//     if(x == 1 && y == n-1) {
//         return 0;
//     }

//     if(~ dp[x][y][pre]) {
//         return dp[x][y][pre];
//     }
//     ll repaint = 1e9,leave = 1e9;

//     if(x + 1 < 2) {
//         repaint = calc(x + 1,y,!pre) + 1;
//         leave = calc(x + 1,y,pre);
//     }
//     if(y + 1 < n) {
//         repaint = calc(x + 1,y,!pre) + 1;
//         leave = calc(x + 1,y,pre);
//     }

//     return dp[x][y][pre] = min(repaint,leave);
// }

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        int n;
        cin >> n;

        string a,b;
        cin >> a >> b;

        vector<int> dp(n+1,1e9);
        dp[0] = 0;

        for(int i=0;i<n;i++){

            int cost = (a[i] != b[i]);
            dp[i+1] = min(dp[i+1], dp[i] + cost);

            if(i+1 < n){
                int cost2 = (a[i] != a[i+1]) + (b[i] != b[i+1]);
                dp[i+2] = min(dp[i+2], dp[i] + cost2);
            }
        }

        cout << dp[n] << endl;
    }
    return 0;
}