#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<vector<int>> nodes;
// vector<bool> visited;
vector<int> dist;
void DFS(int node,int p = -1,int d = 0) {
    dist[node] = d;
    for(auto child : nodes[node]) {
        if(child == p) {
            continue;
        }
        DFS(child,node,d + 1);
    }
} 
int main() {
    ana_Yano;
    int n; cin>>n;
    nodes.assign(n + 1,vector<int>());
    dist.assign(n + 1, 0);
    for(int i = 0,u,v;i<n-1;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    DFS(1);
    int big = -1,node =-1;
    for(int i = 1;i<=n;i++) {
        if(dist[i] > big) {
            big = dist[i];
            node = i;
        }
    }
    dist.assign(n + 1, 0);
    DFS(node);
    big = 0;
    for(int i = 1;i<=n;i++) {
        big = max(dist[i],big);
    }
    cout<< big << endl;
    return 0;
}