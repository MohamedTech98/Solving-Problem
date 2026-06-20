#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> nums(n + 1);
        for(int i = 1;i<n + 1;i++) {cin>>nums[i];}
        vector<vector<int>> grid(32 , vector<int>(n + 1));
        for(int bit = 0;bit<32;bit++) {
            for(int i = 1;i<=n;i++) {
                grid[bit][i] = grid[bit][i - 1] + ((nums[i]>>bit) & 1) ;
            }
        }

        int q; cin>>q;
        while(q--) {
            int start,k; cin>>start>>k;
            int l = start,r = n,ans = -1;
            while(l<=r) {
                int mid = l + ((r - l) / 2);
                int andvalue = 0;
                for(int bits = 0; bits < 32; bits++) {
                    if(grid[bits][mid] - grid[bits][start - 1] == mid - start + 1) {
                        andvalue += (1LL << bits);
                    }
                }

                if(andvalue >= k) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }

            }

            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}