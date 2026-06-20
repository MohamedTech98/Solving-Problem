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
vector<int> levels;
bool bfs(int start) {
    queue<int> q;
    levels[start] = 0;
    visited[start] = 1;
    q.push(start);
    while(! q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto ch : nodes[cur]) {
            if(visited[ch] == 0) {
                q.push(ch);
                visited[ch] = 1;
                levels[ch] = levels[cur] + 1;
            } else if(levels[ch] == levels[cur]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ana_Yano;
    int t; cin>>t;
    for(int i = 1;i<=t;i++) {
        int n,m;
        cin>>n>>m;
        nodes.assign(n + 1,vector<int>());
        visited.assign(n + 1,0);
        levels.assign(n + 1,0);
        for(int j = 0,u,v;j<m;j++) {
            cin>>u>>v;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
        bool f = true;
        for(int j = 1;j<=n;j++) {
            if(visited[j] == 0) {
                f &= bfs(j);
            }
        }
        cout<<"Scenario #"<<i<<":"<<endl;
        if(f) {
            cout<<"No suspicious bugs found!"<<endl;
        } else {
            cout<<"Suspicious bugs found!"<<endl;
        }
    }
    return 0;
}