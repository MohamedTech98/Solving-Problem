#include<bits\stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std; 

int n,m;
ll max_path = 0;
void path(int i,int j,ll sum,vector<vector<int>> &nums) {
    if(i==n-1&&j==m-1) {
        max_path =max(max_path,sum);
        return;
    }
    if(i + 1<n) {
        path(i + 1,j,sum + nums[i+1][j],nums);
    }
    if(j+1<m) {
        path(i,j + 1,sum + nums[i][j+1],nums);
    }
}

int main() {
    ana_Yano;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(m));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin>>nums[i][j];
        }
    }
    path(0,0,nums[0][0],nums);
    cout<<max_path<<endl;
    return 0 ;
}