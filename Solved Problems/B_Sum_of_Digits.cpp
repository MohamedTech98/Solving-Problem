#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    string nums; cin>>nums;
    int ans = 0;

    while(nums.size()>1) {
        int sum = 0;
        for(int i = 0 ;i<nums.size();i++) {
            sum += nums[i] - '0';
        }
        nums = to_string(sum);
        ans++;
    }
    cout<<ans;
    return 0;
}