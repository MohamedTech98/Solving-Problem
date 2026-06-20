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

int n,need_o2,need_n2;
vector<int> weights;
vector<int> o2;
vector<int> n2;

const int N = 1001,O2 = 21 * 2,N2 = 79 * 2;

ll dp[N][O2][N2];

ll calc(int i,int count_o,int count_n) {

    if(count_o >= need_o2 && count_n >= need_n2) {
        return 0;
    }
    if(i >= n) {
        return 1e9;
    }

    int new_o = min(count_o + o2[i],need_o2);
    int new_n = min(count_n + n2[i],need_n2);
    if(~ dp[i][count_o][count_n]) {
        return dp[i][count_o][count_n];
    }

    ll take = calc(i + 1,new_o,new_n) + weights[i];
    ll leave = calc(i + 1,count_o,count_n);

    return dp[i][count_o][count_n] = min(take,leave);
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        cin>>need_o2>>need_n2>>n;
        weights.assign(n,0);
        o2.assign(n,0);
        n2.assign(n,0);

        memset(dp,-1,sizeof dp);

        for(int i = 0;i<n;i++) {
            cin>>o2[i]>>n2[i]>>weights[i];
        }
        cout<<calc(0,0,0)<<endl;
    }
    return 0;
}