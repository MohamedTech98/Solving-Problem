#include<bits\stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std; 

int main() {
    int n; cin>>n;
    ll ans = 0 ;
    while(n--) {
        int time,len;
        cin>>time>>len;
        if(ans == 0) {
            ans+=time+len;
        }
        else if(ans>=time) {
            ans+=len;
        }
        else if(time>ans) {
            ans = time + len;
        }
        // cout<<ans<<"****\n";
    }
    cout<<ans;
    return 0;
}