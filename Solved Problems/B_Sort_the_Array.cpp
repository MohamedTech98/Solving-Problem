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
    int n;cin>>n;
    vector<int> nums(n);
    for(int &val : nums) cin>>val;
    vector<int> ans = nums;
    sort(ans.begin(),ans.end());
    int l = -1,r = -1;
    for(int i = 0;i<n-1;i++) {
        if(nums[i] > nums[i + 1]) {
            if(l == -1) {
                l = i;
            }
            r = i + 1;
        }
    }
    if(l == -1) {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
    } else {
        int i = l,j = r;
        while(i <= j) {
            swap(nums[i],nums[j]);
            i++; j--;
        }
        // for(int val : nums) {
        //     cout<<val<<" ";
        // }
        cout<<endl;
        if(nums == ans) {
            cout<<"yes"<<endl;
            cout<<l + 1<<" "<<r + 1<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }
    return 0;
}