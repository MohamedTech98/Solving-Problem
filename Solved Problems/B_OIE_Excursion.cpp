#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sme=1,prev=a[0];
    for(int i=1;i<n;i++){
        if(a[i]==prev) sme++;
        else{
            sme=1;
            prev=a[i];
        }
        if(sme>=k){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}