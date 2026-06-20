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
    set<int> nums;
    for(int i = 0;i < n;i++) {
        int val; cin>>val;
        nums.emplace(val);
    }
    int i = 1;
    for(auto val : nums) {
        if(i == 2) {
            cout << val << endl;
            return 0;
        }
        i++;
    }
    cout << "NO" << endl;
    return 0;
}