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

map<ll,ll> computed,visited;


ll calc(ll coin) {
    if(coin == 2 ||coin == 1) {
        return coin;
    }


    if(visited[coin] != 0) {
        return computed[coin];
    }
    visited[coin] = 1;
    ll sum = 0;
    sum = calc(coin/2) + calc(coin/3) + calc(coin/4);
    return computed[coin] = max(sum,coin);
}

int main() {
    ana_Yano;
    // int t;
    // cin>>t;
    while(scanf("%lld",&n) != EOF) {
        // cin>>n;
        cout<<calc(n)<<endl;
    }
    return 0;
}