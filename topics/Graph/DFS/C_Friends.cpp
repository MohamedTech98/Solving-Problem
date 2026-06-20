// #include<bits\stdc++.h>
#include<iostream>
#include<vector>
#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
int ans = 0;
void DFS(int node) {
    ans++;
    visited[node] = 1;
    // cout<<node<<" ";
    for(int i = 0;i<nodes[node].size();i++) {
        if(visited[nodes[node][i]]==0) {
            DFS(nodes[node][i]); 
            // the node is connect for the value parameter(node)
        }
    }
}


int main() {
    int t; cin>>t;
    while(t--) {
        int n,m; cin>>n>>m;
        nodes.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        for(int i = 1,u,v;i<=m;i++) {
            cin>>u>>v;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
        int _max = 0;
        for(int i = 1;i<=n;i++) {
            ans = 0;
            if(visited[i]==0) {
                // cout<<i<<" "<<ans<<" "<<_max<<endl;
                DFS(i);
                _max = max(_max,ans);
            }
        }
        cout<<_max<<endl;
    }
    return 0;
}