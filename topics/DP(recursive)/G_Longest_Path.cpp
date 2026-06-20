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

int n,m;
vector<vector<int>> nodes;
const int N = 1e5 + 2;
int dp[N];
int dfs(int node) {
    if(~ dp[node]) {
        return dp[node];
    }
    // cout<<node<<" ";
    int ans = 0;
    for(int ch : nodes[node]) {
        int path = 0;
        // if(visited[ch] == 0) {
            path = dfs(ch) + 1;
            ans = max(ans,path);
        // }
    }
    return dp[node] = ans;
}

int main() {
    ana_Yano;
    cin>>n>>m;
    nodes.assign(n + 1,vector<int>());
    // visited.assign(n + 1,0);
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
    }
    memset(dp,-1,sizeof dp);
    int longest = 0;
    for(int i = 1;i<=n;i++) {
            longest = max(longest,dfs(i));
    }
    cout<<longest<<endl;
    return 0;
}