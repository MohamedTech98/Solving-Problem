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

bool win(vector<int> &nums,vector<int>& freq,int k) {
    for(int i = nums.size() - 2;i >= 0;i--) {
            if(nums[i + 1] - nums[i] > k) {
                if(!(freq[nums[i]] & 1) || i > 0 && nums[i] - nums[i - 1] <= k) {
                    return true;
                }
            }
        }
        return false;
}

int main() {
    ana_Yano;
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        vector<int> nums(n);
        vector<int> freq(n + 1);
        for(int &val : nums) {
            cin >> val;
            freq[val]++;
        }
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end()); // remove duplicate
        nums.push_back(1e9); // to check the last element
        if(win(nums,freq,k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}