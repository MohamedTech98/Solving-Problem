#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n,q; cin>>n>>q;
    vector<int> nums(n + 1);
    for(int i = 1;i<=n;i++) {
        cin>>nums[i];
        nums[i] = nums[i] ^ nums[i - 1];
    }
    while(q--) {
        int l,r; cin>>l>>r;
        cout<<(nums[r]  ^ nums[l - 1])<<endl;
    }
}