#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)

int main() {
    ana_Yano;

    int t; 
    cin >> t;

    while (t--) {

        int n; 
        cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        sort(nums.begin(), nums.end(), greater<int>());

        // int sum = nums[0];
        bool ok = true;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) {
                ok = false;
                break;
            }
            // sum += nums[i];
        }

        if (!ok) {
            cout << -1 << endl;
        }
        else {
            for (int x : nums)
                cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}