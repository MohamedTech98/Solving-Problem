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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        // vector<bool> appear(2e5 + 1);
        set<pair<int,int>,greater<pair<int,int>>> max_values;
        vector<int> nums(n);
        for(int i = 0;i<n;i++) {
            cin>>nums[i];
            // if(appear[nums[i]] == 0) {
                max_values.emplace(make_pair(nums[i],i));
            // }
            // appear[nums[i]] = 1;
        }
        int ans = 0;
        int min_ind = n + 1;
        for(auto p : max_values) {
            if(min_ind < p.second) {
                continue;
            }
            ans++;
            // cout<<p.second<<" ";
            if(p.second == 0) {
                break;
            }
            min_ind = p.second;
        }
        // cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}