#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n,a; cin>>n>>a;
    map<int,pair<int,int>> info;
    vector<int> cities(n);
    for(int i = 0;i<n;i++) {
        cin>>cities[i];
    }
    int pos  = a - 1;
    for(int i = 0;i<n;i++) {
        info[abs(i - pos)].first+=1;
        info[abs(i - pos)].second+=cities[i];
    }
    int ans = 0;
    for(int i = 0;i<info.size();i++) {
        
        if(info[i].first==info[i].second) {
            ans+= info[i].second;
        }
    }
    cout<<ans;
    return 0;
}