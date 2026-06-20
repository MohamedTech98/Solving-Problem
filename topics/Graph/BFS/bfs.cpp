#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<vector<int>> nodes;
vector<int> levels;
vector<bool> visited;
void bfs(int start) {
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto ch : nodes[cur]) {
            q.push(ch);
            levels[ch] = levels[cur] + 1;
        }
    }
}
int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    nodes.assign(n + 1,vector<int>());
    visited.assign(n + 1,0);
    levels.assign(n + 1,0);
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }

    return 0;
}