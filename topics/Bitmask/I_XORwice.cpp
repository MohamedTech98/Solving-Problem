#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all nums.begin(),nums.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        int a,b; cin>>a>>b;
        int ans = 0;
        for(int bit = 31;bit>=0;bit--) {
            if(((a>>bit) & 1)==((b>>bit) & 1)&& ((a>>bit) & 1) == 1) {
                ans += (1<<bit);
            }
        }
        cout<<(a^ans) + (b^ans)<<endl;
    }
    return 0;
}