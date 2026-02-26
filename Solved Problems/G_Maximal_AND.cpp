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
        int n,k; cin>>n>>k;
        vector<int> nums(n);
        int ans = 0;
        for(int i = 0;i<n;i++) {
            cin>>nums[i];
        }
        for(int bit = 30;bit>=0;bit--) {
            int cost = 0;
            for(int i = 0;i<n;i++) {
                if(((nums[i]>>bit) & 1)==0) {
                    cost++;
                }
            }
            if(cost<=k) {
                k-=cost;
                ans += (1<<bit);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
