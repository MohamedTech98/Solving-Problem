// #include<bits\stdc++.h>
#include<iostream>
#include<vector>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

// vector<vector<int>> nodes;
// vector<bool> visited;
// void DFS(int node) {
//     visited[node] = 1;
//     cout<<node<<" ";
//     for(int i = 0;i<nodes[node].size();i++) {
//         if(visited[nodes[node][i]]==0) {
//             DFS(nodes[node][i]); 
//             // the node is connect for the value parameter(node)
//         }
//     }
// }


int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    vector<vector<int>> cities(n + 1);
    while(m--) {
        int u,v; cin>>u>>v;
        cities[u].push_back(v);
        cities[v].push_back(u);
    }
    for(int i = 1;i<=n;i++) {
        cout<<cities[i].size()<<endl;
    }
    return 0;
}