#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all nums.begin(),nums.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n,l,r,x;cin>>n>>l>>r>>x;
    vector<int> problem(n);
    for(int i = 0;i<n;i++) {
        cin>>problem[i];
    }

    int easy = INT_MAX,hard = INT_MIN;
    int ans = 0;
    for(int mask = 1;mask<(1<<n);mask++) {
        ll sum = 0;
        int easy = INT_MAX,hard = INT_MIN;
        for(int i = 0;i<n;i++) {
            if((mask>>i & 1)==1) {
                sum +=problem[i];
                easy = min(problem[i],easy);
                hard = max(problem[i],hard);
            }
            
        }
        if(sum>=l&& sum<=r && hard - easy  >= x) {
            ans++;
        }

    }
    cout<<ans<<endl;
    return 0;
}