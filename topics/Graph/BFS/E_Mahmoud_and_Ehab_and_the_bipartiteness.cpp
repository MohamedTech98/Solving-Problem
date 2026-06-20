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
vector<int> levels;
ll set1 = 0,set2 = 0;
void bfs(int start) {
    queue<int> q;
    visited[start] = 1;
    levels[start] = 1;
    set1++;
    q.push(start);
    while(! q.empty()) {
        int cur = q.front();
        bool is_child = false;
        q.pop();
        for(auto ch : nodes[cur]) {
            if(visited[ch] == 0) {
                is_child = true;
                q.push(ch);
                visited[ch] = 1;
                levels[ch] = levels[cur] + 1;
                if(levels[ch] % 2 == 0) {
                    set2++;
                } else {
                    set1++;
                }
            }
        }
    }
}

int main() {
    ana_Yano;
    cin>>n;
    nodes.assign(n + 1,vector<int>());
    visited.assign(n + 1,0);
    levels.assign(n + 1,0);
    for(int i = 0,u,v;i<n-1;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    bfs(1);
    if(set1 * set2 == n-1) {
        cout<<0<<endl;
    } else {
        cout<< (set1 * set2) - (n-1) << endl;
    }
    return 0;
}