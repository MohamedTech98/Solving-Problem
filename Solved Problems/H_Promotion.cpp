#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n,q; cin>>n>>q;
    vector<ll> pre(n+1,0);
    for(int i = 1;i<=n;i++) {
        cin>>pre[i];
    }
    sort(pre.begin(),pre.end());
    for(int i = 1;i<=n;i++) {
        pre[i] = pre[i] + pre[i-1];
    }
    int l,r;
    while(q--) {
        int x,y; cin>>x>>y;
        l = n - x + 1;
        r = l + y - 1;
        // cout<<pre[r]<<" "<<pre[l - 1]<<endl;
        cout<<pre[r] - pre[l - 1]<<endl;
    }
    return 0;
}