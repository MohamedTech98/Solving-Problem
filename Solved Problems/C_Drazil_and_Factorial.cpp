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

map<int,vector<int>> factorial;

int main() {
    ana_Yano;
    int n; cin>>n;
    string s; cin>>s;
    factorial[1] = {1};
    factorial[2] = {2};
    factorial[3] = {3};
    factorial[4] = {3,2,2};
    factorial[5] = {5};
    factorial[6] = {3,5};
    factorial[7] = {7};
    factorial[8] = {2,2,2,7};
    factorial[9] = {3,3,2,7};
    vector<int> ans;
    for(char &digit: s) {
        if(digit == '1' || digit == '0') {
            continue;
        }
        for(int &val: factorial[digit - '0']) {
            ans.push_back(val);
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    for(int val : ans) {
        cout << val;
    }
    return 0;
}