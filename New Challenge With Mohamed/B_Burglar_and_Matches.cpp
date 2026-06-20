#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;


int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    vector<int> matches(11,0);
    ll ans = 0;
    for(int i = 0;i<m;i++) {
        int ind,time;
        cin>>time>>ind;
        matches[ind] += time;
    }
    int p = 10;
    while(n>0&&p>0) {
        if(matches[p]!=0) {
            int choose = min(matches[p],n);
            ans += choose * p;
            n -=choose;
        }
        p--;
    }
    cout<<ans;
    return 0;
}