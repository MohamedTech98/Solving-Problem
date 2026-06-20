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

ll GCD(ll i,ll j) {
    if(i == 0) {
        return j;
    }
    if(j == 0) {
        return i;
    }
    return GCD(j,i % j);
}

ll LCM(ll i,ll j) {
    return i * j / GCD(i,j);
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        ll a,b,c,m; cin>>a>>b>>c>>m;
        ll a_only = m / a;
        ll b_only = m / b;
        ll c_only = m / c;
        ll AandB = m / LCM(a,b);
        ll Aandc = m / LCM(a,c);
        ll candb = m / LCM(b,c);
        ll three = m / LCM(LCM(a,b),c);
        a_only -= three;
        b_only -= three;
        c_only -= three;
        a_only -=  AandB + Aandc - three;
        b_only -=  AandB + candb - three;
        c_only -=  Aandc + candb - three; 
        ll a_ans = (three * 2) + ((AandB + Aandc) * 3) + (a_only * 6);
        ll b_ans = (three * 2) + ((AandB + candb) * 3) + (b_only * 6);
        ll c_ans = (three * 2) + ((candb + Aandc) * 3) + (c_only * 6);
        cout<<a_ans<<" "<<b_ans<<" "<<c_ans<<endl;
    }
    return 0;
}