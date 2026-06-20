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
        vector<int> nums(n);
        for(int i= 0;i<n;i++) {
            cin>>nums[i];
        }
        cout<<nums[0]<<endl;
    }
    return 0;
}