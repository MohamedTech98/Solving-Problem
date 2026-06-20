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

bool win(string s,int n,int k) {
    for(int i = 0;i < n - k;i++) {
        if(s[i] == '1') {
            s[i] = '0';
            if(i + k < n) {
                s[i + k] = ((s[i + k] - '0') ^ 1) + '0';
            }
        }
    }
    for(int i = 0;i < n;i++) {
        if(s[i] == '1') {
            return false;
        }
    }
    return true;
}
int main() {
    ana_Yano;
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        if(win(s,n,k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}