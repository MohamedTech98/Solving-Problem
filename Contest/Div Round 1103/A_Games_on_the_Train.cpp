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
        vector<int> height(n);
        for(int &val : height) {
            cin >> val;
        }
        int max_diff = -1;
        int max_h = -1;
        for(int i = 0;i < n;i++) {
            max_h = max(max_h,height[i]);
        }
        for(int i = 0;i < n;i++) {
            max_diff = max(max_diff,max_h - height[i]);
        }
        cout << max_diff + 1 << endl;
    }
    return 0;
}