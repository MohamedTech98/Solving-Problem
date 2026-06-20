#include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n,k; cin >> n >> k;
    vector<int> nums(n);
    for(int &val : nums) {
        cin >> val;
    }
    sort(nums.begin(), nums.end());

    long long cnt = 1;
    int mid = n / 2;

    for(int i = mid + 1; i < n; i++) {
        long long need =
            1LL * (nums[i] - nums[i - 1]) * cnt;

        if(need <= k) {
            k -= need;
            cnt++; // NO. elements are equal
        }
        else {
            cout << nums[i - 1] + k / cnt; 
            // this is means if operation to increase all values need to 
            // no. operations greater than the current k 
            // return median + no. operation can make on median to became 
            // max median within k operation
            return 0;
        }
    }

    cout << nums[n - 1] + k / cnt;
    return 0;
}
