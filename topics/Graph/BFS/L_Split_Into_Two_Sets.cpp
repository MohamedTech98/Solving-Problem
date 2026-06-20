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
// vector<bool> visited;
int n,m;
vector<int> color;
bool bfs(int start) {
    queue<int> q;
    // visited[start] = 1;
    color[start] = 1;
    q.push(start);
    while(! q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto ch : nodes[cur]) {
            if(color[ch] == 0) {
                q.push(ch);
                // visited[ch] = 1;
                color[ch] = 3 - color[cur];
            } else if(color[ch] == color[cur]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        cin>>n;
        nodes.assign(n + 1,vector<int>());
        // visited.assign(n + 1,0);
        color.assign(n + 1,0);
        for(int i = 0,u,v;i<n;i++) {
            cin>>u>>v;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
        bool f = true;
        for(int i = 1;i<=n;i++) {
            if(nodes[i].size() > 2) {
                f = false;
            }
        }
        for(int i = 1;i<=n;i++) {
            if(color[i] == 0) {
                f &= bfs(i);
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}