#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    string s,t; cin>>s>>t;
    int start = 0;
    int move = 0;
    bool full = false;
    for(int i = 0;i<s.size();i++) {
        for(int j = start;j<t.size();j++) {
            if(s[i]==t[j]) {
                start = j + 1;
                move ++;
                break;
            }
            if(j==t.size() - 1) {
                full = true;
            }
        }
        if(full) {
            break;
        }
    }
    cout<<move + 1;
    return 0;
}