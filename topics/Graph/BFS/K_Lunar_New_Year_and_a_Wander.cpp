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
vector<bool> visited;
int n,m;
// vector<int> levels;
vector<int> order;
vector<int> ans;
// vector<int> ind;
void bfs(int start) {
    priority_queue<int,vector<int>,greater<int>> q;
    visited[start] = 1;
    // levels[start] = 1;
    q.push(start);
    while(! q.empty()) {
        int cur = q.top();
        ans.push_back(cur);
        q.pop();
        for(auto ch : nodes[cur]) {
            if(visited[ch] == 0) {
                q.push(ch);
                visited[ch] = 1;
                // levels[ch] = levels[cur] + 1;
            }
        }
    }
}

int main() {
    ana_Yano;
    cin>>n>>m;
    nodes.assign(n + 1,vector<int>());
    visited.assign(n + 1,0);
    // ans.assign(n + 1,0);
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    bfs(1);
    for(int val : ans) {
        cout<<val << " ";
    }
    return 0;
}