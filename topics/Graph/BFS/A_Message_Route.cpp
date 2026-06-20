#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<stack>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<vector<int>> nodes;
vector<int> levels;
vector<bool> visited;
vector<int> parent;
void bfs(int start) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto ch : nodes[cur]) {
            if(visited[ch] == 0) {
                q.push(ch);
                visited[ch] = 1;
                levels[ch] = levels[cur] + 1;
                parent[ch] = cur;
            }
        }
    }
}
int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    nodes.assign(n + 1,vector<int>());
    visited.assign(n + 1,0);
    levels.assign(n + 1,0);
    parent.assign(n + 1,-1);
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    bfs(1);
    if(levels[n] == 0) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0; 
    }
    cout<< levels[n] + 1 << endl;
    stack<int> s;
    int cur = n;
    while(cur != -1) {
        s.push(cur);
        cur = parent[cur];
    }
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}