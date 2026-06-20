#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<bits\stdc++.h>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
int n,m;
vector<int> original;
vector<int> ans;
vector<int> cnt;
void bfs(int start) {
    queue<array<int,4>> q; // {node,level,odd_flap,even_flip}
    q.push({start,1,0,0});
    visited[start] = 1;
    while(!q.empty()) { 
        auto [node,level,odd_flip,even_flip] = q.front();
        q.pop();
        int i = original[node],g = ans[node];
        if(level & 1) {
            if(odd_flip == 1) {
                i = 1 - i;
            }
            if(i != g) {
                odd_flip = !odd_flip;
                cnt.push_back(node);
            }
        } else {
            if(even_flip == 1) {
                i = 1 - i;
            }
            if(i != g) {
                even_flip = !even_flip;
                cnt.push_back(node);
            }
        }
        for(auto ch: nodes[node]) {
            if(visited[ch] == 0) {
                q.push({ch,level + 1,odd_flip,even_flip});
                visited[ch] = 1;
            }
        }
    }
}
int main() {
    ana_Yano;
    cin>>n;
    nodes.assign(n + 1,vector<int>());
    visited.assign(n + 1,0);
    original.assign(n + 1,0);
    ans.assign(n + 1,0);

    for(int i = 0,u,v;i<n-1;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    for(int i = 1;i<=n;i++) {
        cin>>original[i];
    }
    for(int i = 1;i<=n;i++) {
        cin>>ans[i];
    }
    bfs(1);
    cout<<cnt.size()<<endl;
    for(auto val : cnt) {
        cout<<val<<endl;
    }
    return 0;
}