#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        ll c, f;
        cin >> n >> c >> f;
        vector<ll> power(n);
        for (int i = 0; i < n; i++) {
            cin >> power[i];
        }
        sort(power.begin(), power.end());
        for(int i = 0;i<n;i++) {
            if(power[i] <= c) {
                // cout<<c<<" "<<power[i]<<" "<<f<<endl;
                int need = min(c - power[i],f);
                power[i] = power[i] + need;
                f -= need;
                c += power[i];
            }
        }
        cout<<c<<endl;
    }
    return 0;
}