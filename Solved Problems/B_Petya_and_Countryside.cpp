#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    int n; cin>>n;
    vector<int>highs(n);
    for(int i = 0 ;i<n;i++) {
        cin>>highs[i];
    }
    int ans = 1;
    for(int pos = 0;pos<n;pos++) {
        int watered = 1;
        for(int l = pos;l>0;l--) {
            if(highs[l]>=highs[l - 1]) {
                watered++;
            }
            else {
                break;
            }
        }
        for(int r = pos;r<highs.size() - 1;r++) {
            if(highs[r]>=highs[r + 1]) {
                watered++;
            }
            else {
                break;
            }
        }
        ans = max(ans,watered);
    }
    cout<<ans;
    return 0;
}