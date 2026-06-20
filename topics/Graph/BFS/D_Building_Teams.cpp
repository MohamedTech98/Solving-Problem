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
vector<int> teams;
vector<bool> visited;
int n,m;
bool bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    teams[start] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto ch : nodes[cur]) {
            if(visited[ch]==0) {
                q.push(ch);
                visited[ch] = 1;
                teams[ch] = 3  - teams[cur];
            } else if(teams[ch]== teams[cur]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ana_Yano;
    cin>>n>>m;
    nodes.assign(n + 1,vector<int>());
    visited.assign(n + 1,0);
    teams.assign(n + 1,0);
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    bool flag = true;
    for(int i = 1;i<=n;i++) {
        if(visited[i]==0) {
            flag &= bfs(i);
        }
    }
    if(flag) {
        for(int i = 1;i<=n;i++) {
            cout<< teams[i] << " ";
        }
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}