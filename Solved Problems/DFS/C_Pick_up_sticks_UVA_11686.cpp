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
vector<int> indegree;
vector<int> ans;
int n,m; 
void bfs() {
    queue<int> q;
    for(int i = 1;i<=n;i++) {
        if(indegree[i] == 0) {
            // ans.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        for(auto ch : nodes[cur]) {
                indegree[ch]--;
            
            if(indegree[ch] == 0) {
                q.push(ch);
            }
        }
    }
    
}
int main() {
    ana_Yano;
    while (true)
    {
        cin>>n>>m;
        if(n==0 && m == 0) {
            break;
        }
        nodes.assign(n + 1,vector<int>());
        visited.assign(n + 1,0);
        levels.assign(n + 1,0);
        indegree.assign(n + 1,0);
        for(int i = 0,u,v;i<m;i++) {
            cin>>u>>v;
            nodes[u].push_back(v);
            indegree[v]++;
            // nodes[v].push_back(u);
        }
        bfs();
        if(ans.size() == n) {
            for(auto val : ans) {
                cout<< val << endl;
            }
        }
        else {
            cout<< "IMPOSSIBLE" << endl;
        }
        ans.clear();
    }
    
    return 0;
}