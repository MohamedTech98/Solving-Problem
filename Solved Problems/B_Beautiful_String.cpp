#include<bits\stdc++.h>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std; 

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int>nums(n);
        for(int &val : nums) {
            cin>>val;
        }
        int l = 0,r = n-1,lp=0,rp=0;bool pail = true;
        while(l<=r) {
            if(nums[l]!=nums[r]) {
                lp = l;
                rp =r;
                pail = false;
                break;
            }
            l++; r--;
        }
        int s = l;
        while(lp<=rp) {
            if(nums[lp]==nums[s]){ 
                s++;
            }
            else if(nums[s]<nums[lp]) {
                
            }
        }
    }
    return 0;
}