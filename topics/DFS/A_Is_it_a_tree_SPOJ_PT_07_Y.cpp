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
vector<bool> visited;
vector<int> parent;

bool DFS(int node) {
    bool f = true;
    visited[node] = 1;
    for(auto ch: nodes[node]) {
        if(parent[node] == ch) {
            continue;
        }
        if(visited[ch] == 0) {
            parent[ch] = node;
            f &= DFS(ch);
        }
        else {
            // cout<< node <<" " << parent[ch] << endl;
            return false;
        }
    }
    return f;
}
int main() {
    ana_Yano;
    cin>>n>>m;
    nodes.resize(n + 1,vector<int>());
    visited.resize(n + 1,0);
    parent.resize(n + 1,0);
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    parent[1] = -1;
    bool ans = true;
    for(int i = 1;i <= n ;i++) {
        if(visited[i]==0) {
            ans &= DFS(i);
        }
    }
    if(ans) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO" << endl;
    }
    return 0;
}