#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    string s; cin>>s;
    string  ans = s;
    reverse(s.begin(),s.end());
    ans += s;
    cout<<ans<<endl;
    return 0;
}