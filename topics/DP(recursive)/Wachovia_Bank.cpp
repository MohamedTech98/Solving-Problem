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

vector<int> weights;
vector<int> values;
int W,M;
const int N = 51,C = 1e4 + 7,mod = 1e9 + 7;
int dp[N][C];
int calc(int i,int carry) {
    
    if(carry > W) {
        return -1e9;
    }

    if(i >= M) {
        return 0;
    }

    if(~ dp[i][carry]) {
        return dp[i][carry];
    }
    int ch1 = 0,ch2 = 0;
    ch1 = calc(i + 1,carry + weights[i]) + values[i];
    ch2 = calc(i + 1,carry);
    return dp[i][carry] = max(ch1,ch2);
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        cin>>W>>M;
        weights.assign(M,0);
        values.assign(M,0);
        memset(dp,-1,sizeof dp);
        for(int  i = 0;i<M;i++) {
            cin>>weights[i]>>values[i];
        }
        cout<<"Hey stupid robber, you can get "<<calc(0,0)<<"."<<endl;
    }
    return 0;
}