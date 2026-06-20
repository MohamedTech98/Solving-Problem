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

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        ll x,y; cin>>x>>y;
        if(y / x <= 2) {
            cout<< "NO" <<endl;
        } else {
            cout<< "YES" << endl;
        }
    }
    return 0;
}