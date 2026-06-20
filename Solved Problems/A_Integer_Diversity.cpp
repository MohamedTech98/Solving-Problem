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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> vec(n);
        map<int,int> nums;
        for(int i = 0;i < n;i++) {
            // int val; cin >> val;
            // vec[i] = val;
            cin >> vec[i];
            nums[vec[i]] = 0;
        }
        int ans = 0;
        for(int val : vec) {
            if(nums[val] == 0) {
                nums[val]++;
            } else if(nums[val] > 0) {
                nums[val * -1]++;
            }
        }
        for(auto [key,val] : nums) {
            ans += min(nums[val],1);
        }
        cout << ans << endl;
    }
    return 0;
}