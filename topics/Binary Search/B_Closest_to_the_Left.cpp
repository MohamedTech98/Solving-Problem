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
    int n,q; cin >> n>> q;
    vector<int> nums(n);
    for(int &val : nums) {
        cin >> val;
    }
    while(q--) {
        int target; cin>> target;
        int l = 0,r = n - 1,ans = 0;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if(nums[mid] <= target) {
                ans = mid + 1; // one-indexed
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}