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
    int n,f; cin>>n>>f;
    vector<pair<int,int>> day(n);
    ll ans = 0;
    // first: products , second: clients
    for(int i = 0;i < n;i++) {
        cin>>day[i].first>>day[i].second;
        ans += min(day[i].first,day[i].second);
    }
    vector<int> needed(n,0);
    for(int i = 0;i < n;i++) {
        if(day[i].second > day[i].first) {
            needed[i] = min(day[i].second,(2 * day[i].first)) - day[i].first;
        }
    }
    sort(needed.begin(),needed.end(),greater<int>());
    for(int i = 0;f != 0;i++) {
        // cout << needed[i] << endl;
        ans += needed[i];
        f--;
    }
    cout << ans << endl;
    return 0;
}