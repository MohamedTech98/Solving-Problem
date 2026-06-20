#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all nums.begin(),nums.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

string game(int n,string s,string t) {
    for(int i = 0;i<n;i++) {
        if(s[i] - '0' ==1) {
            break;
        }
        if(s[i]!=t[i]) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    ana_Yano;
    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        string s,t; cin>>s>>t;
        cout<<game(n,s,t)<<endl;
    }
    return 0;
}