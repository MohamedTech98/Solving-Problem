#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n; cin>>n;
    vector<int> heights(n + 1,0);
    for(int i = 1;i<n + 1;i++) {
        cin>>heights[i];
    }
    int ans = *max_element(heights.begin(),heights.end());
    cout<<ans;
    return 0;
}