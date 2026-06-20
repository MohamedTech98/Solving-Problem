#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        int sub = 1;
        char c = s[0];
        for(int i = 1;i<n;i++) {
            if(s[i - 1]!=s[i]) {
                sub++;
                c = s[i];
            }
        }
        if(sub==n) {
            cout<<sub<<endl;
            continue;
        }
        else {
            if(s[0]==s[n-1]) {
                cout<<sub<<endl;
            }
            else {
                cout<<sub + 1<<endl;
            }
        }

    }
    return 0;
}