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

int n;
vector<ll> points;
const int N = 2e5 + 2;
ll dp[N][2];
ll monsters(int i,bool flag) {

    if(i >= n) {
        return 0;
    }
    if(~ dp[i][flag]) {
        return dp[i][flag];
    }
    ll res = 0;
    if(flag != 0) {
        res =  monsters(i + 1,!flag) + (2 * points[i]);
    }

    ll defeat = monsters(i + 1,!flag) + points[i];
    ll go = monsters(i + 1,flag);
    return dp[i][flag] = max({defeat,go,res});
}

int main() {
    ana_Yano;
    cin>>n;
    points.resize(n);
    for(ll &val:points) {
        cin>>val;
    }
    memset(dp,-1,sizeof dp);
    cout << monsters(0,0)<< endl;
    return 0;
}