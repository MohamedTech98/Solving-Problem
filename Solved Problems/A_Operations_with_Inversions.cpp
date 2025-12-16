#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;


int main() {
    int t; cin>>t;
    while(t--) {
        int count = 0;
        int n; cin>>n;
        vector<int>nums(n);
        for(int i = 0;i<n;i++) {
            cin>>nums[i];
        }
        for(int l = 0;l<n-1;l++) {
            for(int r = l + 1;r<n;r++) {
                if(l!=r&&nums[l]!=n+1) {
                    if(nums[l] > nums[r]&&l<r) {
                        // cout<<nums[l]<<"********"<<nums[r]<<endl;
                        nums[r] = n + 1 ;
                        count++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}