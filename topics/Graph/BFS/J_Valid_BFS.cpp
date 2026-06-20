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
vector<int> ind;
void bfs(int start) {
    queue<int> q;
    visited[start] = 1;
    // levels[start] = 1;
    q.push(start);
    while(! q.empty()) {
        int cur = q.front();
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

bool com(int i,int j) {
    return ind[i] < ind[j];
}

int main() {
    ana_Yano;
    cin>>n;
    nodes.assign(n + 1,vector<int>());
    visited.assign(n + 1,0);
    // levels.assign(n + 1,0);
    order.assign(n,0);
    ind.assign(n + 1,0);
    for(int i = 0,u,v;i<n-1;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    for(int i = 0;i<n;i++) {
        cin>>order[i];
        ind[order[i]] = i;
    }
    for(auto &vec:nodes) {
        sort(vec.begin(),vec.end(),com);
    }
    bfs(1);
    for(int i = 0;i<n;i++) {
        if(ans[i] != order[i]) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}