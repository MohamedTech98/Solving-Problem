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
// vector<bool> visited;
vector<int> indegree;
int n;
int bfs() {
    queue<int> q;
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        if(indegree[i] == 0) {
            // cout<< i << endl;
            q.push(i);
            levels[i] = 1;
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        ans = max(ans,levels[cur]);
        q.pop();
        for(auto ch: nodes[cur]) {
            indegree[ch]--;
            if(indegree[ch] == 0) {
                q.push(ch);
                levels[ch] = levels[cur] + 1;
            }
        }
    }
    return ans;
}
int main() {
    ana_Yano;
    cin>>n;
    nodes.assign(n + 1,vector<int>());
    indegree.assign(n + 1,0);
    levels.assign(n + 1,0);
    for(int i =1,u;i<=n;i++) {
        cin>>u;
        if(u == -1) {
            continue;
        }
        nodes[u].push_back(i);
        indegree[i]++;
    }
    cout<< bfs() << endl;
    return 0;
}