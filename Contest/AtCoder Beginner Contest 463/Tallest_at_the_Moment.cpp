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
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i < n;i++) {
        int h,l; cin >> h >> l;
        v[i].first = l;
        v[i].second = h;
    }
    sort(v.begin(),v.end());
    for(int i = n - 2;i >= 0;i--) {
        v[i].second = max(v[i].second,v[i + 1].second);
    }
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        t = t + 1;
        int l = 0,r = n - 1,ans = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(v[mid].first >= t) {
                ans = v[mid].second;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}