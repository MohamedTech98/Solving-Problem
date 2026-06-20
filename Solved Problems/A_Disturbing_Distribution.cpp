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
const int mod = 676767677;

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> nums(n);
        for(int &val : nums) {
            cin>>val;
        }
        ll ans = 0,multi = 1;
        for(int i = 0;i < n - 1;i++) {

            if(nums[i] > nums[i + 1]) {
                multi *= nums[i];
            } else {
                ans += (multi != 1?multi : 0) + nums[i];
                multi = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}