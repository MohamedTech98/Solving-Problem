#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>


#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
const int N = 101;
int n;
int dp[N][N];
vector<int> task;

int work(int i, int pre) {
    if(i == n) return 0;

    if(dp[i][pre] != -1) return dp[i][pre];

    int ans = work(i + 1, 0); // rest

    if(task[i] == 1 || task[i] == 3) {
        if(pre != 1)
            ans = max(ans, 1 + work(i + 1, 1));
    }

    if(task[i] == 2 || task[i] == 3) {
        if(pre != 2)
            ans = max(ans, 1 + work(i + 1, 2));
    }

    return dp[i][pre] = ans;
}

int main() {
    ana_Yano;
    cin>>n;
    task.resize(n);
    for(int &val : task) {
        cin>>val;
    }
    memset(dp,-1,sizeof dp);
    cout<<n - work(0,10)<<endl;
    return 0;
}