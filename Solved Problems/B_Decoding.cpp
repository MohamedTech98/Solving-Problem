#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n; cin>>n;
    string word ; cin>>word;
    vector<char> ans(n);
    int l = 0,r = n-1;
    for(int even = n - 1;even>=0;even-=2) {
        ans[r] = word[even];
        r--;
    }
    for(int odd = n - 2;odd>=0;odd-=2) {
        ans[l] = word[odd];
        l++;
    }
    for(char c : ans) {
        cout<<c;
    }
    return 0;
}