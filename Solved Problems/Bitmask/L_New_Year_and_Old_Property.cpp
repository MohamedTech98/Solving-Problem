#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all nums.begin(),nums.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ll a,b; cin>>a>>b;
    ll ans = 0;
    ll num = b;
    while(num!=0) {
        ll ind = 0;
        for(ll bit = 0;bit<64;bit++) {
            if((num>>bit & 1)==1) {
                ind  = bit;
            }
        }
        for(ll bit = 0;bit<ind;bit++) {
            if((num>>bit & 1)==0) {
                num |=(1ll<<bit);
            }
        }
        for(ll bit = 0;bit<ind;bit++) {
            if(num - (1ll<<bit) >= a&&num - (1ll<<bit)<=b) {
                ans++;
            }
        }
        num -= (1ll<<ind);
    }
    cout<<ans<<endl;
}