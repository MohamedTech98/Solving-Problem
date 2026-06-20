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
vector<int> ans;
vector<int> a;
int n,m;
void bfs(int mod) {
    vector<int> levels;
    vector<bool> visited;
    visited.assign(n + 1,0);
    levels.assign(n + 1,-1);
    queue<int> q;
    for(int i = 1;i<=n;i++) {
        if(a[i] % 2 == mod) {
            q.push(i);
            visited[i] = 1;
            levels[i] = 0;
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto ch : nodes[cur]) {
            if(visited[ch] == 0 && a[ch] % 2 != mod) {
                q.push(ch);
                visited[ch] = 1;
                levels[ch] = levels[cur] + 1;
                ans[ch] = levels[ch];
            }
        }
    }
}
int main() {
    ana_Yano;
    cin>>n;
    nodes.assign(n + 1,vector<int>());
    ans.resize(n + 1,-1);
    // levels.assign(n + 1,-1);
    a.assign(n + 1,0);
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        if(i - a[i] >=1) {
            // cout<<i <<" "<< a[i] << endl;
            // nodes[i ].push_back(i - a[i]);
            nodes[i - a[i]].push_back(i);
        }
        if(i + a[i] <= n) {
            // cout<<i <<" "<< a[i] << endl;
            // nodes[i].push_back(i + a[i]);
            nodes[i + a[i]].push_back(i);
        }
    }
    bfs(1);
    bfs(0);
    for(int i = 1;i<=n;i++) {
        cout<< ans[i] << " ";
    }
    return 0;
}