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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pref2(n + 1, 0);
        vector<int> suff13(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref2[i + 1] = pref2[i] + (s[i] == '2');
        }
        for(int i = n - 1; i >= 0; i--) {
            suff13[i] = suff13[i + 1] + (s[i] == '1' || s[i] == '3');
        }
        int best = 0;
        for(int i = 0; i <= n; i++) {
            best = max(best, pref2[i] + suff13[i]);
        }
        cout << n - best << endl;
    }
    return 0;
}