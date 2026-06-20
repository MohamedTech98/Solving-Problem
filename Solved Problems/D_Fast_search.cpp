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
    vector<int> nums(n);
    for(int &val : nums) {
        cin >> val ;
    }
    int q; cin >> q;
    sort(nums.begin(),nums.end());
    while(q--) {
        int rl,rr; cin >> rl >> rr;
        int l = 0,r = n - 1;
        // upper bound
        int start = -1;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if(nums[mid] >= rl) {
                r = mid - 1;
                start = mid;
            } else {
                l = mid + 1;
            }
        }
        l = 0,r = n - 1;
        int end = -1;
        // lower bound
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if(nums[mid] <= rr) {
                l = mid + 1;
                end = mid;
            } else {
                r = mid - 1;
            }
        }
        if(start == -1 || end == -1) {
            cout << 0 << ' ';
            continue;
        }
        cout << end - (start - 1) << ' ';
    }
    return 0;
}