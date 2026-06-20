#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std; 
ll solve(vector<int>&nums,int size,ll i = 0,ll g1 = 0 , ll g2 = 0) {
    if(i==size) {
        return abs(g1-g2); // start computing when last edge in the tree
    }
    ll op1 = solve(nums,size,i+1,g1+nums[i],g2);
    ll op2 = solve(nums,size,i+1,g1,g2+nums[i]);
    return min(op1,op2);
}
int main(){ 
    ana_Yano;
    int n; cin>>n;
    vector<int>weights(n);
    for(int &val : weights) {
        cin>>val;
    }
    // sort(all);
    ll ans = solve(weights,n);
    cout<<ans;
    return 0 ;
}