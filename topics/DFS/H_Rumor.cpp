#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
int min_val = 0;
vector<vector<int>> nodes;
vector<int> cost;
vector<bool> visited;

void DFS(int node) {
    visited[node] = 1;
    for(int i = 0;i<nodes[node].size();i++) {
        if(visited[nodes[node][i]]==0) {
            min_val = min(min_val,cost[nodes[node][i]]);
            DFS(nodes[node][i]);
        }
    }
}

int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    nodes.resize(n + 1);
    cost.resize(n + 1);
    visited.resize(n + 1,0);
    for(int i = 1;i<=n;i++) {
        cin>>cost[i];
    }
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++) {
        if(visited[i]==0) {
            min_val = cost[i];
            DFS(i);
            ans += min_val;
        }
    }
    cout<< ans << endl;
    return 0;
}