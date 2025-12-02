#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
vector<int>nums;
vector<int>seq;
vector<int>sorted;
int n,k;

void solve(int sum = 0, int comp = 0) {
    if(seq.size()==n) {
        // Base case
        // int sum = 0;
        // for(int i = 0 ;i<n;i++) {
        //     sum+=seq[i];
        // }
        if(sum%k==0) {
            for(int i = 0 ;i<n;i++) {
                cout<<seq[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // for(int i = 0;i<n;i++) {
        for(int j = 0;j<sorted.size();j++) {
            if(sorted[j]<=nums[comp]) {
                // cout<<sorted[j]<<"******"<<nums[i]<<endl;
                seq.push_back(sorted[j]);
                solve(sum + sorted[j] , comp + 1);
                seq.pop_back(); // Backtracking
            }
        }
    // }
}

int main() {
    ana_Yano;
    cin>>n>>k;
    nums.resize(n);
    int max_val =-1;
    for(int i = 0;i<n;i++) {
        cin>>nums[i];
        max_val = max(max_val,nums[i]);
        // sorted[i] = nums[i];
    }
    sorted.resize(max_val);
    for(int i  = 1;i<=max_val;i++) {
        sorted[i-1] = i;
    }
    // sort(sorted.begin(),sorted.end());
    solve();
    return 0 ;
}