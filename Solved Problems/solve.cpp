#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main(){
    ana_Yano;
    string s; cin>>s;
    int l ,r;
    l = 0; r = s.size() - 1;
    while (l<=r)
    {
        if(s[l]=='?'&&s[r]!='?') {
            s[l] = s[r];
        }
        else if(s[r]=='?'&&s[l]!='?') {
            s[r] = s[l];
        }
        else if(s[l]=='?'&&s[r]=='?') {
            s[l] = s[r] = 'a';
        }
        else if(s[l]!=s[r]) {
            cout<<-1;
            return 0;
        }
        l++;r--;
    }
    cout<<s;
    
    return 0;
}