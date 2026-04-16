#include<bits\stdc++.h>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
void DFS(int node) {
    visited[node] = 1;
    cout<<node<<" ";
    for(int i = 0;i<nodes[node].size();i++) {
        if(visited[nodes[node][i]]==0) {
            DFS(nodes[node][i]); 
            // the node is connect for the value parameter(node)
        }
    }
}


int main() {
    int n,m; cin>>n>>m;
    nodes.resize(n + 1);
    visited.resize(n + 1,0);
    for(int i = 1,u,v;i<=m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    DFS(1);
    return 0;
}