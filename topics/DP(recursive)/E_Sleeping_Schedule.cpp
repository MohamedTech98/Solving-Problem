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

int n,h,l,r;
vector<int> hours;

const int N = 2001;

int dp[N][N];

int sleep(int i,int t) {

    if(i >= n) {
        return 0;
    }

    if(~ dp[i][t]) {
        return dp[i][t];
    }
    int t1 = (t + (hours[i] - 1)) % h;
    int t2 = (t + (hours[i])) % h;

    int ch1 = sleep(i + 1,t1) +  (t1 >= l && t1 <= r);
    int ch2 = sleep(i + 1,t2) + ( t2 >= l && t2 <= r);

    return dp[i][t] = max(ch1,ch2);
}

int main() {
    ana_Yano;
    cin>>n>>h>>l>>r;
    hours.resize(n);
    for(int &val : hours) {
        cin>>val;
    }
    memset(dp,-1,sizeof dp);
    cout<<sleep(0,0)<<endl;
    return 0;
}