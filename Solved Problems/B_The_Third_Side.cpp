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
        vector<int> nums(n);
        for(int &val : nums) {
            cin>>val;
        }
        ll sum = nums[0];
        for(int i = 1;i < n;i++) {
            sum = sum + nums[i] - 1;
        }
        cout << sum << endl;
    }
    return 0;
}