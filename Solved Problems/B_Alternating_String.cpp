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
        string s; cin>>s;
        string ans = "";
        ans += s[0];
        for(int i = 1;i<s.size();i++) {
            ans += ((ans[i - 1] - 'a') ^ 1) + 'a';
        }
        // int l = -1,r = -1;
        int sub = 0;
        // bool sub = false;
        for(int i = 0;i<s.size();i++) {
            if(s[i] != ans[i]) {
                for(int j = i;j<s.size();j++) {
                    if(s[j] == ans[j]) {
                        break;
                    } else {
                        i++;
                    }
                }
                sub++;
            }
        }
        cout << (sub <= 1 ? "YES" : "NO") << endl;
    }
    return 0;
}