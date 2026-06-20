#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n; cin>>n;
    vector<int> nums(n + 1);
    for(int i = 1,ind;i<n + 1;i++) {
        cin>>ind;
        nums[ind] = i;
    }
    int Q; cin>>Q;
    ll v ,p;
    v = p = 0;
    while(Q--) {
        int qur; cin>>qur;
        v +=nums[qur];
        p +=n - nums[qur] + 1;
    }
    cout<<v<<" "<<p;

    return 0;
}