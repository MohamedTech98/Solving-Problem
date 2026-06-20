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
int n,k; 
vector<int> nums;

bool can(ll x) {
    ll sum = 0;
    int parts = 1;

    for(int v : nums) {
        if(sum + v <= x) {
            sum += v;
        }
        else {
            parts++;
            sum = v;
        }
    }

    return parts <= k;
}

int main() {
    ana_Yano;
    cin >> n >> k;
    nums.resize(n);
    for(int &val : nums) {
        cin >> val;
    }
    ll max_val = 0,sum = 0;
    for(int val : nums) {
        max_val = max(1ll * max_val,1ll * val);
        sum += val;
    }
    ll l = max_val,r = sum,ans = 0;
    while(l <= r) {
        ll mid = l + (r-l) / 2;
        // ll divide = divideArray(mid,k);
        if(can(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}