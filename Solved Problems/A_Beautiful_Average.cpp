#include<iostream>
#include<vector>
#include<algorithm>
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
        set<int,greater<int>>nums;
        for(int i = 0;i<n;i++) {
            int val; cin>>val;
            nums.emplace(val);
        }
        cout<<*nums.begin()<<endl;
    }
    return 0;
}