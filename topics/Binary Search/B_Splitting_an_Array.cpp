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
int n,seg;
vector<int> nums;

bool can(ll x) {
    int parts = 1;
    ll sum = 0;
    for(int val : nums) {
        if(sum + val <= x) {
            sum += val;
        } else {
            parts++;
            sum = val; // new segment
        }
    }
    return parts <= seg;
}

int main() {
    ana_Yano;
    cin >> n >> seg;
    nums.resize(n);
    ll max_val = 0,sum = 0;
    for(int &val : nums) {
        cin >> val;
        max_val = max(max_val,1ll * val);
        sum += val;
    }
    ll l = max_val,r = sum,ans = 0;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(can(mid)) {
            // cout << mid << endl;
            ans = mid;
            r = mid - 1; // minimize sum
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}