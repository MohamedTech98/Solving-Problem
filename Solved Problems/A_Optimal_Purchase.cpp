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
        ll n,a,b; cin>>n>>a>>b;
        ll ans = 0;
        ans += (n / 3) * min(b, 3 * a);
        n %= 3;
        ans += min(b, 1ll * n * a);
        cout << ans << endl;
    }
    return 0;
}