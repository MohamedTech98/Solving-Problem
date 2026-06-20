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
map<int,int> levels;
map<int,bool> visited;
void bfs(int start) {
    queue<int> q;
    visited[start] = 1;
    levels[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int val = q.front();
        q.pop();
        if(val > 1 && visited[val - 1] == 0) {
            q.push(val - 1);
            visited[val - 1] = 1;
            levels[val - 1] = levels[val] + 1;
        }
        if(val < 1e4 && visited[val * 2] == 0) {
            q.push(val * 2);
            visited[val * 2] = 1;
            levels[val * 2] = levels[val] + 1;
        }
    }
}
int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    // for(int i = 0,u,v;i<m;i++) {
    //     cin>>u>>v;
    //     nodes[u].push_back(v);
    //     nodes[v].push_back(u);
    // }
    bfs(n);
    cout<< levels[m] << endl;

    return 0;
}