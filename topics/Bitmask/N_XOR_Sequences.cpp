#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all nums.begin(),nums.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        int x,y; cin>>x>>y;
        int ans = 0;
        for(int bit = 0;bit<32;bit++) {
            if((x>>bit & 1) != (y>>bit & 1)) {
                ans = 1<<bit;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}